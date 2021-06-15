using namespace std;

string reverseWordsInString(string str) {
	vector<string> words;
	string temp = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			if (temp != "") {
				words.push_back(temp);
				temp = "";
			}			
			
			string k = "";
			k += str[i];
			words.push_back(k);
		}
		else {
			temp += str[i];
		}
	}
	
	if (temp != "") {
		words.push_back(temp);
		temp = "";
	}
	
	for (int i = words.size() - 1; i >= 0; i--) {
		temp += words[i];
	}
  return temp;
}
