'''
给你两个长度为 n 下标从 0 开始的整数数组 cost 和 time ，分别表示给 n 堵不同的墙刷油漆需要的开销和时间。你有两名油漆匠：

一位需要 付费 的油漆匠，刷第 i 堵墙需要花费 time[i] 单位的时间，开销为 cost[i] 单位的钱。
一位 免费 的油漆匠，刷 任意 一堵墙的时间为 1 单位，开销为 0 。但是必须在付费油漆匠 工作 时，免费油漆匠才会工作。
请你返回刷完 n 堵墙最少开销为多少。

Solution: 付费的工作时间>=免费的工作时间
'''
class Solution:
    def paintWalls(self, cost: List[int], time: List[int]) -> int:
        #付费的工作时间>=免费的工作时间
        n=len(cost)
        #diff:工作时间的差值，idx:当前下标，返回最小开销
        @cache
        def dfs(diff:int,idx:int)->int:
            if diff>=(n-idx) : #付费时间够把剩下的所有都做完  不如此剪枝的话而是继续往后判断，道理上也没问题，但是会爆内存
                return 0
            if idx>=n: #如果上面可做完工作，则不会执行到这行
                return inf
            return min(dfs(diff+time[idx],idx+1)+cost[idx],dfs(diff-1,idx+1))
        return dfs(0,0)