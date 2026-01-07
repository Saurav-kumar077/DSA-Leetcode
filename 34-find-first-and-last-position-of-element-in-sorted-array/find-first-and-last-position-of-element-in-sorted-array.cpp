class Solution {
    int FirstOcc(vector<int>& nums , int target){
        int low = 0;
        int high = nums.size()-1;
        int first_occ = -1;

        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                first_occ = mid;
                high = mid-1;
            }
            else if(nums[mid]>target){
                high = mid-1;
            }else{
                low= mid+1;
            }
        }
        return first_occ;
    }
       int LastOcc(vector<int>& nums , int target){
        int low = 0;
        int high = nums.size()-1;
        int last_occ = -1;

        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                last_occ = mid;
                low = mid+1;
            }
            if(nums[mid]>target){
                high = mid-1;
            }else{
                low= mid+1;
            }
        }
        return last_occ;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = FirstOcc(nums,target);
        int last = LastOcc(nums,target);
        return {first,last};
    }
};