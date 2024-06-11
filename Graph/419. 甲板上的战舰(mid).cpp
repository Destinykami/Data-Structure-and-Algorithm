/*
给你一个大小为 m x n 的矩阵 board 表示甲板，其中，每个单元格可以是一艘战舰 'X' 或者是一个空位 '.' ，
返回在甲板 board 上放置的 战舰 的数量。
战舰 只能水平或者垂直放置在 board 上。换句话说，战舰只能按 1 x k（1 行，k 列）或 k x 1（k 行，1 列）的形状建造，
其中 k 可以是任意大小。
两艘战舰之间至少有一个水平或垂直的空位分隔 （即没有相邻的战舰）。

Solution: 说人话： 连在一起的X为一个船，统计图内的船的数量 （因为题目保证两艘战舰之间至少有一个水平或垂直的空位分隔）
          简单的思路：找到X为起点，往下一个X的方向搜索，搜索过的节点标记为其他数，这样不会再次搜索重复计数

          优化：只统计每个船的左上角
*/
#include<bits/stdc++.h>
using namespace std;
//不加优化
class Solution1{
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans=0;
        queue<pair<int,int>>q;
        function<void(void)>bfs=[&](){
            //向下或者向右搜索，因为遍历是从上到下，从左到右的
            while(!q.empty()){
                auto [x,y]=q.front();
                q.pop();
                if(x+1<board.size()&&board[x+1][y]=='X'){
                    q.push({x+1,y});
                    board[x+1][y]='c';
                }
                else{
                    if(y+1<board[0].size()&&board[x][y+1]=='X'){
                        q.push({x,y+1});
                        board[x][y+1]='c';

                    }
                }
            }
            ans+=1;
        };
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='X'){
                    q.push({i,j});
                    board[i][j]='c';
                    bfs();
                }
            }
        }
        
        return ans;
    }
};

//优化
const auto _ = []() noexcept {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution2 {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='X'&&(i==0||board[i-1][j]=='.')&&(j==0||board[i][j-1]=='.')){
                    ans+=1;
                }
            }
        }
        
        return ans;
    }
};