//left=0,right=total;right-sum[i],if(==),return i;left+nums[i];return -1
lass Solution(object):
    def pivotIndex(self, nums):
        # Time: O(n)
        # Space: O(1)
        left, right = 0, sum(nums)
        for index, num in enumerate(nums):
            right -= num
            if left == right:
                return index
            left += num
        return -1
