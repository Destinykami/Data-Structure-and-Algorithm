"""
给你一个整数数组 nums ，如果 nums 至少 包含 2 个元素，你可以执行以下操作中的 任意 一个：

选择 nums 中最前面两个元素并且删除它们。
选择 nums 中最后两个元素并且删除它们。
选择 nums 中第一个和最后一个元素并且删除它们。
一次操作的 分数 是被删除元素的和。

在确保 所有操作分数相同 的前提下，请你求出 最多 能进行多少次操作。

请你返回按照上述要求 最多 可以进行的操作次数。

Solution : 记忆化搜索
"""

class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        @cache
        def dfs(cur_sum:int,left:int,right:int)->int:
            #cur_sum:当前的和  left,right:左右边界   返回最大操作次数
            if left>=right:
                return 0
            tmp=0
            if nums[left]+nums[left+1]==cur_sum or cur_sum==-1:
                tmp=max(tmp,dfs(nums[left]+nums[left+1],left+2,right)+1)
            if nums[right-1]+nums[right]==cur_sum or cur_sum==-1:
                tmp=max(tmp,dfs(nums[right-1]+nums[right],left,right-2)+1)
            if nums[left]+nums[right]==cur_sum or cur_sum==-1:
                tmp=max(tmp,dfs(nums[left]+nums[right],left+1,right-1)+1)
            return tmp
        return dfs(-1,0,len(nums)-1)