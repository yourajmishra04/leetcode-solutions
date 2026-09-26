class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto it : knowledge)
            mp[it[0]] = it[1];

        string ans = "";
        int i = 0, n = s.size(), j;
        while (i < n) {
            while (i < n && s[i] != '(') {
                ans += s[i];
                i++;
            }
            if (i >= n)
                break;
            string temp = "";
            j = i + 1;
            while (j < n && s[j] != ')') {
                temp += s[j];
                j++;
            }
            if(mp.find(temp)!=mp.end())
            ans += mp[temp];
            else ans+='?';
            i = j + 1;
        }
        return ans;
    }
};