class Solution {
public:
    int getSum(int a, int b) {
        // a xor b, then 'a AND b' with a bitshift left,
        // then repeat this process until 'a AND b' is zero
        int carry;
        while(b != 0){
            carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }
};
