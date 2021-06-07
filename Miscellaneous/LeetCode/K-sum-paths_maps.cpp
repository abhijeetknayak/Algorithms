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
    void recursive_helper(TreeNode * root,
                          int targetSum, int& prev,
                          int& result, unordered_map<int, int>& dp) {
        if (root == NULL) return;
        
        /* Add new entries in dict */
        prev += root->val;
        dp[prev]++;
        
        if (dp.find(prev - targetSum) != dp.end()) {
            result += dp[prev - targetSum];
            if (targetSum == 0) result -= 1;
        }
        
        recursive_helper(root->left, targetSum, prev, result, dp);
        recursive_helper(root->right, targetSum, prev, result, dp);
        
        /* Remove entries from dict */
        dp[prev]--;
        prev -= root->val;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int, int> dp;
        dp[0] = 1;
        int prev = 0, result = 0;
        recursive_helper(root, targetSum, prev, result, dp);
        
        return result;
    }
};
