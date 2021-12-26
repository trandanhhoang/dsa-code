class Solution(object):
    def groupAnagrams(self, strs):
        base = 31;
        prim = 1e9 + 7;

        groupResult = []
        groupSum = []
        myDict = {}

        for i in range(len(strs)):
            sum = 0

            for j in range(len(strs[i])):
                sum += (sum * base + int(strs[i][j])) % prim


            print(sum)
            print(groupSum)
            if sum not in groupSum:
                groupSum.append(sum)

            myDict[sum].append(strs[i])

        for ele in groupSum:
            # groupResult.append(strs[i])
            print(ele)

        return [[""]]



