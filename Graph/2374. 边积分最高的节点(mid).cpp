/*
给你一个有向图，图中有 n 个节点，节点编号从 0 到 n - 1 ，其中每个节点都 恰有一条 出边。

图由一个下标从 0 开始、长度为 n 的整数数组 edges 表示，其中 edges[i] 表示存在一条从节点 i 到节点 edges[i] 的 有向 边。

节点 i 的 边积分 定义为：所有存在一条指向节点 i 的边的节点的 编号 总和。

返回 边积分 最高的节点。如果多个节点的 边积分 相同，返回编号 最小 的那个。


Solution: 纯读题  注意int溢出
*/
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int ans=0;
        long long tmp=0;
        vector<long long>val(edges.size(),0);
        for(int i=0;i<edges.size();i++){
            val[edges[i]]+=i;
            if(val[edges[i]]>tmp){
                ans=edges[i];
                tmp=val[edges[i]];
            }
            else if(val[edges[i]]==tmp){
                ans=min(ans,edges[i]);
            }
        }
        return ans;
    }
};