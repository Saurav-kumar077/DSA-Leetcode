class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty() || s.empty()) return res;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        if (s.size() < totalLen) return res;

        unordered_map<string, int> freq;
        for (auto &w : words) freq[w]++;

        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset, count = 0;
            unordered_map<string, int> window;

            for (int right = offset; right + wordLen <= (int)s.size(); right += wordLen) {
                string w = s.substr(right, wordLen);
                if (freq.find(w) != freq.end()) {
                    window[w]++;
                    count++;

                    while (window[w] > freq[w]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == wordCount) {
                        res.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return res;
    }
};
