class Solution {
public:
    bool isAnagram(string s, string t) {
        int letter_frequency[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

        for (int i = 0; i < s.length(); i++) {
            letter_frequency[s[i] - 'a']++;
        }

        for (int i = 0; i < t.length(); i++) {
            letter_frequency[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (letter_frequency[i] != 0) {
                return false;
            }
        }

        return true;
    }
};

