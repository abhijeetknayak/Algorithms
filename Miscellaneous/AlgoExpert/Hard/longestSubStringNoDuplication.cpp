using namespace std;

string longestSubstringWithoutDuplication(string str) {
	unordered_map<char, int> table;
	vector<int> longestIdx{0, 1};
	int start_idx = 0;
	for (int i = 0; i < str.size(); i++) {
		if (table.find(str[i]) != table.end()) {
			start_idx = max(start_idx, table[str[i]] + 1);
		}
		if (i - start_idx > longestIdx[1] - longestIdx[0]) {
			longestIdx = {start_idx, i};
		}			
		table[str[i]] = i;		
	}
	string result = str.substr(longestIdx[0], longestIdx[1] - longestIdx[0] + 1);
  return result;
}
