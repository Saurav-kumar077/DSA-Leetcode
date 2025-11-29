class Solution {
public:
    int characterReplacement(string s, int k) {
        int n= s.size();
        vector<int>f(26,0);
        int low=0;
        int maxCnt = 0;
        int res=0;
        for(int high = 0; high<n; high++){
            int idxHigh = s[high]-'A';
            f[idxHigh]++;
            maxCnt = max(maxCnt,f[idxHigh]);
            int len = high-low+1;
            int diff = len-maxCnt;

            while(diff>k){
                int idxLow = s[low]-'A';
                f[idxLow]--;
                low++;
                len = high-low+1;
                diff = len-maxCnt;
            }
            res = max(res,len);
        }
        return res;
    }
};