class Solution {
public:
    bool pal(string s){
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
    int maxPalindromes(string s, int k) {
        
         int n=s.size();
         int ans=0 , i=0;

         while(i<=n-k){
            if(pal(s.substr(i,k))) {
                ans++;
                i+=k;
            }
            else  if( i+k+1 <= n && pal(s.substr(i,k+1))) {
                ans++;
                i+=k+1;
            }
           else i++;
         }
         return ans;
          
    }
};