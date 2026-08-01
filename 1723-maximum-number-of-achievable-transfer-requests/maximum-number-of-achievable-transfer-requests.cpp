class Solution {
public:
int ans;
int m;
    void solve(int idx, int cnt , vector<vector<int>>& r, vector<int>& v){
        if(idx==m){
           for(auto x : v) if(x!=0) return;
           ans=max(ans,cnt);
           return;
        }
     
        int f=r[idx][0] , t = r[idx][1];
        v[f]++;
        v[t]--;

        solve(idx+1, cnt+1, r , v);
        v[f]--;
        v[t]++;
        solve(idx+1, cnt , r,v);



    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> v(n,0);
        ans=0;
        m=requests.size();
        solve(0,0,requests , v);
        return ans;
    }
};