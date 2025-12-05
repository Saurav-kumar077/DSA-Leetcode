class Solution {
    int TotalSum(vector<int>&nums){
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }
        return sum;
    }
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int ArraySum = TotalSum(nums);
        for(int i=0;i<nums.size();i++){
            int right = ArraySum - nums[i]-left;

            if(left==right){
                return i;
            }
            left = left+nums[i];
        }
        return -1;
    }
};