class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int current_streek =0;
        int max_streek =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                current_streek++;
                if(current_streek>max_streek){
                    max_streek = current_streek;
                }
            }
            if(nums[i]!=1){
                current_streek=0;
            }
        }
        return max_streek;
    }
};