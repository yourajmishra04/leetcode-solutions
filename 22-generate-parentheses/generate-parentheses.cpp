class Solution {
public:
 void paranthesis(string s, int o, int c, int n,vector<string>&ans)
{
    if (o == n && c == n)
    {
        ans.push_back(s);
        return;
    }
    if (o < n)
        paranthesis(s + '(', o + 1, c, n,ans);
    if (o > c && c < n)
    {
        paranthesis(s + ')', o, c + 1, n,ans);
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
         paranthesis("",0,0,n,ans);
         return ans;
    }
};