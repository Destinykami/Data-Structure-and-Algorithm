/*
给你一个二维数组 points 和一个字符串 s ，其中 points[i] 表示第 i 个点的坐标，s[i] 表示第 i 个点的 标签 。

如果一个正方形的中心在 (0, 0) ，所有边都平行于坐标轴，且正方形内 不 存在标签相同的两个点，那么我们称这个正方形是 合法 的。

请你返回 合法 正方形中可以包含的 最多 点数。

注意：

如果一个点位于正方形的边上或者在边以内，则认为该点位于正方形内。
正方形的边长可以为零。

Solution: 维护每个标记出现的第二大坐标,在所有标记的第二大坐标内取最小值。
*/
class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        //维护每个标记出现的第二大坐标
        vector<pair<int,int>>alphabet(26,{INT_MAX,INT_MAX});
        int radius=INT_MAX;
        for(int i=0;i<points.size();i++){
            int x=abs(points[i][0]);
            int y=abs(points[i][1]);
            int t=max(x,y);//要使该点在正方形内，则要取大的
            int tag=s[i]-'a';
            if(t<alphabet[tag].first){
                alphabet[tag]={t,alphabet[tag].first};
            }
            else{
                alphabet[tag].second=min(t,alphabet[tag].second);
            }
            radius=min(radius,alphabet[tag].second);
        }
        if(radius==INT_MAX){
            return points.size();
        }
        int ans=0;
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            if(abs(x)<radius&&abs(y)<radius){
                ans+=1;
            }
        }
        return ans;
    }
};