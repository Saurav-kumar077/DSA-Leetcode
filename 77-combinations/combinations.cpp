class Solution {
public:
    void backTrack(int start , int n,int k,vector<int>&curr,vector<vector<int>>&ans){
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }
        for(int i= start ;i<=n;i++){
            curr.push_back(i);
            backTrack(i+1,n,k,curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>curr;
        backTrack(1,n,k,curr,ans);
        return ans;
    }
};