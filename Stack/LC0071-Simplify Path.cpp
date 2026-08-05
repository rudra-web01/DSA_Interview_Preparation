// LeetCode 71. Simplify Path
// Difficulty: Medium
// Topic: Stack, String
//
// Approach:
// 1. Split the path using '/'.
// 2. Ignore empty strings ("") and ".".
// 3. If the token is "..", pop the top directory (if any).
// 4. Otherwise, push the directory onto the stack.
// 5. Reconstruct the canonical path from the stack.
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        stringstream ss(path); //tokenization
        stack<string> st;

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") continue;

            if (token != "..") {
                st.push(token);
            } else if (!st.empty()) {
                st.pop();
            }
        }

        if (st.empty()) return "/";

        string res = "";
        while (!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }

        return res;
    }
};
