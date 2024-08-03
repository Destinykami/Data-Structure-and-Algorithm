/*
在二维平面上的 x 轴上，放置着一些方块。

给你一个二维整数数组 positions ，其中 positions[i] = [lefti, sideLengthi] 表示：第 i 个方块边长为 sideLengthi ，其左侧边与 x 轴上坐标点 lefti 对齐。

每个方块都从一个比目前所有的落地方块更高的高度掉落而下。方块沿 y 轴负方向下落，直到着陆到 另一个正方形的顶边 或者是 x 轴上 。一个方块仅仅是擦过另一个方块的左侧边或右侧边不算着陆。一旦着陆，它就会固定在原地，无法移动。

在每个方块掉落后，你必须记录目前所有已经落稳的 方块堆叠的最高高度 。

返回一个整数数组 ans ，其中 ans[i] 表示在第 i 块方块掉落后堆叠的最高高度。

My Solution: 记录每个区间的高度和长度。使用哈希表和堆。比较复杂

更好做法：线段树
*/
// class Solution {
// public:
//     vector<int> fallingSquares(vector<vector<int>>& positions) {
//         unordered_map<int, pair<int, int>> ump; // 开始下标,对应[长度，高度]
//         unordered_set<int> ust; // 记录所有的开始下标
//         vector<int> ans(positions.size(), 0);
//         int cur_max = 0;

//         for (int i = 0; i < positions.size(); i++) {
//             int start = positions[i][0];
//             int side_length = positions[i][1];
//             int end = start + side_length;

//             int max_height = 0;

//             for (auto &&ss : ust) {
//                 auto [tmp_len, tmp_height] = ump[ss];
//                 if (ss + tmp_len <= start || end <= ss) {
//                     // 未覆盖
//                     continue;
//                 } else {
//                     // 覆盖，找出重叠部分的最大高度
//                     max_height = max(max_height, tmp_height);
//                 }
//             }

//             // 当前方块的高度是其接触点的最大高度加上自身高度
//             int current_height = max_height + side_length;

//             // 更新 ump 和 ust
//             vector<int> to_erase;
//             vector<pair<int, pair<int, int>>> to_add;

//             for (auto &&ss : ust) {
//                 auto [tmp_len, tmp_height] = ump[ss];
//                 if (ss + tmp_len <= start || end <= ss) {
//                     // 未覆盖
//                     continue;
//                 } else {
//                     // 覆盖，需调整已有方块的信息
//                     if (ss < start) {
//                         to_add.push_back({ss, {start - ss, tmp_height}});
//                     }
//                     if (end < ss + tmp_len) {
//                         to_add.push_back({end, {ss + tmp_len - end, tmp_height}});
//                     }
//                     to_erase.push_back(ss);
//                 }
//             }

//             for (int e : to_erase) {
//                 ust.erase(e);
//                 ump.erase(e);
//             }

//             for (auto &[s, h] : to_add) {
//                 ust.insert(s);
//                 ump[s] = h;
//             }

//             ust.insert(start);
//             ump[start] = {side_length, current_height};

//             // 更新最高高度
//             cur_max = max(cur_max, current_height);
//             ans[i] = cur_max;
//         }

//         return ans;
//     }
// };

//线段树：
class Node {
public:
    Node* left;
    Node* right;
    int l;
    int r;
    int mid;
    int v;
    int add;

    Node(int l, int r) {
        this->l = l;
        this->r = r;
        this->mid = (l + r) >> 1;
        this->left = this->right = nullptr;
        v = add = 0;
    }
};

class SegmentTree {
private:
    Node* root;

public:
    SegmentTree() {
        root = new Node(1, 1e9);
    }

    void modify(int l, int r, int v) {
        modify(l, r, v, root);
    }

    void modify(int l, int r, int v, Node* node) {
        if (l > r) return;
        if (node->l >= l && node->r <= r) {
            node->v = v;
            node->add = v;
            return;
        }
        pushdown(node);
        if (l <= node->mid) modify(l, r, v, node->left);
        if (r > node->mid) modify(l, r, v, node->right);
        pushup(node);
    }

    int query(int l, int r) {
        return query(l, r, root);
    }

    int query(int l, int r, Node* node) {
        if (l > r) return 0;
        if (node->l >= l && node->r <= r) return node->v;
        pushdown(node);
        int v = 0;
        if (l <= node->mid) v = max(v, query(l, r, node->left));
        if (r > node->mid) v = max(v, query(l, r, node->right));
        return v;
    }

    void pushup(Node* node) {
        node->v = max(node->left->v, node->right->v);
    }

    void pushdown(Node* node) {
        if (!node->left) node->left = new Node(node->l, node->mid);
        if (!node->right) node->right = new Node(node->mid + 1, node->r);
        if (node->add) {
            Node* left = node->left;
            Node* right = node->right;
            left->v = node->add;
            right->v = node->add;
            left->add = node->add;
            right->add = node->add;
            node->add = 0;
        }
    }
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> ans;
        SegmentTree* tree = new SegmentTree();
        int mx = 0;
        for (auto& p : positions) {
            int l = p[0], w = p[1], r = l + w - 1;
            int h = tree->query(l, r) + w;
            mx = max(mx, h);
            ans.push_back(mx);
            tree->modify(l, r, h);
        }
        return ans;
    }
};

// 作者：ylb
// 链接：https://leetcode.cn/problems/falling-squares/solutions/2859880/python3javacgotypescript-yi-ti-yi-jie-xi-ju2s/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。