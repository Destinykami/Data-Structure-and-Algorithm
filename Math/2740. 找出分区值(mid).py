'''
给你一个 正 整数数组 nums 。

将 nums 分成两个数组：nums1 和 nums2 ，并满足下述条件：

数组 nums 中的每个元素都属于数组 nums1 或数组 nums2 。
两个数组都 非空 。
分区值 最小 。
分区值的计算方法是 |max(nums1) - min(nums2)| 。

其中，max(nums1) 表示数组 nums1 中的最大元素，min(nums2) 表示数组 nums2 中的最小元素。

返回表示分区值的整数。

Solution: 排个序就可以了，枚举分隔点，则前面部分为nums1，后面部分为nums2
'''
class Solution:
    def findValueOfPartition(self, nums: List[int]) -> int:
        nums.sort()
        n=len(nums)
        ans=inf
        for i in range(n-1):
            ans=min(ans,nums[i+1]-nums[i])
        return ans