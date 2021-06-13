using namespace std;

int firstNonRepeatingCharacter(string string) {
	map<char, int> alphabet;
	
	for (int i = 0; i < string.size(); i++) {
		alphabet[string[i]] += 1;
	}
	
	for (int i = 0; i < string.size(); i++) {
		if (alphabet[string[i]] == 1) return i; 
	}
	
  return -1;
}
