#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class Solution {
public:
  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
    std::unordered_map<std::string, std::vector<std::string>> res;

    for (const auto &s : strs) {

      std::vector<int> freq(26, 0);

      // Builds the frequency array for the first string
      for (char c : s) {
        freq[c - 'a']++;
      }

      // Turn the frequency array into the key
      std::string key = std::to_string(freq[0]);

      // This creates the key by placing the exact frequency of letters into the key
      for (int i = 1; i < 26; i++) {
        key += ',' + std::to_string(freq[i]);
      }

      // This places the string into the map at the key, if the key matches it will be included in the value(vector<string>)
      res[key].push_back(s);
    }

    std::vector<std::vector<std::string>> result;

    for (const auto &pair : res) {

      // The first and second fields of a map in C++, are the key and value respectively
      result.push_back(pair.second);
    }
    return result;
  }
};

int main() {
  Solution sol = Solution();

  std::vector<std::string> strs = {"strs", "srts", "cat"};

  auto sorted = sol.groupAnagrams(strs);

  for (const auto &strs : sorted) {
    for (const auto &str : strs) {
      std::cout << str << " ";
    }
    std::cout<< std::endl;
  }


}
