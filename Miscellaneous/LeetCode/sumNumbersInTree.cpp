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
    double recursive_helper(TreeNode* root, int& cumulative_sum) {
        if (root == NULL) return 0;
        
        double multiplier_l = recursive_helper(root->left, cumulative_sum);
        double multiplier_r = recursive_helper(root->right, cumulative_sum);
        if (multiplier_l + multiplier_r == 0) {
            multiplier_l = 1;
        }
        double multiplier = (multiplier_l + multiplier_r);
        cumulative_sum += (multiplier * root->val);
        multiplier *= 10;
        
        return multiplier;        
    }
    
    int sumNumbers(TreeNode* root) {
        int cumulative_sum = 0;
        recursive_helper(root, cumulative_sum);
        return cumulative_sum;
    }
};
