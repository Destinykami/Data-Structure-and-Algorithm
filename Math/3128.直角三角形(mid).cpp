/*
给你一个二维 boolean 矩阵 grid 。
请你返回使用 grid 中的 3 个元素可以构建的 直角三角形 数目，且满足 3 个元素值 都 为 1 。

注意：

如果 grid 中 3 个元素满足：一个元素与另一个元素在 同一行，同时与第三个元素在 同一列 ，那么这 3 个元素称为一个 直角三角形 。
这 3 个元素互相之间不需要相邻。

Solution: 统计每一行，每一列1的数目，乘法原理计算
*/
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        //统计每一行、列的1的数目
        vector<int>row(grid.size());
        vector<int>col(grid[0].size());
        for(int i=0;i<grid.size();i++){
            int cnt=0;
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    cnt+=1;
                }
            }
            row[i]=cnt;
        }
        for(int i=0;i<grid[0].size();i++){
            int cnt=0;
            for(int j=0;j<grid.size();j++){
                if(grid[j][i]==1){
                    cnt+=1;
                }
            }
            col[i]=cnt;
        }
        long long ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    ans+=(long long)(row[i]-1)*(col[j]-1);
                }
            }
        }
        return ans;
    }
};