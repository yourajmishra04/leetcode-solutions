class Solution {
public:
    string reverseParentheses(string S) {
        stack<char> st;
        int m = S.size();
        int l = 0, r = m - 1;
        while (l < m && S[l] != '(')
            l++;
        if (l >= m)
            return S;
        while (r > l && S[r] != ')')
            r--;
        string s = S.substr(l, r - l + 1);
        string ss;
        int n = s.size();
        for (int i = 0; i < n ; i++) {
            if (s[i] != ')') {
                st.push(s[i]);
                continue;
            }
            ss.clear();
            while (st.top() != '(') {
                ss.push_back(st.top());
                st.pop();
            }
            st.pop();
            for (int j = 0; j < ss.size(); j++)
                st.push(ss[j]);
        }
        ss.clear();
        while (!st.empty()) {
            ss.push_back(st.top());
            st.pop();
        }
        reverse(ss.begin(),ss.end());
        string ans = "";
        for (int i = 0; i < l; i++)
            ans += S[i];
        ans += ss;
        for (int i = r + 1; i < m; i++)
            ans += S[i];
        return ans;
    }
};