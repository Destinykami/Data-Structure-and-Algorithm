'''
给你一个非负整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

Solution:   正数的和-负数的绝对值和=target
            正数的和+负数的绝对值和=sum(nums)
            于是问题变为在nums中选取数使其和为(sum(nums)+target)//2

            0-1背包问题
'''
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        #正数的和-负数的绝对值和=target
        #正数的和+负数的绝对值和=sum(nums)
        tmp=sum(nums)+target
        if tmp%2!=0:
            return 0
        res=tmp//2
        #在nums中挑数，使得其和为res
        n=len(nums)
        @cache
        def dfs(idx:int,cur:int)->int:
            #idx:当前下标，cur:当前的和
            if idx>=n:
                return 1 if cur==res else 0
            return dfs(idx+1,cur+nums[idx])+dfs(idx+1,cur)
        return dfs(0,0)