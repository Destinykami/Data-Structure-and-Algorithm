/*
给你一个整数数组 nums。

返回两个（不一定不同的）质数在 nums 中 下标 的 最大距离。

Solution: 关键是判断质数的操作
        可以预处理所有质数并存入set中，然后从nums开头和结尾分别找到第一个质数即可。
*/
//预处理所有质数

const int MX = 999999;
vector<int> primes; 
unordered_set<int> prime_set;
int init = []() {
    bool np[MX]{};
    for (int i = 2; i < MX; ++i)
        if (!np[i]) {
            primes.push_back(i); // 预处理质数列表
            for (int j = i; j < MX / i; ++j)
                np[i * j] = true;
        }
    for(auto i:primes){
        prime_set.insert(i);
    }
    return 0;
}();
class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int first=-1;
        int last=-1;
        for(int i=0;i<nums.size();i++){
            if(prime_set.count(nums[i])){
                if(first==-1){
                    first=i;
                    last=i;
                }
                else{
                    last=i;
                }
            }
        }
        return last-first;
    }
};