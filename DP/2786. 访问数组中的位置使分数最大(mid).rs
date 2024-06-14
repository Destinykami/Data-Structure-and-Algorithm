/*
给你一个下标从 0 开始的整数数组 nums 和一个正整数 x 。

你 一开始 在数组的位置 0 处，你可以按照下述规则访问数组中的其他位置：

如果你当前在位置 i ，那么你可以移动到满足 i < j 的 任意 位置 j 。
对于你访问的位置 i ，你可以获得分数 nums[i] 。
如果你从位置 i 移动到位置 j 且 nums[i] 和 nums[j] 的 奇偶性 不同，那么你将失去分数 x 。
请你返回你能得到的 最大 得分之和。

注意 ，你一开始的分数为 nums[0] 。

Solution: dp,分别统计上一次是奇数和偶数的情况，取最大值，注意nums[0]是必选,所以even和odd有一个要初始为非法值
*/

use std::cmp::max;
impl Solution {
    pub fn max_score(nums: Vec<i32>, x: i32) -> i64 {
        let mut even=-0x3f3f3f;
        let mut odd=-0x3f3f3f;
        if nums[0]%2==0{
            even=nums[0];
        }
        else{
            odd=nums[0];
        }
        for i in 1..nums.len(){
            if nums[i as usize]%2==0{
                even=max(even,odd-x)+nums[i as usize];
            }
            else{
                odd=max(odd,even-x)+nums[i as usize];
            }
        }
        max(odd,even) as i64
    }
}