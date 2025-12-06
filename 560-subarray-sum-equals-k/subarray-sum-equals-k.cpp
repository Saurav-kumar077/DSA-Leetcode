class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        map[0]=1; //0 already exists once
        int prefixsum=0;
        int countSubarrays = 0;

        for(int x:nums){
            prefixsum += x;

            int need = prefixsum-k;
            if(map.find(need)!=map.end()){
                countSubarrays +=map[need];
            }
            map[prefixsum]++;
        }
        return countSubarrays;

    }
};