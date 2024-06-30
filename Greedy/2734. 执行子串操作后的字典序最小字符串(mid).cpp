/*
给你一个仅由小写英文字母组成的字符串 s 。在一步操作中，你可以完成以下行为：

选择 s 的任一非空子字符串，可能是整个字符串，接着将字符串中的每一个字符替换为英文字母表中的前一个字符。例如，'b' 用 'a' 替换，'a' 用 'z' 替换。
返回执行上述操作 恰好一次 后可以获得的 字典序最小 的字符串。

子字符串 是字符串中的一个连续字符序列。

现有长度相同的两个字符串 x 和 字符串 y ，在满足 x[i] != y[i] 的第一个位置 i 上，如果  x[i] 在字母表中先于 y[i] 出现，则认为字符串 x 比字符串 y 字典序更小 。

Solution: 贪心,如果不是a,则需要开始往后替换，如果接下来遇到a则停止。
            注意判断字符串全是a的情况，这种情况把最后一个a替换成z
*/
class Solution {
public:
    string smallestString(string s) {
        //如果不是a,则需要开始替换，如果接下来遇到a则停止
        int flag=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!='a'){
                flag=1;
                for(int j=i;j<s.length();j++){
                    if(s[j]=='a'){
                        break;
                    }
                    s[j]=s[j]-1;
                }
                break;
            }
        }
        if (flag==0){
            s[s.length()-1]='z';
        }
        return s;
    }
};