/*
给你一个下标从 0 开始的 8 x 8 网格 board ，其中 board[r][c] 表示游戏棋盘上的格子 (r, c) 。棋盘上空格用 '.' 表示，白色格子用 'W' 表示，黑色格子用 'B' 表示。

游戏中每次操作步骤为：选择一个空格子，将它变成你正在执行的颜色（要么白色，要么黑色）。但是，合法 操作必须满足：涂色后这个格子是 好线段的一个端点 （好线段可以是水平的，竖直的或者是对角线）。

好线段 指的是一个包含 三个或者更多格子（包含端点格子）的线段，线段两个端点格子为 同一种颜色 ，且中间剩余格子的颜色都为 另一种颜色 （线段上不能有任何空格子）

Solution: 实际上就是往八个方向搜索，判断找到和起点相同颜色的端点时，中间是否有不同的颜色

*/
class Solution {
public:
    const int dx[8]={0,0,1,-1,-1,-1,1,1};
    const int dy[8]={1,-1,0,0,1,-1,1,-1};
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        for(int i=0;i<8;i++)
        {
            int nextx=rMove+dx[i];
            int nexty=cMove+dy[i];
            int flag=0;//到相同颜色的端点时，中间是否有不同的颜色
            while(nextx>=0&&nextx<board.size()&&nexty>=0&&nexty<board[0].size()){
                if(board[nextx][nexty]=='.') break;
                if(board[nextx][nexty]==color){
                    if(flag==1)
                    return true;
                    else break;
                }
                else if(board[nextx][nexty]!=color){
                    flag=1;
                }
                nextx+=dx[i];
                nexty+=dy[i];
            }
        }
        return false;
    };
};