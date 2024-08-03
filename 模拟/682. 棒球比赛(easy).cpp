/*
你现在是一场采用特殊赛制棒球比赛的记录员。这场比赛由若干回合组成，过去几回合的得分可能会影响以后几回合的得分。

比赛开始时，记录是空白的。你会得到一个记录操作的字符串列表 ops，其中 ops[i] 是你需要记录的第 i 项操作，ops 遵循下述规则：

整数 x - 表示本回合新获得分数 x
"+" - 表示本回合新获得的得分是前两次得分的总和。题目数据保证记录此操作时前面总是存在两个有效的分数。
"D" - 表示本回合新获得的得分是前一次得分的两倍。题目数据保证记录此操作时前面总是存在一个有效的分数。
"C" - 表示前一次得分无效，将其从记录中移除。题目数据保证记录此操作时前面总是存在一个有效的分数。
请你返回记录中所有得分的总和。

Solution:栈模拟
*/
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>stk;
        for(auto&&op:operations){
            if(op=="+"){
                int a=stk.top();
                stk.pop();
                int b=stk.top();
                stk.pop();
                stk.push(b);
                stk.push(a);
                stk.push(a+b);
            }
            else if(op=="D"){
                stk.push(stk.top()*2);
            }
            else if(op=="C"){
                stk.pop();
            }
            else{
                
                stk.push(stoi(op));
            }
        }
        int ans=0;
        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }
        return ans;
    }
};