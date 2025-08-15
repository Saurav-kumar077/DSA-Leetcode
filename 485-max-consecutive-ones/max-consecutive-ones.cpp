class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int count1=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                count=count+1;
                count1=max(count1,count);
            }
            else{
                count=0;
            }
        }
        return count1;
    }
};