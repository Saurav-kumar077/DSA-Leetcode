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
    int dfs(TreeNode*node , int CurrSum){
        if(node==NULL){
            return 0 ;
        }
        CurrSum = CurrSum *10 + node->val;
        if(node->left ==NULL && node->right==NULL){
            return CurrSum;
        }
        return dfs(node->left , CurrSum) + dfs(node->right , CurrSum);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};