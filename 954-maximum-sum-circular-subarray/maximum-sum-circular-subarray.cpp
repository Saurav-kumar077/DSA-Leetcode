class Solution {
    int minSum(vector<int>&nums){
        int bestEnding = nums[0];
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            int v1 = nums[i];
            int v2 = bestEnding+nums[i];
            bestEnding = min(v1,v2);
            ans = min(ans,bestEnding);
        }
        return ans;
    }
    int maxSum(vector<int>& nums) {
        int bestEnding = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int v1 = nums[i];
            int v2 = bestEnding + nums[i];
            bestEnding = max(v1, v2);
            ans = max(ans, bestEnding);
        }
        return ans;
    }
    int ArraySum(vector<int>&nums){
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum = sum+nums[i];
        }
        return sum;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int normalMax = maxSum(nums);
        int minSub = minSum(nums);
        int TotalSum = ArraySum(nums);

        if(normalMax<0){
          return normalMax;  
        }
        int circularMax = TotalSum - minSub;
        return max(normalMax , circularMax);
    }
};