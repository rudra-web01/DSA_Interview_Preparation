//Time Complexity-- O(N)
//Space Complexity-- O(N)
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '(') {
                st.push(ch);
            }
            else {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
                else {
                    st.push(ch);
                }
            }
        }

        return st.size();
    }
};

//It can be solved in O(1) time complexity also using String

class Solution {
public:
    int minAddToMakeValid(string s) {
        int size=0;
        int open=0;

        for(auto&ch:s){
            if(ch=='('){
                size++;
            }else if(size>0){
                size--;
            }
            else{
                open++;
            }

        }
        return open + size;
    }
};
