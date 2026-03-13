#include <string>
#include <vector>
#include <iostream>

//Input: n = 4
//Output: "1211"
//Explanation:
//countAndSay(1) = "1"
//countAndSay(2) = say "1" = one 1 = "11"
//countAndSay(3) = say "11" = two 1's = "21"
//countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
//countAndSay(5) = say "1211" = one 1 + one 2 + two 1 = "111211"


class Solution {
public:
    Solution(){
        std::cout<<"8: " << countAndSay(8);
    }
    std::string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        std::string prev = countAndSay(n - 1);
        std::string result;
        
        for (size_t i = 0; i < prev.size(); ++i) {
            char current = prev[i];
            int count = 1;
            while (i + 1 < prev.size() && prev[i+1] == prev[i]) {
                ++count;
                ++i;
            }
            result += std::to_string(count) + current;
        }

        return result;
    }
};

int main() {
    Solution();
    return 0;
}
