/*
你有 n 个机器人，给你两个下标从 0 开始的整数数组 chargeTimes 和 runningCosts ，两者长度都为 n 。第 i 个机器人充电时间为 chargeTimes[i] 单位时间，花费 runningCosts[i] 单位时间运行。再给你一个整数 budget 。

运行 k 个机器人 总开销 是 max(chargeTimes) + k * sum(runningCosts) ，其中 max(chargeTimes) 是这 k 个机器人中最大充电时间，sum(runningCosts) 是这 k 个机器人的运行时间之和。

请你返回在 不超过 budget 的前提下，你 最多 可以 连续 运行的机器人数目为多少。
 */

 // 二分答案  ST表记录最大值
class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n=chargeTimes.size();
        vector<long long>prefix(n+1,0);//前缀和
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+runningCosts[i];
        }
        //需要统计一个区间内的最大值
        //用什么统计可以O(1)获取?

        // 构建ST表
        vector<int>lg (n+1);// 预处理：以2为底的对数，向下取整
        for (int i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
        // f[i][j] 表示 [i - 2^j + 1, i] 区间的最大值
        vector<vector<int>>f(n,vector<int>(lg[n]+1));
        for (int i = 0; i < n; ++i) {
            f[i][0] = chargeTimes[i];
            for (int j = 1; j <= lg[i + 1]; ++j) {
                f[i][j] = max(f[i][j - 1], f[i - (1 << j - 1)][j - 1]);
            }
        }
        
        function<bool(int)>check=[&](int k){
            int i=0;
            int j=k-1;
            while(j<n){
                int maxval = max(f[j][lg[k]], f[i + (1 << lg[k]) - 1][lg[k]]);
                if((long long)k*(prefix[j+1]-prefix[i])+(long long)maxval<=budget){
                    return true;
                }
                i++;
                j++;
            }
            return false;
        };
        
        int left=1;
        int right=n;
        while(left<=right){
            int mid=(left-right)/2+right;
            if(check(mid)){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return left-1;
    }
};