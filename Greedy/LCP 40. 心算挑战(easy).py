'''
「力扣挑战赛」心算项目的挑战比赛中，要求选手从 N 张卡牌中选出 cnt 张卡牌，
若这 cnt 张卡牌数字总和为偶数，则选手成绩「有效」且得分为 cnt 张卡牌数字总和。 
给定数组 cards 和 cnt，其中 cards[i] 表示第 i 张卡牌上的数字。 
请帮参赛选手计算最大的有效得分。若不存在获取有效得分的卡牌方案，则返回 0。

Solution:排序，选取最大的cnt张，如果满足条件：和为偶数，则直接返回。如果不满足条件，则有以下两种情况
        1.把最后一个数（选取的最小的一个数）换成和它奇偶性不同的下一个最大的数。
        2.把和最后一个数奇偶性不同的之前已选取的一个数换成下一个和它奇偶性不同的最大的数。
        这样可以保证和为偶数。
'''
class Solution:
    def maxmiumScore(self, cards: List[int], cnt: int) -> int:
        cards.sort(reverse=True)
        s=sum(cards[:cnt])
        if s%2==0:
            return s
        def replace(x:int):
            for i in range(cnt,len(cards)):
                if cards[i]%2!=x%2:
                    return s-x+cards[i]
            return 0
        #尝试把最后一个数换为和它奇偶性不同的最大的数
        ans=replace(cards[cnt-1])
        for i in range(cnt-1,-1,-1):
            #从后往前找到一个奇偶性和最后一个数不同的数替换掉
            if cards[i]%2!=cards[cnt-1]%2:
                ans=max(ans,replace(cards[i]))
                break
        return ans
            