class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestEnding = nums[0];
        int ans = nums[0];
        for(int i =1;i<nums.size();i++){
            int val1 = bestEnding+nums[i];
            int val2 = nums[i];
            bestEnding = max(val1 , val2);
            ans = max(ans,bestEnding);
        }
        return ans;
    }
};