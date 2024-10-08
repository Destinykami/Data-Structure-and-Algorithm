/*
给你一个字符串 s 和一个整数 k 。

定义函数 distance(s1, s2) ，用于衡量两个长度为 n 的字符串 s1 和 s2 之间的距离，即：

字符 'a' 到 'z' 按 循环 顺序排列，对于区间 [0, n - 1] 中的 i ，计算所有「 s1[i] 和 s2[i] 之间 最小距离」的 和 。
例如，distance("ab", "cd") == 4 ，且 distance("a", "z") == 1 。

你可以对字符串 s 执行 任意次 操作。在每次操作中，可以将 s 中的一个字母 改变 为 任意 其他小写英文字母。

返回一个字符串，表示在执行一些操作后你可以得到的 字典序最小 的字符串 t ，且满足 distance(s, t) <= k 。

Solution: 贪心  优先变成a，如果不能变成a，则尽可能变成小的
*/
class Solution {
public:
    string getSmallestString(string s, int k) {
        //贪心  优先变成a，如果不能变成a，则尽可能变成小的
        int n=s.length();
        for(int i=0;i<n;i++){
            int dist=min(s[i]-'a','a'+26-s[i]);
            if(dist>k){
                s[i]-=k;
                k=0;
            }
            else{
                s[i]='a';
                k-=dist;
            }
        }
        return s;
    }
};