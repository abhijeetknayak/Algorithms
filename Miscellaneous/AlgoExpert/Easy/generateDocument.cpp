using namespace std;

bool generateDocument(string characters, string document) {
	map<char, int> dict;
	for (int i = 0; i < characters.size(); i++) {
		dict[characters[i]] += 1;
	}
	
	for (int i = 0; i < document.size(); i++) {
		if (dict[document[i]] == 0) return false;
		else dict[document[i]]--;
	}
	
  return true;
}
