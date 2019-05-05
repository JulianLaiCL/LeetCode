class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        length = len(digits)
        if length == 0:
            return digits
        digits[length-1] += 1
        carry = 0
        for i in range(length-1, -1, -1): #start, end, step
            digits[i] = digits[i] + carry
            if digits[i] >= 10:
                digits[i] -= 10
                carry = 1
            else:
                carry = 0
                break #no need furthur operation
        if carry > 0:
            digits.insert(0, carry)
            
        return digits

'''
if __name__ == "__main__":
    sol = Solution()
    print(sol.plusOne([1,2,3,4,5]))
    print(sol.plusOne([7,9,9]))
    print(sol.plusOne([9,9,9]))
    print(sol.plusOne([8,8,1,7,0,9,9,9,9]))
'''