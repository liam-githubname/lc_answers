import collections
import typing

class Solution:

  # This algorithm is o(m*n*log(n)) and a space complexity of o(m*n)
    def groupAnagrams(self, strs: typing.List[str]) -> typing.List[typing.List[str]]:
        my_dict = collections.defaultdict(list);

        # This is the m part of the length
        for str in strs:
            # This should technically multply by n but that is considered a constant in notation and dropped
            sortedStr = "".join(sorted(str))
            # Python's sorted() uses Timsort which is O(nlogn)
            my_dict[sortedStr].append(str)

        # Thus the overall time complexity is O(m * nlogn)
        return list(my_dict.values())
