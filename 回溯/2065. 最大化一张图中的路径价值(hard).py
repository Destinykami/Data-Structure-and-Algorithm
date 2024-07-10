"""
给你一张 无向 图，图中有 n 个节点，节点编号从 0 到 n - 1 （都包括）。同时给你一个下标从 0 开始的整数数组 values ，其中 values[i] 是第 i 个节点的 价值 。同时给你一个下标从 0 开始的二维整数数组 edges ，其中 edges[j] = [uj, vj, timej] 表示节点 uj 和 vj 之间有一条需要 timej 秒才能通过的无向边。最后，给你一个整数 maxTime 。

合法路径 指的是图中任意一条从节点 0 开始，最终回到节点 0 ，且花费的总时间 不超过 maxTime 秒的一条路径。你可以访问一个节点任意次。一条合法路径的 价值 定义为路径中 不同节点 的价值 之和 （每个节点的价值 至多 算入价值总和中一次）。

请你返回一条合法路径的 最大 价值。

注意：每个节点 至多 有 四条 边与之相连。

Solution: 回溯,遍历所有边,取最大价值MAX
"""
class Solution:
    def maximalPathQuality(self, values: List[int], edges: List[List[int]], maxTime: int) -> int:
        n=len(values)
        ans=0
        g=defaultdict(list)
        for u,v,time in edges:
            g[u].append((v,time))
            g[v].append((u,time))
        
        def dfs(cur,visit,value,remain_time):
            if cur==0:
                nonlocal ans
                ans=max(ans,value)
            for nextnode,time in g[cur]:
                if remain_time-time>=0:
                    if nextnode in visit:
                        dfs(nextnode,visit,value,remain_time-time)
                    else:
                        visit.add(nextnode) #注意这里的回溯操作
                        dfs(nextnode,visit,value+values[nextnode],remain_time-time)
                        visit.remove(nextnode)

        dfs(0, set([0]), values[0], maxTime)
        return ans

