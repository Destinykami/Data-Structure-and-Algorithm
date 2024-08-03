/*
给你一个炸弹列表。一个炸弹的 爆炸范围 定义为以炸弹为圆心的一个圆。

炸弹用一个下标从 0 开始的二维整数数组 bombs 表示，其中 bombs[i] = [xi, yi, ri] 。xi 和 yi 表示第 i 个炸弹的 X 和 Y 坐标，ri 表示爆炸范围的 半径 。

你需要选择引爆 一个 炸弹。当这个炸弹被引爆时，所有 在它爆炸范围内的炸弹都会被引爆，这些炸弹会进一步将它们爆炸范围内的其他炸弹引爆。

给你数组 bombs ，请你返回在引爆 一个 炸弹的前提下，最多 能引爆的炸弹数目。

Solution: 建图，在引爆范围内视为连通，注意引爆范围是有向的，然后dfs搜索
*/
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>>g(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((long long)(bombs[i][0]-bombs[j][0])*(long long)(bombs[i][0]-bombs[j][0])+(long long)(bombs[i][1]-bombs[j][1])*(long long)(bombs[i][1]-bombs[j][1])<=(long long)bombs[i][2]*(long long)bombs[i][2]){
                    g[i].push_back(j);
                }
            }
        }
        int ans=0;
        function<int(int,vector<int>&)>dfs=[&](int cur,vector<int>&visit){
            int res=1;
            for(auto&&next:g[cur]){
                if(visit[next]==0){
                    visit[next]=1;
                    res+=dfs(next,visit);
                }
            }
            return res;
        };
        for(int i=0;i<n;i++){
            vector<int>visit(n,0);
            visit[i]=1;
            ans=max(ans,dfs(i,visit));
        }
        return ans;
    }
};