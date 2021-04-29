#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isUnique(string str) {
	unordered_map<char, bool> table;

	for (auto ch : str) {
		if (table.find(ch) != table.end()) return false;
		else table[ch] = true;
	}

	return true;
}

/* Without Additional Data structures --> Time Complexity O(N * N) */
bool isUniqueNew(string str) {
	int n = str.length();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (str[i] == str[j]) return false;
		}
	}
	return true;
}

int main() {
	cout << isUnique("HelhoWrd") << endl;
	return 0;
}
