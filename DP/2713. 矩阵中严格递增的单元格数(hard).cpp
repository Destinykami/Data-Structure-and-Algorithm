/*
给你一个下标从 1 开始、大小为 m x n 的整数矩阵 mat，你可以选择任一单元格作为 起始单元格 。

从起始单元格出发，你可以移动到 同一行或同一列 中的任何其他单元格，但前提是目标单元格的值 严格大于 当前单元格的值。

你可以多次重复这一过程，从一个单元格移动到另一个单元格，直到无法再进行任何移动。

请你找出从某个单元开始访问矩阵所能访问的 单元格的最大数量 。

返回一个表示可访问单元格最大数量的整数。

Solution : 暴力记忆化搜索，最后TLE了- - 
           实际上是在矩阵中找到一条最长的严格递增的路径

           cpp中的map基于红黑树，实现了一个有序的结构

           定义 f[i][j] 表示到达 mat[i][j] 时，访问过的单元格的最大数量（包含 mat[i][j]）。
           那么答案就是所有 f[i][j]的最大值。
           我们不需要知道具体从哪个单元格转移过来，只需要知道所有转移来源的最大值是多少。
*/
class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int, vector<pair<int, int>>> g;  
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                g[mat[i][j]].emplace_back(i, j); // 相同元素放在同一组，统计位置
            }
        }

        vector<int> row_max(m), col_max(n);
        for (auto& [_, pos] : g) {   //map是从小到大排列的，因此是从小到大遍历
            vector<int> mx; // 先把最大值算出来，再更新 row_max 和 col_max
            for (auto& [i, j] : pos) {
                mx.push_back(max(row_max[i], col_max[j]) + 1);
            }
            for (int k = 0; k < pos.size(); k++) {
                auto& [i, j] = pos[k];
                row_max[i] = max(row_max[i], mx[k]); // 更新第 i 行的最大 f 值
                col_max[j] = max(col_max[j], mx[k]); // 更新第 j 列的最大 f 值
            }
        }
        return ranges::max(row_max);
    }
};

/*
另外有个方法是建图，感觉是非常值得学习的一个方法

将单元格之间的访问关系描述为一个有向无环图，题目要求的就是有向无环图的最长路，直接动态规划即可，
唯一要注意的就是暴力建图，图中边的数量会达到 O(mn(m+n)) 量级，因此需要建图优化，有两个点需要优化
1. 同一行（列）里，只需要在大小相邻的节点间连边。假设有三个节点 u<v<w，那么只需要连接边 (u,v) 和 (v,w)，边 (u,w) 可以用上面两条边组合起来代替

2. 因为有同值节点，只有上面的优化还不够，假设同一行（列）里，值为 x 的节点构成集合 S，值为 y 的节点构成集合 T，且 x<y，
那么需要从集合 S 向集合 T 连边，暴力连边会使边数达到 ∣S∣∣T∣，更好的方法是建立虚拟节点 dummyd，
从集合 S向虚拟节点 dummy 连边，从虚拟节点 dummy 向集合 T 连边，这样边的数量减少到了 ∣S∣+∣T∣。
*/

class Solution {
public:
    struct Item {
        int val, idx;
        bool operator<(Item other) const {
            return val < other.val;
        }
    };
    
    int maxIncreasingCells(const vector<vector<int>>& mat) {
        const int m = mat.size(), n = mat[0].size();
        vector<vector<int>> graph(m * n);
        for (int i = 0;i < m;++i) {
            vector<Item> ord;
            for (int j = 0;j < n;++j)
                ord.push_back({mat[i][j], j});
            sort(ord.begin(), ord.end());
            // 前一个值对应的区间为 [p, j)，当前值对应的区间为 [j, q)
            for (int j = 0, p = -1, q = 1;j < n;p = j, j = q++) {
                while (q < n && ord[q].val == ord[j].val)
                    ++q;
                if (p != -1) {
                    const int t = graph.size();
                    graph.emplace_back();
                    for (int k = p;k < j;++k)
                        graph[n * i + ord[k].idx].push_back(t);
                    for (int k = j;k < q;++k)
                        graph[t].push_back(n * i + ord[k].idx);
                }
            }
        }
        for (int i = 0;i < n;++i) {
            vector<Item> ord;
            for (int j = 0;j < m;++j)
                ord.push_back({mat[j][i], j});
            sort(ord.begin(), ord.end());
            // 前一个值对应的区间为 [p, j)，当前值对应的区间为 [j, q)
            for (int j = 0, p = -1, q = 1;j < m;p = j, j = q++) {
                while (q < m && ord[q].val == ord[j].val)
                    ++q;
                if (p != -1) {
                    const int t = graph.size();
                    graph.emplace_back();
                    for (int k = p;k < j;++k)
                        graph[n * ord[k].idx + i].push_back(t);
                    for (int k = j;k < q;++k)
                        graph[t].push_back(n * ord[k].idx + i);
                }
            }
        }
        // 拓扑排序动态规划
        const int l = graph.size();
        vector<int> deg(l, 0);
        for (const auto& s : graph)
            for (int e : s)
                ++deg[e];
        queue<int> q;
        for (int i = 0;i < l;++i)
            if (deg[i] == 0)
                q.push(i);
        int ans = 0;
        vector<int> dp(l, 0);
        for (;!q.empty();q.pop()) {
            const int u = q.front();
            dp[u] += u < m * n;
            ans = max(ans, dp[u]);
            for (int v : graph[u]) {
                dp[v] = max(dp[v], dp[u]);
                if (--deg[v] == 0)
                    q.push(v);
            }
        }
        return ans;
    }
};
