class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        ret = ''
        p = 0
        ones = 0

        for i in range(len(s)):
            if s[i] == '1':
                if ones == k:
                    p += 1
                    while s[p] != '1' and p <= i:
                        p += 1
                    ones -= 1
                ones += 1
                if ones == 1:
                    p = i
                if ones == k:
                    if ret == '' or len(ret) > i - p + 1 or (len(ret) == i - p + 1 and ret > s[p:i + 1]):
                        ret = s[p:i + 1]
        
        return ret
    
def main():
    s = "11000111"
    k = 1
    ret = Solution().shortestBeautifulSubstring(s, k)
    print(ret)

if __name__ == '__main__':
    main()