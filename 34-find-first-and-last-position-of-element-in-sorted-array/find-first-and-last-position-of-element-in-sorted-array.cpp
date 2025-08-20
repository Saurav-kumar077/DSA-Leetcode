class Solution {
    private:
    int findFirst(vector<int>& nums, int target){
        int n=nums.size();
        int st = 0;
        int end=n-1;
        int first_pos = -1;

        while(st<=end){
            int mid = st+(end-st)/2;
            if(nums[mid]==target){
                first_pos =mid;
                end=mid-1;
            }
            else if (nums[mid]<target){
                st=mid+1;
            }
            else{
                end =mid-1;
            }
        }
        return first_pos;
    }
    int findLast(vector<int>& nums, int target){
        int n=nums.size();
        int st=0;
        int end=n-1;
        int last_pos = -1;
        while (st<=end){
            int mid = st+(end-st)/2;
            if(nums[mid]==target){
                last_pos=mid;
                st=mid+1;
            }
            else if(nums[mid]<target){
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return last_pos;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=findFirst(nums,target);
        if(first==-1){
            return {-1,-1};
        }
        int last = findLast(nums,target);
        return {first , last};
    }
};