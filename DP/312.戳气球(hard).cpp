/*
有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。

现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。 这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号。如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。

求所能获得硬币的最大数量。

Solution: 动态规划   在nums前后添加“1”,作为虚拟的气球节点，便于硬币数量计算
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int>new_nums(nums.size()+2,1);
        for(int i=0;i<nums.size();i++){
            new_nums[i+1]=nums[i];
        }
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        //dp[i][j]定义为打区间[i,j]的气球后获得的硬币最大数量 ，结果为dp[0][n+1]
        //状态转移  dp[i][j]= max(dp[i][j],dp[i][k]+dp[k][j]+new_nums[i] * new_nums[k] * new_nums[j])
        for (int len = 1; len <= n + 2; len ++) { //枚举区间长度
            for (int i = 0; i + len - 1 <= n + 1; i ++) {  //枚举开始端点     
            //注意遍历顺序   这样遍历，在dp表中是按对角线斜着填充的
                int j = i + len - 1; //由长度和开始端点算出结束端点     
                for (int k = i + 1; k < j ; k ++) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + new_nums[i] * new_nums[k] * new_nums[j]);
                }
            }
        }
        return dp[0][nums.size()+1];
    }
};