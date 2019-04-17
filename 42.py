class Solution:
    def trap(self, height):
        '''Given n non-negative integers representing an elevation map where the width of each bar is 1, 
           compute how much water it is able to trap after raining.
           height: List[int]
           return: int
        '''
        if len(height) < 3:
            return 0

        ians = 0
        left,right = 0, len(height) - 1
        maxL, maxR = height[left], height[right]
        
        while left < right:
            if (maxL <= maxR):
                left+=1
                if maxL - height[left] > 0:
                    ians = ians + (maxL - height[left])
                else:
                    maxL = height[left]
            else:
                right-=1
                if maxR - height[right] > 0:
                    ians = ians + (maxR - height[right])                        
                else:
                    maxR = height[right]
        
        #print(ians)
        return ians

"""
if __name__ == "__main__":
    sol = Solution()
    height = [0,1,0,2,1,0,1,3,2,1,2,1]
    sol.trap(height)
    height = [0,1,1,9,1,0,1,3,2,1,2,1]
    sol.trap(height)
    height = [9,8,7,6,5,4,3,2,1,2,3,2,1,1,2]
    sol.trap(height)
    height = [2,1,1,2,3,2,1,2,3,4,5,6,7,8,9]
    sol.trap(height)
    height = [9,8,9,8,7,8,7,6,5,6,100,200,0,1]
    sol.trap(height)
    height = [5,5,5,5,5,6,6,6,6,7,7,7,7,7,5,100]
    sol.trap(height)
    height = [9,8,7,6,5,4,3,2,1,0,1]
    sol.trap(height)
    height = [1000,0,100,0,50,0,30]
    sol.trap(height)
    height = [1000,0,100,0,50,0,1000]
    sol.trap(height)
"""