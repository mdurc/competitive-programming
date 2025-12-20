// Optimal solution where we don't have to search through the map to check
// if every window is an anagram of s1. Instead, we keep a running count of
// the total number of matches between two "maps" of the 26 letters of the alphabet
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        // vectors are serving essentially as a map, character is each index
        vector<int> m1(26,0);
        vector<int> m2(26,0);
        for(int i=0; i<s1.size(); ++i){
            ++m1[s1[i] - 'a'];
            ++m2[s2[i] - 'a'];
        }

        int matches = 0;
        for(int i=0; i<26; ++i){
            matches += m1[i] == m2[i];
        }

        int i = 0;
        int j = s1.size();
        while (j < s2.size()){
            if (matches == 26) return true;

            // move window to the right
            int index = s2[j] - 'a';
            ++m2[index]; // note that j starts outside of the window of s1 chars
            if (m1[index] == m2[index]){
                // we just made them equal each other
                ++matches;
            }else if (m1[index]+1 == m2[index]){
                // we just made them no longer equal each other
                --matches;
            }

            // same thing but with the left pointer at the start of the window
            index = s2[i] - 'a';
            --m2[index];
            if (m1[index] == m2[index]){
                ++matches;
            }else if (m1[index]-1 == m2[index]){
                --matches;
            }

            ++i;
            ++j;
        }
        return matches == 26;
    }
};


// Version one, with looping through map to check for anagram
// A lot more intuitive than the other solution
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        // checking anagrams in sliding window
        int i, j;
        unordered_map<char, int> m1, m2;
        for (i =0; i<s1.size(); ++i){
            ++m1[s1[i]];
            ++m2[s2[i]];
        }

        // hashmap of first s1.size()-1 characters
        // then just move that hashmap as a window
        i = 0;
        j = s1.size()-1;
        while (j < s2.size()){
            unordered_map<char, int>::iterator itr;
            for (itr = m1.begin(); itr != m1.end(); ++itr){
                if (itr->second != m2[itr->first]){
                    // not anagram
                    --m2[s2[i]]; // decrement char we are leaving
                    ++i;
                    ++j;
                    ++m2[s2[j]]; // increment char we are adding
                    break;
                }
            }
            if (itr == m1.end()){ // if we never used 'break'
                return true;
            }
        }
        return false;
    }
};
