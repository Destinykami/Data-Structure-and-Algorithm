/*
给你一个二维整数数组 point ，其中 points[i] = [xi, yi] 表示二维平面内的一个点。同时给你一个整数 w 。你需要用矩形 覆盖所有 点。

每个矩形的左下角在某个点 (x1, 0) 处，且右上角在某个点 (x2, y2) 处，其中 x1 <= x2 且 y2 >= 0 ，同时对于每个矩形都 必须 满足 x2 - x1 <= w 。

如果一个点在矩形内或者在边上，我们说这个点被矩形覆盖了。

请你在确保每个点都 至少 被一个矩形覆盖的前提下，最少 需要多少个矩形。

注意：一个点可以被多个矩形覆盖。

Solution:注意y没有用
*/
class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        //y坐标其实没有用
        set<int>x_ranges;
        for(auto&point:points){
            x_ranges.insert(point[0]);
        }
        int ans=0;
        int pre=-1;
        for(auto&next:x_ranges){
            if(pre==-1){
                ans+=1;
                pre=next;
            }
            else{
                if(next-pre<=w){
                    continue;
                }
                else{
                    ans+=1;
                    pre=next;
                }
            }
        }
        return ans;
    }
};