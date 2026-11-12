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
    void inorder(vector<int>&ans,struct TreeNode*temp){
        //base case
        if(temp==nullptr){
            return;
        }
        inorder(ans,temp->left);
        ans.push_back(temp->val);
        inorder(ans,temp->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder(ans,root);
        return ans;
    }
};