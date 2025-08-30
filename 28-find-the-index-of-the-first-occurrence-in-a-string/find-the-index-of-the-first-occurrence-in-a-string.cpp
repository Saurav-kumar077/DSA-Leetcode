class Solution {
public:
    int strStr(string haystack, string needle) {
        while(haystack.length()>0 && haystack.find(needle)<haystack.length()){
            return haystack.find(needle);
        }
        return -1;
    }
};