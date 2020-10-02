#include <bits/stdc++.h>

using namespace std;

bool check_balance(string s) {
	stack<char> seq;
	for (auto ch : s) {
		if (ch == '(' || ch == '[' || ch == '{')
			seq.push(ch);
		else {
			if (seq.empty())
				return false;
			else {
				char top = seq.top();
				switch(ch) {
				case '}' :

					if (top == '{')
						seq.pop();
					else
					    return false;
					break;
				case ']' :
					if (top == '[')
						seq.pop();
					else
						return false;
					break;
				case ')' :
					if (top == '(')
						seq.pop();
					else
						return false;
				}
			}
		}
	}

	if (seq.empty())
		return true;

	return false;

}

int main() {
	string s;
	cin >> s;

	cout << check_balance(s);


	return 0;
}
