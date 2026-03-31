from sys import maxsize
from typing import Dict, List

# There are two faster solutions: the min-heap solution, which I will implement next and the bucket sort
# which I don't understand.

class Solution:
  def topKFrequent(self, nums: List[int], k: int) -> List[int]:
    """Solution for top K frequency leetcode problem"""
    # Loop through all of the nums in nums and then count each element, you can't use a any string manip tricks because you're using numbers not elements. Then you should just store the number in a hash table as a key and the frequency as the value.
    # Then you need to find all of the values above k, so loop through the hash map and append all keys where val > k.
    # That's not what the problem is looking for, you're looking for the most frequent k elements.
    answer: List[int] = []
    frequency_hash: Dict[int, int] = {}

    # Stores the frequencies
    for num in nums:
      if num in frequency_hash:
        frequency_hash[num] = frequency_hash[num] + 1
      else:
        frequency_hash[num] = 1


    # You could just loop through it k times and grab the top value each time. I believe worst case for that is n^2
    # This is O(k)
    greatest_key = 0
    for _ in range(k):

      # Sets the key for the sort
      greatest_key = -1001

      # This is O(k*n)
      for key, value in frequency_hash.items():

        greatest_value = frequency_hash.get(greatest_key)

        if greatest_value is None:
          greatest_value = -1001

        print("Key: ", key, "Value: ", value, "greatest value: ", greatest_value)

        if value > greatest_value:
          greatest_key = key

      answer.append(greatest_key)
      frequency_hash[greatest_key] = 0
      # Problem is if k >= n, that makes the worst case O(n^2)

    return answer

if __name__ == "__main__":
  nums = [1,2,2,3,3,3]
  k = 2
  sol = Solution()
  print(sol.topKFrequent(nums=nums, k=k))
