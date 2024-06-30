"""
一个魔法师有许多不同的咒语。

给你一个数组 power ，其中每个元素表示一个咒语的伤害值，可能会有多个咒语有相同的伤害值。

已知魔法师使用伤害值为 power[i] 的咒语时，他们就 不能 使用伤害为 power[i] - 2 ，power[i] - 1 ，power[i] + 1 或者 power[i] + 2 的咒语。

每个咒语最多只能被使用 一次 。

请你返回这个魔法师可以达到的伤害值之和的 最大值 。

Solution : 打家劫舍!  先排序，然后相邻的两个不能选，用二分搜索下一个位置
"""
class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        power.sort()
        c=Counter(power)
        @cache
        def dfs(i:int)->int:
            if i>=len(power):
                return 0
            return max(dfs(i+1),c[power[i]]*power[i]+dfs(bisect_right(power,power[i]+2)))
        ans= dfs(0)
        dfs.cache_clear()
        return ans
