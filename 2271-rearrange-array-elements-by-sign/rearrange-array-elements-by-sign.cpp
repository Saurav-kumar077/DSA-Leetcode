class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n,0);
        int ps_index = 0;
        int ng_index = 1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                result[ps_index]=nums[i];
                ps_index +=2;
            }
            else{
                result[ng_index]=nums[i];
                ng_index +=2;
            }
        }
        return result;
    }
};