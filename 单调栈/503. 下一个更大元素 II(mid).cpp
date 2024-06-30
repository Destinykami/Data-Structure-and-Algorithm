/*
给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的 下一个更大元素 。

数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1 。

Solution: 单调栈，维护一个元素大小递减的栈，遍历数组，如果遇到比栈顶元素大的，则依次把栈顶元素出栈，当前的数就是栈顶元素的下一个更大的数。
            注意栈中存储的是下标，而不是数，要根据下标去nums中访问数
            还要注意数组是循环数组，可以把除了最后一个数以外的数给复制一遍，添加到原数组最后。
            但是实际上也可以不用真的这样操作，改变循环条件为[0,2*n-1)  下标访问时对n取余数即可。
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //单调栈
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>stk;
        for(int i=0;i<2*n-1;i++){
            while(!stk.empty()&&nums[stk.top()]<nums[i%n]){
                ans[stk.top()]=nums[i%n];
                stk.pop();
            }
            stk.push(i%n);
        }
        return ans;
    }
};