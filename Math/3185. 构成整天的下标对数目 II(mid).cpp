/*
给你一个整数数组 hours，表示以 小时 为单位的时间，返回一个整数，表示满足 i < j 且 hours[i] + hours[j] 构成 整天 的下标对 i, j 的数目。

整天 定义为时间持续时间是 24 小时的 整数倍 。

例如，1 天是 24 小时，2 天是 48 小时，3 天是 72 小时，以此类推。

Solution: 两数之和换皮版，用哈希表统计余数
*/
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long hash_map[25]={0};
        long long ans=0;
        for(auto&&i:hours){
            ans+=hash_map[(24-i%24)%24];
            hash_map[i%24]+=1;
        }
        return ans;
    }
};