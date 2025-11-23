class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0;
        int sum = 0;
        int min_len = INT_MAX;
        for(int high=0;high<nums.size();high++){
            sum=sum+nums[high];
            while(sum>=target){
                int len = high-low+1;
                min_len = min(min_len,len);
                sum = sum-nums[low];
                low++;
            }
        }
        if (min_len == INT_MAX)
        return 0;
        return min_len;
    }
};