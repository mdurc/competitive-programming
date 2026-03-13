class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0; i<tokens.size(); ++i){

            int a,b;
            if (tokens[i] == "+" || tokens[i] == "-" ||
                tokens[i] == "*" || tokens[i] == "/"){
                b = s.top(); s.pop();
                a = s.top(); s.pop();
            }

            if (tokens[i] == "+"){
                s.push(a+b);
            }else if (tokens[i] == "-"){
                s.push(a-b);
            }else if (tokens[i] == "*"){
                s.push(a*b);
            }else if (tokens[i] == "/"){
                s.push(a/b);
            }else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};
