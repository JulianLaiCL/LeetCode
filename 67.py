class Solution:
    def addBinary(self, a: str, b: str) -> str:
        '''
        a: str
        b: str
        return: str
        '''
        lena = len(a)
        lenb = len(b)
        s = ''
        carry = 0
        vala = valb = 0
        tmp = 0
        while lena > 0 or lenb > 0:
            lena = lena - 1
            lenb = lenb - 1
            if lena >= 0:
                vala = int(a[lena])
            else:
                vala = 0
            if lenb >= 0:
                valb = int(b[lenb])
            else:
                valb = 0
            tmp = vala + valb + carry
            s = s + str(tmp % 2)
            carry = tmp >> 1
        
        if carry > 0:
            s = s + '1'
        
        s = s[::-1] #reverse string
        #print(s)
        return s

'''
if __name__ == "__main__":
    sol = Solution()
    assert "100" == sol.addBinary("11","1"),"TEST FAIL"
    assert "10" == sol.addBinary("1","1"),"TEST FAIL"
    assert "10101" == sol.addBinary("1010","1011"),"TEST FAIL"
    assert "1011" == sol.addBinary("1010","1"),"TEST FAIL"
    assert "11100" == sol.addBinary("10101","111"),"TEST FAIL"
    print("TEST PASS")
'''