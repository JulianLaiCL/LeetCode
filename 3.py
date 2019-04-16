class Solution:
    def lengthOfLongestSubstring(self, s):
        '''Given a string, find the length of the longest substring without repeating characters.'''
        if not s:
            print("input sring is empty")
            return 0
        maxlen = 1
        begin = 0
        end = 0
        dict = {}
        while end < len(s):
            if s[end] in dict:
                if (end-begin) > maxlen:
                    maxlen = (end-begin)
                #remove from begin char to the duplicated char
                for i in range(begin,dict[s[end]]):
                    del dict[s[i]]
                begin = dict[s[end]]+1
                del dict[s[end]]
            dict[s[end]] = end
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
    print(sol.lengthOfLongestSubstring(s))
    s = "abcabcbb"
    print(sol.lengthOfLongestSubstring(s))
    s = "bbbbb"
    print(sol.lengthOfLongestSubstring(s))
    s = "pwwkew"
    print(sol.lengthOfLongestSubstring(s))
    s = "pwwkewlkopfdsafubnfldkMaQ"
    print(sol.lengthOfLongestSubstring(s))
    s = " aAbB c"
    print(sol.lengthOfLongestSubstring(s))
    