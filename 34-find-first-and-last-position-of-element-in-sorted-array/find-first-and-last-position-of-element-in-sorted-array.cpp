class Solution {
    int Firstocc(vector<int> & nums,int target){
        int s=0;
        int e=nums.size()-1;
        int ans =-1;
        while(s<=e){
            int mid =s+(e-s)/2;
            if(nums[mid]==target){
                ans=mid;
                e=mid-1;    
            }
            else if(target>nums[mid]){
                s=mid+1;

            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
    int lastocc(vector<int> & nums, int target){
        int s=0;
        int e=nums.size()-1;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                ans=mid;
                s=mid+1;
            }
            else if(target>nums[mid]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first =Firstocc(nums ,target);
        int last =lastocc(nums,target);
        return {first,last};
        
        
    }
};