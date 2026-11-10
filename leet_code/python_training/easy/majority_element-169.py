class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        res = count = 0
        for val in nums:
            if count == 0:
                res = val
            count+= (1 if val == res else -1)
        return res