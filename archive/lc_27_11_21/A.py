class Solution(object):
    def countWords(self, words1, words2):
        """
        :type words1: List[str]
        :type words2: List[str]
        :rtype: int
        """
        from collections import Counter
        w1 = Counter(words1)
        w2 = Counter(words2)
        s1 = {w for w, c in w1.items() if c == 1}
        s2 = {w for w, c in w2.items() if c == 1}
        return len(s1 & s2)


sol = Solution()
words1 = ["a", "ab"]
words2 = ["a", "a", "a", "ab"]

print(sol.countWords(words1, words2))
