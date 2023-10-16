from typing import List

class Solution:
    def lastVisitedIntegers(self, words: List[str]) -> List[int]:
        
        nums = []
        p = -1
        ret = []

        for word in words:
            if word == 'prev':
                if p == -1:
                    ret.append(-1)
                else:
                    ret.append(nums[p])
                    p -= 1
            else:
                nums.append(int(word))
                p = len(nums) - 1

        return ret
    
def main():
    words = ["1","prev","2","prev","prev"]
    print(Solution().lastVisitedIntegers(words))

if __name__ == '__main__':
    main()