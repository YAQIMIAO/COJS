from typing import List

class Solution:
    def getWordsInLongestSubsequence(self, n: int, words: List[str], groups: List[int]) -> List[str]:

        wordLength = {}
        longestSubsequenceLength = []
        longestSubsequence = []

        for i, word in enumerate(words):
            wordLength[len(word)] = wordLength.get(len(word), []) + [i]
            longestSubsequence.append([i])
        for i in wordLength:
            longestSubsequenceLength[i] = [1 for _ in range(len(wordLength[i]))]

        # f[g[i]] = max(f[g[i]] + 1) for j < i if groups[g[i]] != groups[g[j]] and dist(words[g[i]], words[g[j]]) == 1
        # g - wordLength
        # f - longestSubsequenceLength
        for g in wordLength.values():
            for i in range(len(g)):
                for j in range(i):
                    if groups[g[i]] != groups[g[j]] and self.hammingDistance(words[g[i]], words[g[j]]) == 1:
                        if longestSubsequenceLength[g[j]] + 1 > longestSubsequenceLength[g[i]]:
                            longestSubsequenceLength[g[i]] = longestSubsequenceLength[g[j]] + 1
                            longestSubsequence[g[i]] = longestSubsequence[g[j]] + [g[i]]
        
        maxSequence = max(longestSubsequence, key=lambda x: len(x))
        
        return [words[i] for i in maxSequence]
        
    
    def hammingDistance(self, word1: str, word2: str) -> int:
        distance = 0
        for i in range(len(word1)):
            if word1[i] != word2[i]:
                distance += 1
        return distance
    
def main():
    n = 13
    words = ["cb","dc","ab","aa","ac","bb","ca","bcc","cdd","aad","bba","bc","ddb"]
    groups = [12,6,10,11,4,8,9,11,2,11,3,2,5]
    print(Solution().getWordsInLongestSubsequence(n, words, groups))

if __name__ == '__main__':
    main()