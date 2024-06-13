/*
给你一个长度为 n 的二维整数数组 items 和一个整数 k 。

items[i] = [profiti, categoryi]，其中 profiti 和 categoryi 分别表示第 i 个项目的利润和类别。

现定义 items 的 子序列 的 优雅度 可以用 total_profit + distinct_categories2 计算，

其中 total_profit 是子序列中所有项目的利润总和，distinct_categories 是所选子序列所含的所有类别中不同类别的数量。

你的任务是从 items 所有长度为 k 的子序列中，找出 最大优雅度 。

用整数形式表示并返回 items 中所有长度恰好为 k 的子序列的最大优雅度。

注意：数组的子序列是经由原数组删除一些元素（可能不删除）而产生的新数组，且删除不改变其余元素相对顺序。


Solution: 虽然说是子序列，但是其实顺序是没有关系的
*/
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        //顺序其实无所谓,按照profit从大到小排序
        int n=items.size();
        sort(items.begin(),items.end(),[&](const auto&a,const auto&b){
            return a[0]>b[0];
        });
        long long total_profit=0;
        unordered_set<int>ust;//已有的种类
        stack<int>stk; // 重复类别的利润
        long long ans=0;
        for(int i=0;i<n;i++){
            if(i<k){
                total_profit+=items[i][0];
                if(ust.count(items[i][1])){
                    stk.push(items[i][0]); //该种类已重复，存入栈中
                }
                else{
                    ust.insert(items[i][1]);
                }
            }
            else{
                //利润从大到小排序，因此用后面的利润替换前面的会使total_profit减少
                //要获得最大ans,则需要增加distinct_categories
                if(ust.count(items[i][1])){
                    continue;//已经存在该种类
                }
                if(!stk.empty()){
                    ust.insert(items[i][1]);
                    total_profit+=items[i][0]-stk.top();
                    stk.pop(); // 重复类别的利润 ,因为已经排序过了，所以栈顶的profit是最小的
                }
            }
            ans=max(ans,total_profit+(long long)ust.size()*(long long) ust.size());
        }
        return ans;
    }
};