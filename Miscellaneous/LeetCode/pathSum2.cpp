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
    void recursion_helper(TreeNode* root, int cur_val, int target, vector<int> cur_nums, vector<vector<int>>& result) {
        if (root == NULL) return;
        cur_val += root->val;
        cur_nums.push_back(root->val);
        if (root->left == NULL && root ->right == NULL) {
            if (cur_val == target) {
                result.push_back(cur_nums);
                return;
            }
        }       
        
        recursion_helper(root->left, cur_val, target, cur_nums, result);
        recursion_helper(root->right, cur_val, target, cur_nums, result);        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int cur_val = 0;
        vector<int> cur_nums;
        vector<vector<int>> result;
        
        recursion_helper(root, cur_val, targetSum, cur_nums, result);
        
        return result;
    }
};
