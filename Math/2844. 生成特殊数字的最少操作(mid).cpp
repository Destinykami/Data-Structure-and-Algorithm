/*
给你一个下标从 0 开始的字符串 num ，表示一个非负整数。

在一次操作中，您可以选择 num 的任意一位数字并将其删除。请注意，如果你删除 num 中的所有数字，则 num 变为 0。

返回最少需要多少次操作可以使 num 变成特殊数字。

如果整数 x 能被 25 整除，则该整数 x 被认为是特殊数字。

Solution: 特殊数字：0，或者尾数为00，25，50，75
            写的很复杂，答案有更简洁的写法。
*/
class Solution {
public:
    int minimumOperations(string num) {
        //能被25整除：以00或者25或者50,75结尾
        int n=num.length();
        int idx=-1;
        int ans=n;
        int flag=0;
        for(int i=n-1;i>=0;i--){ //从后往前找到第一个0
            if(num[i]=='0'){
                idx=i;
                break;
            }
        }
        if(idx!=-1){
            ans=n-1;
            int tmp1=n-idx-1;
            for(int i=idx-1;i>=0;i--){
                if(num[i]=='0'||num[i]=='5'){
                    flag=1;
                    break;
                }
                else tmp1+=1;
            }
            if(flag==1){
                ans=min(ans,tmp1);
            }
        }
        flag=0;
        idx=-1;
        for(int i=n-1;i>=0;i--){ //从后往前找到第一个5
            if(num[i]=='5'){
                idx=i;
                break;
            }
        }
        if(idx!=-1){
            int tmp2=n-idx-1;
            for(int i=idx-1;i>=0;i--){
                if(num[i]=='2'||num[i]=='7'){
                    flag=1;
                    break;
                }
                else tmp2+=1;
            }
            if(flag==1) ans=min(ans,tmp2);
        }
        return ans;
    }
};