/*  
Midium
给你一棵无根带权树，树中总共有 n 个节点，分别表示 n 个服务器，服务器从 0 到 `n - 1` 编号。
同时给你一个数组 edges ，其中 `edges[i] = [ai, bi, weighti]` 表示节点 ai 和 bi 之间有一条双向边，
边的权值为 `weighti` 。再给你一个整数 `signalSpeed` 。

如果两个服务器 a ，b 和 c 满足以下条件，那么我们称服务器 a 和 b 是通过服务器 c 可连接的 ：

a < b ，a != c 且 b != c 。
从 c 到 a 的距离是可以被 signalSpeed 整除的。
从 c 到 b 的距离是可以被 signalSpeed 整除的。
从 c 到 b 的路径与从 c 到 a 的路径没有任何公共边。

请你返回一个长度为 n 的整数数组 count ，其中 count[i] 表示通过服务器 i 可连接 的服务器对的 数目 。

Solution:  dfs遍历节点，统计节点数，乘法原理计数
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n=edges.size()+1;
        vector<vector<pair<int,int>>>g(n);
        for(auto&&i:edges){
            g[i[0]].push_back({i[1],i[2]});
            g[i[1]].push_back({i[0],i[2]});
        }
        function<int(int,int,int)>dfs=[&](int cur,int fa,int dist)->int{
            int tmp=0;
            if(dist%signalSpeed==0)
                tmp=1;
            //经过cur点 且 距离能被signalSpeed整除的节点数
            for(auto&&i:g[cur]){
                if(i.first!=fa){
                    tmp+=dfs(i.first,cur,dist+i.second);
                }
            }
            return tmp;
        };
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            if(g[i].size()==1){ //只有一条边,则到达某两个节点的路径一定有公共边，则不必判断
                continue;
            }
            int cnt=0;
            int sum=0;
            for(auto&&next:g[i]){
                int tmp=dfs(next.first,i,next.second);
                sum+=tmp*cnt;  //乘法原理，新的满足距离条件的节点可以和之前任意一个满足距离条件的节点构成一个满足条件的服务器对
                cnt+=tmp;
            }
            ans[i]=sum;
        }
        return ans;
    }
};