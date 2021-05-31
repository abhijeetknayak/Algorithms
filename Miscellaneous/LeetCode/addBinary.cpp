void helper(string& a, string b) {
    int carry = 0, i = 0, new_val = 0;
    int l1 = a.length(), l2 = b.length();
    int j = l1 - 1;
    /* Use string a as the base*/
    for (i = l2 - 1; i >= 0; i--) {
        new_val = (a[j] - '0') + (b[i] - '0') + carry;
        if (new_val == 1) { a[j] = '1'; carry = 0; }
        if (new_val == 2) { a[j] = '0'; carry = 1; }
        if (new_val == 3) { a[j] = '1'; carry = 1; }
        j--;
    }
    while (carry != 0) {
        if (j == -1) { a.insert(a.begin(), '1'); break; }
        new_val = (a[j] - '0') + carry;
        if (new_val == 1) { a[j] = '1'; carry = 0; }
        if (new_val == 2) { a[j] = '0'; carry = 1; }
        j--;
    }
}

string addBinary(string a, string b) {
    int l1 = a.length(), l2 = b.length();
    if (l1 >= l2) {
        helper(a, b);
        return a;
    }
    else {
        helper(b, a);
        return b;
    }
    return "";
}
