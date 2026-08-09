//Time Complexity--O(M*N)
//space Complexity==O(m+n)

class Solution {
public:

    bool check(stack<char> tempst, string part, int n) {
        for(int idx = n - 1; idx >= 0; idx--) {
            if(tempst.top() != part[idx])
                return false;

            tempst.pop();
        }

        return true;
    }

    string removeOccurrences(string s, string part) {
        stack<char> st;

        int m = s.length();
        int n = part.length();

        for(int i = 0; i < m; i++) {
            st.push(s[i]);

            if(st.size() >= n && check(st, part, n)) {
                for(int j = 0; j < n; j++) {
                    st.pop();
                }
            }
        }

        string res = "";

        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
