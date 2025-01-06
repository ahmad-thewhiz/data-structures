def solve(nums):
  maxSum=-99999
  currSum=0
  for num in nums:
    currSum+=num
    if currSum>maxSum:
      maxSum=currSum
    if currSum<0:
      currSum=0
  return maxSum
