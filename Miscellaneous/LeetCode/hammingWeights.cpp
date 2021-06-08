class Solution {
public:
    void generate_ones(unordered_map<int, int>& ones) {
        ones[0] = 0;
        for (int i = 1; i < 16; i++) {
            if (i % 2 == 0) ones[i] = ones[i / 2];
            else ones[i] = ones[i - 1] + 1;
        }
    }
    
    int hammingWeight_maps(uint32_t n) {
        unordered_map<int, int> ones;
        generate_ones(ones);
        int temp = 0, count = 0;
        while(n > 0) {
            temp = n & 0x0000000F;
            cout << temp;
            count += ones[temp];
            n = n >> 4;
        }
        return count;        
    }
    
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n > 0) {
            count++;
            n = n & (n - 1);
        }
        return count;
    }
};
