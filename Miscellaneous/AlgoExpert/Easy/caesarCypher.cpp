using namespace std;

string caesarCypherEncryptor(string str, int key) {
	string res;
	for (auto ch : str) {
		int c = ch - 'a';
		c = (c + key) % 26;
		res.push_back(char('a' + c));
	}
  return res;
}
