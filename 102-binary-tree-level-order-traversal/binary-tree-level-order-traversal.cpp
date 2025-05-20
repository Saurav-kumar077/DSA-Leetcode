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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        levelorder(root,result);
        return result;
        
    }
    private:
    void levelorder(TreeNode* root,vector<vector<int>>&result){
        if(root==nullptr){
            return;
        }
        queue<TreeNode*>q;
        q.push(root);
        

        while(!q.empty()){
            int size=q.size();
            vector<int>level;
            for(int i=0;i<size;i++){
                TreeNode* num=q.front();
                q.pop();

                level.push_back(num->val);

                if(num->left){
                    q.push(num->left);
                }
                if(num->right){
                    q.push(num->right);
                }
            }
            result.push_back(level);
        }

    }
};