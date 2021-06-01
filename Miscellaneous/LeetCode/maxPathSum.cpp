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
    vector<int> recursive_helper(TreeNode* root) {
        if (root == NULL) return vector<int> {0, INT_MIN};
        vector<int> leftTree{0, INT_MIN}, rightTree{0, INT_MIN};
        
        leftTree = recursive_helper(root->left);
        rightTree = recursive_helper(root->right);
        
        int max_branch_sum = max(leftTree[0], rightTree[0]);
        int max_branch_cumulative_sum = max(max_branch_sum + root->val, root->val);
        int max_sum_incl_root = max(leftTree[1], leftTree[0] + root->val + rightTree[0]);
        max_sum_incl_root = max(max_sum_incl_root, rightTree[1]);
        int max_running_sum = max(max_branch_cumulative_sum, max_sum_incl_root);
        return vector<int> {max_branch_cumulative_sum, max_running_sum};       
    }
    
    int maxPathSum(TreeNode* root) {
        vector<int> result = recursive_helper(root);
        return result[1];
    }
};
