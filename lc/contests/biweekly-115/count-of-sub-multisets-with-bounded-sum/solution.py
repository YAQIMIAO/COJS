from typing import List
from collections import Counter

class Solution:
    def countSubMultisets(self, nums: List[int], l: int, r: int) -> int:

        f = [1 if l <= x <= r else 0 for x in range(r + 1)]
        d = Counter(nums)
        modulo = 10 ** 9 + 7
        
        # f[k] += f[k + num * i] for i=1..d[num] for k=0..r-num*i
        for num, count in d.items(): 
            for j in range(min(num, r)): 
                s = sum([f[j + num * i] if j + num * i <=r else 0 for i in range(count)]) 
                for i in range((r - j) // num): 
                    s -= f[j + num * i] 
                    if j + num * (i + count) <= r:
                        s += f[j + num * (i + count)] 
                    f[j + num * i] = (f[j + num * i] + s) % modulo

        return f[0] * (d.get(0, 0) + 1) % modulo

def main():
    nums = [0]
    l = 0
    r = 0
    ret = Solution().countSubMultisets(nums, l, r)
    print(ret)

if __name__ == '__main__':
    main()