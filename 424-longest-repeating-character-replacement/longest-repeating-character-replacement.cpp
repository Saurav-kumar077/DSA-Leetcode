class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int left = 0;
        int maxLength = 0;
        int maxFreq =0;

        vector<int>charCounts(26,0);
        for(int right = 0; right <n ; right++){
            charCounts[s[right]-'A']++;
            maxFreq = max(maxFreq , charCounts[s[right]-'A']);

            while((right - left +1)-maxFreq >k){
                charCounts[s[left]-'A']--;
                left++;
            }
            maxLength = max(maxLength , right - left +1 );
        }
        return maxLength;
        
        
    }
};