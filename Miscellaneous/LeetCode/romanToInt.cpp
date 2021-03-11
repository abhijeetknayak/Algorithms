int helper_function(int& loc, string s, char next1, char next2, int first, int second, int third) {
	int result = 0;
	if ((loc + 1 < s.size()) && s[loc + 1] == next1) {
		result += first;
		loc += 1;
	}
	else if ((loc + 1 < s.size()) && s[loc + 1] == next2) {
		result += second;
		loc += 1;
	}
	else result += third;
	
	return result;
}

int romanToInt(string s) {
	int result = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'M') { result += 1000; }
		else if (s[i] == 'D') { result += 500; }
		else if (s[i] == 'C') { result += helper_function(i, s, 'D', 'M', 400, 900, 100); }		
		else if (s[i] == 'L') { result += 50; }
		else if (s[i] == 'X') { result += helper_function(i, s, 'L', 'C', 40, 90, 10); }
		else if (s[i] == 'V') { result += 5; }
		else if (s[i] == 'I') { result += helper_function(i, s, 'V', 'X', 4, 9, 1); }
	}
	
	return result;
}
