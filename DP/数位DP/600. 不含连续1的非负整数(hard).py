"""
给定一个正整数 n ，请你统计在 [0, n] 范围的非负整数中，有多少个整数的二进制表示中不存在 连续的 1 。

Solution:数位dp
"""
class Solution:
    def findIntegers(self, n: int) -> int:
        #数位dp
        @cache
        def dfs(idx:int,pre:bool,isLimit:bool):
            #idx:当前下标，pre:上一个是否是1，isLimit:是否被n约束
            if idx<0:
                return 1
            up=n>>idx&1 if isLimit else 1  #如果受约束，则当前位只能填比n的当前位相等或者小的
            ans=dfs(idx-1,False,isLimit and up==0) #填0  如果当前不受约束，或者n当前位为1则填0后都不受约束，如果n当前位为0，填0后仍受约束
            if not pre and up==1:
                ans+=dfs(idx-1,True,isLimit) #填1
            return ans

        return dfs(n.bit_length()-1,False,True)