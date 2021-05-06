using namespace std;

void addToResult(string& result, char current, int count) {
	while (count > 9) {
		result.push_back(char('0' + 9));
		result.push_back(current);
		count -= 9;
	}
	result.push_back(char('0' + count));
	result.push_back(current);
}

string runLengthEncoding(string str) {
	string result;
	char current = str[0];
	int count = 1;
	
	for(int i = 1; i < str.length(); i++) {
		if (str[i] == current) {
			count++;
		}
		else {
			addToResult(result, current, count);
			current = str[i];
			count = 1;
		}
	}
	(void) addToResult(result, current, count);
	
  return result;
}
