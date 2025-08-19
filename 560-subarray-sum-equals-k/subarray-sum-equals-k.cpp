class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count =0;
        
        for(int i=0;i<n;i++){
            int current_sum=0;
            for(int j=i;j<n;j++){
                current_sum +=nums[j];
                if(current_sum==k){
                    count++;
                }
            }
        }
        return count;
    }
};