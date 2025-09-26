/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root , int targetSum ,vector<vector<int>>&result,vector<int>&path_Sum ){
        if(root==NULL){
            return;
        }
        path_Sum.push_back(root->val);

        if(root->left==NULL && root->right==NULL && targetSum==root->val){
            result.push_back(path_Sum);
        }
        dfs(root->left , targetSum-root->val , result , path_Sum);
        dfs(root->right , targetSum-root->val , result , path_Sum);

        path_Sum.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>result;
        vector<int>path_Sum;
        dfs(root , targetSum , result , path_Sum);
        return result;
    }
};