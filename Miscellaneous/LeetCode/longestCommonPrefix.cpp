string longestCommonPrefix(vector<string>& strs) {
    int numStrings = strs.size();
    if (numStrings == 0) return "";
    if (numStrings == 1) return strs[0];

    int index = 0;
    bool bLoop = true;
    while (bLoop) {
        for (int i = 0; i < numStrings - 1; i++) {
            if ((index < strs[i].size())
                    && (index < strs[i + 1].size()))
            {
                if (strs[i][index] != strs[i + 1][index]) {
                    bLoop = false;
                    if (index == 0) index = -1;
                }
            }
            else bLoop = false;
        }
        if (bLoop == true) index++;
        else if (index == 0) index = -1;
    }

    if (index == -1) return "";
    else return strs[0].substr(0, index);
}
