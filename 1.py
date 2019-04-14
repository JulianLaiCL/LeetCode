class Solution:
    def twoSum(self, nums, target):
        result = []
        dict = {}
        for i in range(len(nums)):
            val = target - nums[i]
            if val in dict:
                return [dict[val], i]
            dict[nums[i]] = i

if __name__ == "__main__":
    sol = Solution()
    nums = [3,3]
    result = sol.twoSum(nums,6)
    nums = [1,3,4,2]
    result = sol.twoSum(nums,6)
    print(result)
    nums = [2,7,11,15]
    result = sol.twoSum(nums,9)
    print(result)
    nums = [2,7,9,11,15]
    result = sol.twoSum(nums,17)
    print(result)
    