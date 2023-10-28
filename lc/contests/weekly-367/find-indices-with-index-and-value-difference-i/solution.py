from typing import List

class Solution:
    def findIndices(self, nums: List[int], indexDifference: int, valueDifference: int) -> List[int]:
        for j in range(indexDifference, len(nums)):
            for i in range(j - indexDifference + 1):
                if abs(nums[j] - nums[i]) >= valueDifference:
                    return [i, j]
        return [-1, -1]
    
def main():
    nums = [0]
    indexDifference = 0
    valueDifference = 0
    ret = Solution().findIndices(nums, indexDifference, valueDifference)
    print(ret)

if __name__ == '__main__':
    main()