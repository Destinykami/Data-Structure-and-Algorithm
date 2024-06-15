/*
给定字符串列表 strs ，返回其中 最长的特殊序列 的长度。如果最长特殊序列不存在，返回 -1 。

特殊序列 定义如下：该序列为某字符串 独有的子序列（即不能是其他字符串的子序列）。

 s 的 子序列可以通过删去字符串 s 中的某些字符实现。

Solution: 枚举所有子串对，跑LCS
          rust写LC真麻烦..考虑重新用c++写好了
*/

use std::cmp::max;

impl Solution {
    pub fn lcs(str1: &str, str2: &str) -> usize {
        let mut dp = vec![vec![0; str2.len() + 1]; str1.len() + 1];
        let str1_chars: Vec<char> = str1.chars().collect();
        let str2_chars: Vec<char> = str2.chars().collect();
        
        for i in 1..=str1.len() {
            for j in 1..=str2.len() {
                if str1_chars[i - 1] == str2_chars[j - 1] {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        dp[str1.len()][str2.len()]
    }

    pub fn find_lu_slength(strs: Vec<String>) -> i32 {
        let mut ans = -1;
        for i in 0..strs.len() {
            let mut flag = false;
            for j in 0..strs.len() {
                if i != j && Solution::lcs(&strs[i], &strs[j]) == strs[i].len() {
                    flag = true;
                    break;
                }
            }
            if !flag {
                ans = max(ans, strs[i].len() as i32);
            }
        }
        ans
    }
}