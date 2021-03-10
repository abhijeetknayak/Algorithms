string convert(string s, int numRows) {
	string res = "";
	int len = s.size();
    int start = 0;
    int first = (numRows - 1) * 2;
    int second = 0;

    if (numRows == 1) { return s; }

    for (int i = 0; i < numRows; i++) {
    	start = i;
    	while (start < len) {
    		res += s[start];

    		start += first;
    		if (first == 0) {
    			start += second;
    		}
    		if (start < len) {
    			res += s[start];

    			start += second;
    			if (second == 0) {
    				start += first;
    			}
    		}
    	}
    	first -= 2;
    	second += 2;
    }

    return res;
}
