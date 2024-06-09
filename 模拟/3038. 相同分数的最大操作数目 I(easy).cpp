/*
给你一个整数数组 nums ，如果 nums 至少 包含 2 个元素，你可以执行以下操作：

选择 nums 中的前两个元素并将它们删除。
一次操作的 分数 是被删除元素的和。

在确保 所有操作分数相同 的前提下，请你求出 最多 能进行多少次操作。

请你返回按照上述要求 最多 可以进行的操作次数。

Solution: 扫一遍就OK
*/

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int score=-1;
        int ans=0;
        for(int i=0;i<nums.size();i+=2){
            if(score==-1){
                score=nums[i]+nums[i+1];
                ans+=1;
            }
            else{
                if(nums[i]+nums[i+1]!=score){
                    break;
                }
                ans+=1;
            }
        }
        return ans;
    }
};