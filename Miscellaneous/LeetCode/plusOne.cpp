class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int new_val = digits[len - 1] + 1;
        digits[len - 1] = new_val % 10;
        int carry = new_val / 10;
        if (carry != 0) {
            for (int i = digits.size() - 2; i >= 0; i--) {
                if (carry == 0) break;
                new_val = digits[i] + carry;
                digits[i] = new_val % 10;
                carry = new_val / 10;
            }
        }
        if (carry != 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
