#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                }
                char top = st.top();
                st.pop();
                if (ch == ')' && top != '(') return false;  //  Example: "(]" → ch = ')', top = '['  then return false and move to next if 
                if (ch == ']' && top != '[') return false;  //         and if true then good, go up then i++ and so onn.. 
                if (ch == '}' && top != '{') return false;
            }
        }
        return st.empty();
    }
};
