/*
给你一个二进制数组nums 。

如果一个子数组中 不存在 两个 相邻 元素的值 相同 的情况，我们称这样的子数组为 交替子数组 。

返回数组 nums 中交替子数组的数量。

Solution: 似乎不算是严格的dp。 我做的时候应该是使用了类似贡献法的那种思路(?  不过也不是很严格的定义就是了...
*/

//my solution:
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        if(nums.size()==1) return 1;
        long long ans=0;
        long long cnt=0;
        int pre=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==pre){
                ans+=(long long)(cnt+1)*cnt/2;//...之前的cnt个数里面可以组成的交替子数组数量
                pre=nums[i];
                cnt=1;
            }
            else{
                pre=nums[i];
                cnt+=1;
            }
        }
        //如果最后一次未统计
        if(nums[nums.size()-1]!=nums[nums.size()-2])
            ans+=(cnt+1)*cnt/2;
        else{
            ans+=1;
        }
        return ans;
    }
};

//copyed from answer, using dp :  
// class Solution:
//     def countAlternatingSubarrays(self, nums: List[int]) -> int:
//         dp = [0]*len(nums)
//         dp[0] = 1
//         for i in range(1, len(nums)):
//             if nums[i] != nums[i-1]:
//                 dp[i] = dp[i-1]+1
//             else:
//                 dp[i] = 1
//         return sum(dp)
