class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        if (t.size() > n) return "";

        unordered_map<char,int> mp;
        for (char ch : t) {
            mp[ch]++;
        }

        int requiredCount = t.size();
        int i = 0, j = 0;
        int windowSize = INT_MAX;
        int start = 0;

        while (j < n) {
            char ch = s[j];

            mp[ch]--;
            if (mp[ch] >= 0) {
                requiredCount--;
            }

            while (requiredCount == 0) {
                int currWindowSize = j - i + 1;
                if (windowSize > currWindowSize) {
                    windowSize = currWindowSize;
                    start = i;
                }

                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    requiredCount++;
                }
                i++;
            }

            j++;
        }

        return windowSize == INT_MAX ? "" : s.substr(start, windowSize);
    }
};
