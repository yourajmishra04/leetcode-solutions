class Solution {
public:
    long long minimumCost(int c1, int c2, int cb, int n1, int n2) {
        long long ans=0;
        long long mn=min(n1,n2);
        c1=min(c1,cb);
        c2=min(c2,cb);
        if(c1+c2 >= cb) {
            ans+=mn*cb;
            n1-=mn;
            n2-=mn;
        } 
        ans+= 1LL*n1*c1;
        ans+= 1LL *n2*c2;
        return ans;
    }
};