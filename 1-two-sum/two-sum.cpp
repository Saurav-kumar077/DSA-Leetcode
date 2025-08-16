class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>sum;
        for(int i=0;i<n;i++){
            int compliment = target-nums[i];

            if(sum.count(compliment)){
                return{sum[compliment],i};
            }
            sum[nums[i]]=i;
        }
        return {};
    }
};