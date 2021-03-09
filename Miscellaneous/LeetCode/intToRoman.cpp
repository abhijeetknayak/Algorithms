string intToRoman(int num) {
	string thousands[10] = {"", "M", "MM", "MMM", "", "", "", "", "", ""};
	string hundreds[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
	string tens[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
	string ones[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
	string res = "";

	int n = 1000;

	while (n >= 1) {
		// Start with thousands digit
		int k = num / n;
		if (k > 0) {
			if ((n == 1000) && (k <= 3)) { res.append(thousands[k]); }
			else if (n == 100) { res.append(hundreds[k]); }
			else if (n == 10) { res.append(tens[k]); }
			else { res.append(ones[k]); }
		}

		num -= k * n;
		n /= 10;
	}

	cout << res;

	return res;
}
