/* Hard
来源：数据结构C++语言版 邓俊辉 

给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

Solution: 类似于木桶原理，最大面积受到最短柱子高度的限制，维护一个从大到小的单调栈，注意栈中存储的为下标
          当遍历到的元素比栈顶高时，计算以栈顶元素高度为高的矩形面积。
          需要特别注意边界的处理。

          Algorithm：单调栈 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //单调栈
        stack<int>stk;
        int maxRect=0;
        int n=heights.size();
        for(int i=0;i<=n;i++){ //注意边界的处理，这里i能取到等号
            while(!stk.empty()&&(i==n||heights[stk.top()]>heights[i])){
                int r=stk.top();
                stk.pop();
                int s=stk.empty()?0:stk.top()+1;
                maxRect=max(maxRect,heights[r]*(i-s));
            }
            if(i<n){
                stk.push(i);
            }
        }
        return maxRect;
    }
};