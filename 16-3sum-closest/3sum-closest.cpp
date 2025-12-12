class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int res = nums[0]+nums[1]+nums[2];
        int bestDiff = abs(res - target);

        for(int i=0;i<n;i++){
            int left= i+1;
            int right = n-1;
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                int diff = abs(sum - target);
                if(diff<bestDiff){
                    bestDiff = diff;
                    res = sum;
                }
                if(sum == target){
                    left++;
                    right--;
                }
                else if(sum>target){
                    right--;
                }else{
                    left++;
                }
            }
        }
        return res;
    }
};