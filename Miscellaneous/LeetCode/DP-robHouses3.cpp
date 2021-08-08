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
    vector<int> recursive_helper(TreeNode * root) { 
        vector<int> retVal {0, 0};
        if (root == NULL) return retVal;
        
        vector<int> leftSubTree = recursive_helper(root->left);
        vector<int> rightSubTree = recursive_helper(root->right);
        
        retVal[0] = leftSubTree[1] + rightSubTree[1] + root->val;
        retVal[1] = max(leftSubTree[0], leftSubTree[1]) +
            max(rightSubTree[0], rightSubTree[1]);
        
        return retVal;        
    }
    
    int rob(TreeNode* root) {
        vector<int> result = recursive_helper(root);
        return max(result[0], result[1]);
    }
};
