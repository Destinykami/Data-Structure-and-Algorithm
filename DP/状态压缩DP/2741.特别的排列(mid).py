'''
给你一个下标从 0 开始的整数数组 nums ，它包含 n 个 互不相同 的正整数。如果 nums 的一个排列满足以下条件，我们称它是一个特别的排列：

对于 0 <= i < n - 1 的下标 i ，要么 nums[i] % nums[i+1] == 0 ，要么 nums[i+1] % nums[i] == 0 。
请你返回特别排列的总数目，由于答案可能很大，请将它对 10^9 + 7 取余 后返回。

Solution: 注意到n的范围从2到14,所以可以用一个int的每一位来标记每个数是否被用过
            每次从头开设遍历数组，如果没用过该数，则判断是否可用，若可用则使用，递归进行下一次选取
'''
class Solution:
    def specialPerm(self, nums: List[int]) -> int:
        n=len(nums)
        @cache
        def dfs(pre:int,mask:int)->int:
            #pre:上个数   mask:每个数的状态
            tmp=0
            flag=1
            for i in range(0,n):
                if mask>>i & 1==0:
                    flag=0
                    if (nums[i]%pre==0 or pre%nums[i]==0): #没用过这个数
                        tmp+=dfs(nums[i],mask|(1<<i))
            if flag==1:
                return 1
            return tmp%1_000_000_007
        return dfs(1,0)
                
                    