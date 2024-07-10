"""
给你一个下标从 0 开始的数组 points ，它表示二维平面上一些点的整数坐标，其中 points[i] = [xi, yi] 。

两点之间的距离定义为它们的 曼哈顿距离 。

请你恰好移除一个点，返回移除后任意两点之间的 最大 距离可能的 最小 值。

Solution: 没思路。  看了题解，原来可以把曼哈顿距离转化为切比雪夫距离...
        另外，python的SortedList真的很犯规hhhh
附链接：
https://oi-wiki.org/geometry/distance/
"""
from sortedcontainers import SortedList
class Solution:
    def minimumDistance(self, points: List[List[int]]) -> int:
        xs = SortedList()
        ys = SortedList()
        #曼哈顿距离的转换
        for x,y in points:
            xs.add(x+y)
            ys.add(y-x)
        ans=inf
        for x,y in points:
            x,y=x+y,y-x
            xs.remove(x)
            ys.remove(y)
            ans=min(ans,max(xs[-1]-xs[0],ys[-1]-ys[0]))
            xs.add(x)
            ys.add(y)
        return ans