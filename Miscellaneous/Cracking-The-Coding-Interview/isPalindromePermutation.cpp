#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isPalindrome(string str) {
	unordered_map<char, int> table;
	for (auto ch : str) {
		if (ch == ' ') continue;

		ch = tolower(ch);
		if (table.find(ch) != table.end()) table.erase(ch);
		else table[ch] += 1;
	}

	if (table.empty() || (table.size() == 1 && table.begin()->second % 2 != 0)) return true;
	else return false;
}

int main() {
	cout << isPalindrome("tact oca") << endl;

	return 0;
}
