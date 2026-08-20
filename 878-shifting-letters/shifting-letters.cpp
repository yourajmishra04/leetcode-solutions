class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int temp=0,n=s.size();
        for(int i=n-1;i>=0;i--){
              temp+=shifts[i];
              temp%=26;
              s[i]=(s[i]-'a' + temp)%26 + 'a';
        }
        return s;
    }
};