class Solution:
    def lengthOfLongestSubstring(self, s):
        '''Given a string, find the length of the longest substring without repeating characters.'''
        if not s:
            print("input sring is empty")
            return 0
        maxlen = 1
        begin = 0
        end = 1
        while end < len(s):
            for i in range(begin, end):
                if s[i] == s[end]:
                    if (end-begin) > maxlen:
                        maxlen = (end-begin)
                    #print(s[begin:end],maxlen)
                    begin = begin + (i-begin) + 1
                    break
            end = end + 1
            if (end-begin) > maxlen:
                maxlen = (end-begin)
            #print(s[begin:end],maxlen)
            
        #print(maxlen)
        return maxlen
        
#help(Solution.lengthOfLongestSubstring)

if __name__ == "__main__":
    sol = Solution()
    s = "abcdabcdefg"
    sol.lengthOfLongestSubstring(s)
    s = "abcabcbb"
    sol.lengthOfLongestSubstring(s)
    s = "bbbbb"
    sol.lengthOfLongestSubstring(s)
    s = "pwwkew"
    sol.lengthOfLongestSubstring(s)
    s = "pwwkewlkopfdsafubnfldkMaQ"
    sol.lengthOfLongestSubstring(s)
    s = " aAbB c"
    sol.lengthOfLongestSubstring(s)
    