
#include <iostream>
#include <unordered_map>
#include <vector>
class Solution {
public:
  // NOTE: This is the simple solution uses two nested for loops for a O(n^2) runtime.
  std::vector<int> twoSum1(std::vector<int>& nums, int target) {


    std::vector<int> answer;
    for (int i = 0; i < nums.size(); i++) {
      // NOTE: Don't forget your indexing, the y = i + 1 because you can't use the same index twice.
      for (int y = i + 1; y < nums.size(); y++) {
        if (nums[i] + nums[y] == target) {
          answer.push_back(i);
          answer.push_back(y);
          return answer;
        }
      }
    }
    return answer;
  }


  // NOTE: this is the hash map solution pretty obvious now that I've seen it.
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    // NOTE: the unordered_map is a hashmap in c++
    std::unordered_map<int, int> hash;
    // NOTE: must walk through the list at least once if one index of solution is at the end.
    for (int i = 0; i < nums.size(); i++) {

      int complement = target - nums[i];

      // NOTE: Looks for a pair using a key 'complement'
      if (hash.find(complement) != hash.end()) {

        // NOTE: You can return a vector like this very cool.
        return {hash[complement], i};
      }
      // NOTE: This fills the hashmap with the key value pairs.
      // NOTE: adds the index to the hashmap using the value of the elements index
      hash[nums[i]] = i;
    }
    return {};
  }

};

int main (int argc, char *argv[]) {
  Solution sol;

  std::vector<int> nums;
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(2);

  for (int num : sol.twoSum(nums, 3)) {
    std::cout << num << std::endl;
  }
  return 0;
}

