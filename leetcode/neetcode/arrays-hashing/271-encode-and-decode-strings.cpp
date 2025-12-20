
// Encoding with integer value in each string encoding added
class Solution {
public:
    string encode(vector<string>& strs) {
        string ans;
        for (const string& s: strs){
            ans += to_string(s.size()) + "#" + s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        int j;
        while (i < s.size()){
            // move to the first #, past the length encoding
            for (j=i; s[j] != '#'; ++j);

            int length = stoi(s.substr(i, j-i));
            i = j+1; // start of string encoding
            j = i+length;
            ans.push_back(s.substr(i, length));
            i = j;
        }
        return ans;
    }
};




// Using '#' as a delimeter (doesn't work when string can include '#')
class Solution {
public:
    string encode(vector<string>& strs) {
        string ans;
        for (const string& s: strs){
            ans += s + "#";
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int hash = s.find('#');
        int index = 0;
        while (hash != std::string::npos){
            ans.push_back(s.substr(index, hash-index));
            index = hash+1;
            hash = s.find('#', index);
        }
        return ans;
    }
};
