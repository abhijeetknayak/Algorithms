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
    bool recursive_helper(TreeNode* root, int current_sum, int targetSum) {
        bool retVal = false;
        if (root == NULL) return false;
        current_sum += root->val;
        if (root->left == NULL && root->right == NULL) {
            if (current_sum == targetSum) return true;
        }
        
        if (root->left != NULL) {
            retVal = recursive_helper(root->left, current_sum, targetSum);
        }
        
        if (root->right != NULL) {
            retVal = retVal | recursive_helper(root->right, current_sum, targetSum);
        }      
        
        return retVal;
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int cur_sum = 0;
        return recursive_helper(root, cur_sum, targetSum);
    }
};
