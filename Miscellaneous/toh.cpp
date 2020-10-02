#include <bits/stdc++.h>

using namespace std;

void move_k(stack<int> * a, stack<int> * b) {
	int aTop = -1, bTop = -1;

	if (!a->empty()) { aTop = a->top(); }
	if (!b->empty()) { bTop = b->top(); }

	if (a->empty() && !b->empty()) {
		a->push(bTop);
		b->pop();
	}
	else if (!a->empty() && b->empty()) {
		b->push(aTop);
		a->pop();
	}
	else if (aTop > bTop) {
		a->push(bTop);
		b->pop();
	}
	else if (aTop < bTop) {
		b->push(aTop);
		a->pop();
	}
	else { /* Do nothing */ }
}

void print_tower_content(stack<int> s) {
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

int main() {
	stack<int> source, aux, dest;
	int n = 0, num_moves = 0;  // Number of disks

	cin >> n;

	num_moves = pow(2, n) - 1;
	for (int i = n; i > 0; i--) {
		source.push(i);
	}

	cout << "S" << " ";
	print_tower_content(source);

	cout << "A" << " ";
	print_tower_content(aux);

	cout << "D" << " ";
	print_tower_content(dest);

	for (int i = 1; i <= num_moves; i++) {
		if (i % 3 == 1) /* Move disk from Source to Destination */
			move_k(&source, &dest);
		else if (i % 3 == 2)  /* Move disk from source to aux */
			move_k(&source, &aux);
		else  /* Move disk from aux to dest */
			move_k(&aux, &dest);

		cout << "S" << " ";
		print_tower_content(source);

		cout << "A" << " ";
		print_tower_content(aux);

		cout << "D" << " ";
		print_tower_content(dest);

		cout << endl;
	}

	if (n % 2 == 0) /* Even number of disks, print aux instead */
		print_tower_content(aux);
	else
		print_tower_content(dest);
	
	return 0;
}
