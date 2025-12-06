#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        mp[0] = 1;

        int prefixSum = 0;     
        int countSub = 0;

        for(int i = 0; i < nums.size(); i++){
            prefixSum = prefixSum + nums[i];   
       
            int need = prefixSum - k;

            if(mp.find(need) != mp.end()){
                countSub = countSub + mp[need];
            }

            mp[prefixSum]++;
        }

        return countSub;
    }
};
