from typing import List

class Solution:
    def sumCounts(self, nums: List[int]) -> int:

        return sum([self.distinct_count(nums, i, j) ** 2 for i in range(len(nums)) for j in range(i, len(nums))])
    
    @staticmethod
    def distinct_count(nums: List[int], i: int, j:int) -> int:

        return len(set(nums[i:j+1]))

def main():
    nums = [1,2,1]
    ans = Solution().sumCounts(nums)
    print(ans)

if __name__ == '__main__':
    main()