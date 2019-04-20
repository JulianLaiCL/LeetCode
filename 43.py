class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        """
        num1 : str
        num2 : str
        return : str
        """
        len1 = len(num1)
        len2 = len(num2)
        vans = [0]*(len1+len2)
        for i in range(len1-1,-1,-1):
            pos = len1-1-i
            tmp = 0
            for k in range(len2-1,-1,-1):
                tmp = int(num2[k]) * int(num1[i]) + vans[pos]
                vans[pos+1] += int(tmp/10)
                vans[pos] = tmp%10
                pos += 1
        leadzero = 0
        s = ''
        for i in range(len(vans)-1,-1,-1):
            if vans[i] == 0 and leadzero == 0 and i >= 1:
                continue
            leadzero = 1
            s = s + str(vans[i])
        #print(vans)
        #print(s)
        return s

if __name__ == "__main__":
    sol = Solution()
    assert sol.multiply("123", "456")=="56088"
    assert sol.multiply("2", "3")=="6"
    assert sol.multiply("8817067", "926338")=="8167584210646"
    assert sol.multiply("8817067", "0")=="0"
    assert sol.multiply("0", "0")=="0"
    assert sol.multiply("0", "9988776")=="0"
    assert sol.multiply("1234567890", "998877665544332211")=="1233182291919191919193304790"
    assert sol.multiply("10000000000", "1000000000000000000000000000000")=="10000000000000000000000000000000000000000"
    assert sol.multiply("10000000000000000000000000000000000000000000000000000000000000000000000", "10000000000")=="100000000000000000000000000000000000000000000000000000000000000000000000000000000"
