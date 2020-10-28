#include <bits/stdc++.h>

using namespace std;

bool isValid(string s) {
	stack<char> st;
	char c = ' ';
	for (auto ch : s) {
		if (ch == '(' || ch == '[' || ch == '{')
			st.push(ch);
		else {
			/* Must be the ending characters */
			switch(ch) {
			case ']':
				c = st.top();
				st.pop();

				if (c != '[')
					return false;
			break;

			case '}':
				c = st.top();
				st.pop();

				if (c != '{')
					return false;
			break;

			case ')':
				c = st.top();
				st.pop();

				if (c != '(')
					return false;
			break;
			}
		}
	}

	if (!st.empty())
		return false;

	return true;
}

int main() {
	string s = "[{[[]]}";
	cout << isValid(s);

	return 0;
}
