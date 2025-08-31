class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m=t.length();
        if( n != m){
            return false;
        }
        vector<int>charCount(26,0);
        for(char ch :s){
            charCount[ch-'a']++;
        }
        for (char c :t){
            charCount[c-'a']--;
        }
        for(int count :charCount){
            if(count !=0){
                return false;
            }
        }
        return true;

    }
};