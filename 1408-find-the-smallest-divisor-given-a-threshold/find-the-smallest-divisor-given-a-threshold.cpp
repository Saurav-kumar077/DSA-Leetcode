class Solution {
public:
    long long calculateSum(vector<int>& nums, int divisor){
        long long totalSum = 0;
        for(int num:nums){
            totalSum+=(num+ divisor-1)/divisor;
        }
        return totalSum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int st = 1;
        int end = *std::max_element(nums.begin(),nums.end());
        int result = end ; 
        while(st<=end){
            int mid = st+(end-st)/2;
            long long currentSum = calculateSum(nums,mid);
            if(currentSum<=threshold){
                result=mid;
                end =mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return result;
    }
};