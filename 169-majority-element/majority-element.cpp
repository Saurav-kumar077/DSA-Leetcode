class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>count;
        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }
        int majorityelement = 0;
        for(auto&pair:count){
            if(pair.second>n/2){
                majorityelement = pair.first;
                
            }
        }
        return majorityelement;
    }
};