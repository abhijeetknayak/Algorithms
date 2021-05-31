class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        string result(len1 + len2, '0');
        if (num1 == "0" || num2 == "0") return "0";

        int j = len2 - 1;
        int k = len1 + len2;
        while (j >= 0) {
            int update_pos = k - 1;
            int carry = 0;
            for (int i = len1 - 1; i >= 0; i--) {
                int prod = (num1[i] - '0') * (num2[j] - '0');
                int new_sum = prod + (result[update_pos] - '0') + carry;
                result[update_pos] = '0' + (new_sum % 10);
                carry = new_sum / 10;
                update_pos--;
            }
            if (carry != 0) {
                result[update_pos] = '0' + ((result[update_pos] - '0') + carry);
            }
            k--;
            j--;
        }
        result.erase(0, result.find_first_not_of('0'));
        return result;
    }
};
