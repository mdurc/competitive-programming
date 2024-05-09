
#include <iostream>
#include <string>
#include <vector>


class Solution {
public:
    Solution(){
        std::cout<<lengthOfLongestSubstring("dvdf")<<'\n';
    }
    int lengthOfLongestSubstring(std::string s) {
        if (s.length()==0){
            return 0;
        }
        std::vector<int> maxes{};
        int start{};
        int length{1};
        int i{};
        /* while loop goes through each substring until it finds a character
         * that already exists in the substring and then adds the length to
         * the vector of lengths.
         *
         * length starts at one for each start of a new substring search
         * increments until the next char is one that already exists.
         * Then add the current length to the vector of lengths.
         * Reset the length of the next substring to 1. Change the start
         * variable to the next starting location of the next substring.
         * (increments the starting location with ++start)
         */
        while (i<s.length()-1){
            if (found(s.substr(start, length), s[i+1])){
                maxes.push_back(length);
                length = 1;
                i = ++start;
            }else{
                length+=1;
                i++;
            }
        }
        maxes.push_back(length); // the end final case to push.
        int max{};
        for (int val : maxes){
            if (val>max){
                max=val;
            }
        }
        if (max==0){        //if there are no duplicate chars in the string
            max = s.length();
        }

        return max;
    }

    bool found(std::string str, char c){
        for (char v : str){
            if (v==c){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution();
    return 0;
}
