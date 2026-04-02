class Solution {
public:
    bool isValid(string s) {
        vector<char> a;
        for (auto i:s) {
            if (i=='[' || i=='{' || i=='(') a.push_back(i);
            else {
                if (a.empty()) return false;
                if ((a.back() == '[' && i!=']') || (a.back() == '(' && i!=')') || (a.back() == '{' && i!='}') ) {
                    return false;
                }
                else {
                    a.pop_back();
                }
            }
        }
        return a.empty();
    }
};
