/*
给你一个下标从 0 开始的 正 整数数组 nums 。

如果 nums 的一个子数组满足：移除这个子数组后剩余元素 严格递增 ，那么我们称这个子数组为 移除递增 子数组。比方说，[5, 3, 4, 6, 7] 中的 [3, 4] 是一个移除递增子数组，因为移除该子数组后，[5, 3, 4, 6, 7] 变为 [5, 6, 7] ，是严格递增的。

请你返回 nums 中 移除递增 子数组的总数目。

注意 ，剩余元素为空的数组也视为是递增的。

子数组 指的是一个数组中一段连续的元素序列。

Solution: 2024/7/10的每日一题是这题的数据缩水版本，标为了easy，使用暴力枚举所有子数组可以通过...
        对于本题，显然暴力是不能通过的。
        假设移除中间一段数组，则移除后，前面和后面的剩余元素构成递增子数组。
        
        1. 那么，从前往后，找到第一段严格递增的数组的最后位置left

        2. 接着尝试把left往前移动，然后从后往前，找到最后一段严格递增的数组的最开始位置right，注意nums[right]需要严格大于nums[left]
                则可以累加每次的子数组数量n-right+1;  (以left为开始，right为末尾的起始，n为末尾的中止，这其中的子数组有n-right+1个)
        3. 最后，在left已经移动到-1的情况下，尝试把right在满足和其之后的数构成严格递增的情况下继续往前移动。
            则以数组起始0开始，末尾为[right,n)的子数组都可以删，有n-right+1个。
*/
class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        //假设移除中间一段数组，则移除后，前面和后面的剩余元素构成递增子数组
        long long ans=0;
        int n=nums.size();
        int left=0;
        int right=n;
        //从前往后找到一段递增数组
        while(left+1<n){
            if(nums[left+1]>nums[left]){
                left+=1;
            }
            else{
                break;
            }
        }
        if(left==n-1){ //所有子数组都可以移除，需要特判，不然会报错。。。
            return n*(n+1)/2;
        }
        //将right指针移动到末尾一段递增子数组，
        //并且要保证nums[right] > nums[left]，
        //那么此时从right开始到结尾的子数组都是可以移除的
        while(left>=0){
            while(nums[right-1]>nums[left]&&(right==n||nums[right-1]<nums[right])){
                right-=1;
            }
            left-=1;
            ans+=n-right+1;
        }
        //right继续尝试向前移动
        //那么此时从right开始到结尾的子数组都是可以移除的
        while(right==n||nums[right-1]<nums[right]){
            right-=1;
        }
        return ans+n-right+1;
    }
};