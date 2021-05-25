#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
};

vector<int> recursive_call(BinaryTree * root) {
	int max_cumulative_sub_branch = INT_MIN, mst = INT_MIN, msb = INT_MIN, rmps = INT_MIN;
	vector<int> left_sub;
	vector<int> right_sub;
	
	if (root == NULL) return vector<int> {0, INT_MIN};
	
	left_sub = recursive_call(root->left);
	right_sub = recursive_call(root->right);
	
	max_cumulative_sub_branch = max(left_sub[0], right_sub[0]);
	msb = max(max_cumulative_sub_branch + root->value, root->value);
	mst = max(msb, left_sub[0] + root->value + right_sub[0]);
	rmps = max(left_sub[1], right_sub[1]);
	rmps = max(rmps, mst);
	
	return vector<int> {msb, rmps};
}

int maxPathSum(BinaryTree tree) {
	vector<int> result = recursive_call(&tree);
	cout << result[0] << " " << result[1] << endl; 
  return result[1];
}
