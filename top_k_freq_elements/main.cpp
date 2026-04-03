#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main(int argc, char *argv[]) { return 0; }

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    vector<int> answer;

    // This is interesting
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        heap;
    unordered_map<int, int> map;

    // Loop through the num in nums and input into a map
    for (auto num : nums) {
      // Stores key's and frequencies
      map[num]++;
    }

    // for (every key-value pair in map)
    for (auto &key_value : map) {
      // need priority queue
      // .second holds the frequency (which is what we're using for priority on
      // the heap) We need .first so we can add the index to the output vector.
      heap.push({key_value.second, key_value.first});

      // This is important because it pops off smallest n - k values
      // If the heap was exposed to us we could just grab the last three
      // elements in the array
      if (heap.size() > k)
        heap.pop();
    }

    for (int i = 0; i < k; i++) {
      pair<int, int> key = heap.top();
      answer.push_back(key.second);
      heap.pop();
    }

    return answer;
    // push onto the heap
    // if heap.size > k pop it
    //
    // add what's left in the heap into the results
    //
    // return the result
  }
};
