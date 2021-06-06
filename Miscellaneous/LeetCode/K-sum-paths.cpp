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
    void recursion_helper(TreeNode * root, int targetSum, vector<int> array,
                         int& count) {
        if (root == NULL) return;
        
        array.push_back(root->val);
        
        recursion_helper(root->left, targetSum, array, count);
        recursion_helper(root->right, targetSum, array, count);
        
        int value = 0;
        for (int i = array.size() - 1; i >= 0; i--) {
            value += array[i];
            if (value == targetSum) count++;
        }
        
        array.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> array;
        int count = 0;
        recursion_helper(root, targetSum, array, count);
        
        return count;
    }
};
