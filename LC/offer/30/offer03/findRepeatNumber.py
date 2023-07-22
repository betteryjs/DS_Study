class Solution:
    def findRepeatNumber(self, nums):

        repeatDict = {}
        for num in nums:
            if num not in repeatDict:
                repeatDict[num] = 1
            else:
                return num


if __name__ == '__main__':
    go = Solution()
    num = [2, 3, 1, 0, 2, 5, 3]
    go.findRepeatNumber(num)
