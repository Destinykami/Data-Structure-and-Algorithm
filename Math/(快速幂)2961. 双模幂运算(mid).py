#TODO:自己实现快速幂

class Solution:
    def getGoodIndices(self, variables: List[List[int]], target: int) -> List[int]:
        ans=[]
        cnt=0
        for a,b,c,d in variables:
            if pow(pow(a,b)%10,c)%d==target:
                ans.append(cnt)
            cnt+=1
        return ans