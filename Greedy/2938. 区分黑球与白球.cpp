/*
桌子上有 n 个球，每个球的颜色不是黑色，就是白色。

给你一个长度为 n 、下标从 0 开始的二进制字符串 s，其中 1 和 0 分别代表黑色和白色的球。

在每一步中，你可以选择两个相邻的球并交换它们。

返回「将所有黑色球都移到右侧，所有白色球都移到左侧所需的 最小步数」。

e.g:  101 -> 011

Solution: 贪心 从左到右遍历，每个0需要移到能放置的最右边的位置，这个位置受已经统计过的0的数量决定。

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        //注意只能交换相邻的
        int cnt=0;
        long long ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                ans+=(i-cnt);
                cnt+=1;
            }
        }
        return ans;
    }
};