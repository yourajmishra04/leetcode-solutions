class Solution {
public:
    long long minimumRemoval(vector<int>& b) {
        sort(b.begin(),b.end());
       long long ans=LLONG_MAX,
      tot=0,n=b.size(),curr=0 , prev=0;
        for(int x : b) tot+=x;

        for(int i=0;i<n;i++){
                curr= b[i]*(n-i);
                ans=min(ans, prev+tot-curr);
                tot-=b[i];
                prev+=b[i];
        }
           return ans;
    }
};