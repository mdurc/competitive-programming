class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            res = (res << 1) | (n & 1);
            n >>= 1;
        }
        return res;
    }
};

// alternative version that doesn't modify 'n' so much
uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; ++i) {
        res = (res << 1) | ((n >> i) & 1);
    }
    return res;
}

// or without shifting the result variable (OR directly in positions)
uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; ++i) {
        res |= ((n >> i) & 1) << (31 - i);
    }
    return res;
}
