class Solution {
public:
    void backTrack(vector<int>& nums , int index , vector<int>&curr,vector<vector<int>>&ans){
        if(index ==nums.size()){
            ans.push_back(curr);
            return;
        }
        //notpick
        backTrack(nums,index+1,curr,ans);
        //pick current element
        curr.push_back(nums[index]);
        backTrack(nums,index+1,curr,ans);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>curr;
        backTrack(nums,0,curr,ans);
        return ans;
    }
};