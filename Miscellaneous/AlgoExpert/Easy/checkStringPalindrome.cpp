using namespace std;

bool isPalindrome(string str) {
	bool ret = false;
	int left = 0, right = str.length() - 1;
	if (left == right) return true;
	while(left < right) {
		if (str[left] == str[right]) {
			left++; right--;
			ret = true;
		}
		else {
			ret = false;
			break;
		}
	}	
	return ret;
}
