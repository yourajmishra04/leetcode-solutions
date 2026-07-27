class Solution {
public:
    set<string> st;
    string d;
    int ans;
    void solve(queue<pair<string, int>>& q) {
        if (q.empty())
            return;

        while (q.size() > 0) {

            string s = q.front().first;
            int curr = q.front().second;
            q.pop();
            if (s == d) {
                ans = curr;
                return;
            }

            for (int i = 0; i < s.size(); i++) {
                for (int j = 0; j < 26; j++) {
                    string ss = s;
                    ss[i] = 'a' + j;
                    if (ss != s && st.find(ss) != st.end()) {
                        q.push({ss, curr+1});
                        st.erase(ss);
                    }
                }
            }
        }
    }

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        st.clear();
        d = endWord;
        ans = 0;
        for (auto it : wordList)
            st.insert(it);
        queue<pair<string, int>> q;
        if (st.find(d) == st.end())
            return ans;
        if (st.find(beginWord) != st.end())
            st.erase(beginWord);
        q.push({beginWord, 1});
        solve(q);
        return ans;
    }
};