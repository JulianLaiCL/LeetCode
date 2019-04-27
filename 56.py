class Solution:
    def merge(self, intervals):
        intervals = sorted(intervals, key=lambda intervals:intervals[0])
        #print(intervals)
        if len(intervals) < 2:
            return intervals
        minv = intervals[0][0]
        maxv = intervals[0][1]
        vans = []
        for i in intervals[1:]:
            if i[0] >= minv and i[0] <= maxv:
                maxv = max(maxv, i[1])
                #print("now max=" + str(maxv))
            else:
                vans.append([minv,maxv])
                minv = i[0]
                maxv = i[1]
        vans.append([minv,maxv])
        #print(vans)
        return vans

#if __name__ == "__main__":
#    sol = Solution()
#    intervals = [[1,2],[3,4],[2,3]]
#    intervals = [[1,3],[2,6],[8,10],[15,18]]
#    intervals = [[1,4],[2,3]]
#    intervals = [[2,3],[4,5],[6,7],[8,9],[1,10]]
#    sol.merge(intervals)