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
    vector<vector<int>>result;
    vector<int>path;
    void dfs(TreeNode* root , int targetSum ,int currSum){
        if(root==NULL){
            return;
        }
        path.push_back(root->val);
        currSum += root->val;
        if(root->left ==NULL && root->right ==NULL && currSum ==targetSum){
            result.push_back(path);
        }
        dfs(root->left , targetSum , currSum);
        dfs(root->right , targetSum , currSum);

        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root , targetSum , 0);
        return result;
    }
};