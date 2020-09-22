#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	bool one = 0, zero = 0;
	int cnt1 = 0, cnt2 = 0;
	string str, revStr;
	
	getline(cin, str);
	revStr = str;
	reverse(revStr.begin(), revStr.end());  // Reversed String
	
	for (int i = 0; i < str.length(); i++) {
		/* Count all Zeros after first occurence of '1' */
		if (one == 0 && str[i] == '1')
			one = 1;
		else if (one == 1 && str[i] == '0') 
			cnt1++;
		
		/* Count all 1's before last occurence of zero -----> Count all 1's after first occurence of '0' in the reversed string */
		if (zero == 0 && revStr[i] == '0')
			zero = 1;
		else if (zero == 1 && revStr[i] == '1')
			cnt2++;		
	}
	
	cout << min(cnt1, cnt2);	
	
	return 0;
}