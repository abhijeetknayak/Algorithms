#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool checkPermutation(string str1, string str2) {
	unordered_map<char, int> table;
	for (auto ch : str1) {
		table[ch] += 1;
	}

	for (auto ch : str2) {
		if (table.find(ch) != table.end()) {
			table[ch]--;
			if (table[ch] == 0) table.erase(ch);
		}
		else return false;
	}

	if (table.empty()) return true;
	else return false;
}

int main() {
	/* Should this be Case sensitive? */
	cout << checkPermutation("Abhijeet", "teejibha") << endl;

	return 0;
}
