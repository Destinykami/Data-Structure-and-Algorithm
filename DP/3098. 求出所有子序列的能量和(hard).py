'''
给你一个长度为 n 的整数数组 nums 和一个 正 整数 k 。

一个 子序列的 能量 定义为子序列中 任意 两个元素的差值绝对值的 最小值 。

请你返回 nums 中长度 等于 k 的 所有 子序列的 能量和 。

由于答案可能会很大，将答案对 10^9 + 7 取余 后返回。

Solution: 首先把数组排序，然后记忆化搜索枚举每个子序列
'''
class Solution:
    def sumOfPowers(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans=0
        n=len(nums)
        mod=1_000_000_007
        @cache
        def dfs(idx:int,pre:int,diff:int,cnt:int)->int:
            #idx:当前访问的元素下标 pre:上个访问元素  diff:元素差值的最小值  cnt:当前子序列中的元素个数
            res=0
            if cnt==k:
                return diff
            if idx>=n:
                return 0
            res+=dfs(idx+1,nums[idx],min(diff,nums[idx]-pre),cnt+1) %mod#选
            res+=dfs(idx+1,pre,diff,cnt)%mod #不选
            return res
        return dfs(0,-0x3f3f3f3f,0x3f3f3f3f,0)%mod