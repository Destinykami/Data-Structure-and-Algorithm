/*
一开始，你的银行账户里有 100 块钱。

给你一个整数purchaseAmount ，它表示你在一次购买中愿意支出的金额。

在一个商店里，你进行一次购买，实际支出的金额会向 最近 的 10 的 倍数 取整。换句话说，你实际会支付一个 非负 金额 roundedAmount ，满足 roundedAmount 是 10 的倍数且 abs(roundedAmount - purchaseAmount) 的值 最小 。

如果存在多于一个最接近的 10 的倍数，较大的倍数 是你的实际支出金额。

请你返回一个整数，表示你在愿意支出金额为 purchaseAmount 块钱的前提下，购买之后剩下的余额。

注意： 0 也是 10 的倍数。

Solution: 直接+5然后除以10再乘以10就是了... 自动舍弃来满足取整要求
*/
impl Solution {
    pub fn account_balance_after_purchase(purchase_amount: i32) -> i32 {
        100 - (purchase_amount + 5) / 10 * 10
    }
}