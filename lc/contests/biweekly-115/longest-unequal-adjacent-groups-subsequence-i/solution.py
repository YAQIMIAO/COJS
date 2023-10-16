from typing import List

class Solution:
    def getWordsInLongestSubsequence(self, n: int, words: List[str], groups: List[int]) -> List[str]:
        subsequence = []

        for i, group in enumerate(groups):
            if len(subsequence) == 0 or group != groups[subsequence[-1]]:
                subsequence.append(i)

        return [words[i] for i in subsequence]
    
def main():
    n = 3
    words = ["e","a","b"]
    groups = [0,0,1]
    print(Solution().getWordsInLongestSubsequence(n, words, groups))

if __name__ == '__main__':
    main()