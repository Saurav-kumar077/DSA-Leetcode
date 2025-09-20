class Solution {
public:
    void backTrack(vector<int>& candidates ,int target, int start ,vector<int>&combination,vector<vector<int>>&result){
        if(target==0){
            result.push_back(combination);
            return;
        }
        if(target<0){
            return;
        }
        for(int i=start;i<candidates.size();i++){
            combination.push_back(candidates[i]);
            backTrack(candidates ,target - candidates[i],i,combination,result);
            combination.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>combination;
        vector<vector<int>>result;
        backTrack(candidates ,target , 0, combination,result );
        return result;
    }
};