# Write a function solve that finds the sum of three integers in an array that is closest to a target number. Return the sum of the three integers. You may assume that each input would have exactly one solution.

# Example:
# Input: [-1,2,1,-4], 1
# Output: 2 

# Make sure you return your solution, don't print!

def solve(nums, target):
  nums.sort()
  flag=False
  sum=[]
  for i in range(2, len(nums)):
    sum.append(nums[i]+nums[i-1]+nums[i-2])
  
  i=0
  while(i<len(sum)-1 and sum[i]<target):
      i+=1
      
  return sum[i]
