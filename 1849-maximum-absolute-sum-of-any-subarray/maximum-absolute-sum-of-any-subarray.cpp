class Solution {
    int maxSum(vector<int>&nums){
        int bestEnding = nums[0];
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            int v1 = bestEnding + nums[i];
            int v2 =nums[i];
            bestEnding = max(v1 , v2);
            ans = max(ans,bestEnding);
        }
        return ans;
    }
    int minSum(vector<int>& nums){
        int bestEnding = nums[0];
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            int v1 = bestEnding+nums[i];
            int v2 = nums[i];
            bestEnding = min(v1 , v2);
            ans = min(ans , bestEnding);
        }
        return ans;
    }
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int pos = maxSum(nums);
        int neg = minSum(nums);
        return max(abs(pos),abs(neg));
    }
    
};