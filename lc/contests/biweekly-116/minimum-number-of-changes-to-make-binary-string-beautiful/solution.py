class Solution:
    def minChanges(self, s: str) -> int:
        # if we want to partiion s into substrings of even length, s must be partitioned at even indices

        # s[i*2] and s[i*2+1] must be the same

        return sum([s[i * 2] != s[i * 2 + 1] for i in range(len(s) // 2)])
    
def main():
    s = "1001"
    ans = Solution().minChanges(s)
    print(ans)

if __name__ == '__main__':
    main()