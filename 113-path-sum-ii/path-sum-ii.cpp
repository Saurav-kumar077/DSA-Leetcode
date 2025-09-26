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
    void dfs(TreeNode* root , int CurrSum , int targetSum , vector<int>path_sum){
        if(root==NULL){
            return;
        }
        path_sum.push_back(root->val);
        CurrSum += root->val;

        if(root->left==NULL && root->right==NULL && CurrSum ==targetSum){
            result.push_back(path_sum);
        }
        dfs(root->left ,CurrSum,targetSum,path_sum);
        dfs(root->right ,CurrSum,targetSum,path_sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path_sum ; 
        dfs(root , 0 , targetSum , path_sum);
        return result;
    }
};