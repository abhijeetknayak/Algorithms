#include <vector>
using namespace std;

void insert(vector<int>& sort_stack, int element) {
	if (sort_stack.size() == 0 || 
			sort_stack[sort_stack.size() - 1] <= element) {
		sort_stack.push_back(element);
		return;
	}
	
	int top = sort_stack[sort_stack.size() - 1];
	sort_stack.pop_back();
	
	insert(sort_stack, element);	
	insert(sort_stack, top);	
}

void sort(vector<int>& sort_stack) {
	if (sort_stack.size() == 0) return;
	int top = sort_stack[sort_stack.size() - 1];
	sort_stack.pop_back();
	
	sort(sort_stack);
	
	insert(sort_stack, top);
}

vector<int> sortStack(vector<int> &stack) {
	sort(stack);
	
  return stack;
}
