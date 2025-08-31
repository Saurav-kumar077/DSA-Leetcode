class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0){
            return  0;
        }
        int left = 0;
        int maxLength = 0;
        unordered_set<char>charSet;
        for(int right = 0; right < n ;right++){
            while(charSet.count(s[right])){
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
            maxLength = max(maxLength , right-left+1);
        }
        return maxLength;
    }
};