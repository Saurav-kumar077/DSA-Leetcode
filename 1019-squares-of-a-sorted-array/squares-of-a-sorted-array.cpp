class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        int left = 0;
        int right=n-1;
        int idx = n-1;
        while(left<=right){
            int leftsq = nums[left]*nums[left];
            int rightsq = nums[right]*nums[right];

            if(leftsq>rightsq){
                res[idx]=leftsq;
                left++;

            }else{
                res[idx]=rightsq;
                right--;
            }
            idx--;
        }
        return res;
    }
};