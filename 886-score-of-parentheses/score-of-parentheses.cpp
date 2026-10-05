class Solution {
public:
int get(int n){
    int ans=1;
    while(n>0){
        ans*=2;
        n--;
    }
    return ans;
}
    int scoreOfParentheses(string s) {
        int n=s.size();
        int ans=0;
        int st=0;
        int i=0;
      while(i<n){
        while(i<n && s[i]=='('){
            i++;
            st++;
        }
        int j=i;
        while(j<n && s[j]==')') j++;

        ans+=get(st-1);
        st-=(j-i);
        i=j;


      }
      return ans;
    }
};