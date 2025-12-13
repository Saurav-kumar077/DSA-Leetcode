class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        int sum =0;
        int min_len = INT_MAX;

        for(int right = 0; right<n;right++){
            sum +=nums[right];
            while(sum>=target){
                int len = right - left +1;
                min_len = min(min_len,len);
                sum = sum - nums[left];
                left++;
            }
        }
        if(min_len == INT_MAX){
            return 0;
        }
        return min_len;
    }
};