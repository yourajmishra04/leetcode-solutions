class Solution {
public:
int mod=1e9+7;
int ans=0;
vector<int>dp;
   int solve(  vector<vector<pair<int, int>>>& mat ,   vector<long long>& dis , int node){
             
             int n=mat.size()-1;
             if(node == n) {
                ans=(ans+1)%mod;
                return dp[node]=1;
             }
             if(dp[node]!=-1) return dp[node];
               long long ans=0;
             for(auto [next , a]: mat[node]) {
                if(dis[next]<dis[node]){  ans+=solve(mat, dis,next);
                ans%=mod;}
             }

         return dp[node]=ans;
   }



    int countRestrictedPaths(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int, int>>> mat(n+1);
        for (auto it : edges) {
            mat[it[0]].push_back({it[1], it[2]});
            mat[it[1]].push_back({it[0], it[2]});
        }
        vector<long long> dis(n + 1,LLONG_MAX);
        dis[n] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        pq.push({0, n});
        while (!pq.empty()) {
            auto [a, b] = pq.top();
            pq.pop();
            if (a > dis[b])
                continue;
            for (auto [next, d] : mat[b]) {
                long long newd = a + d;
                if (newd < dis[next]) {
                    dis[next] = newd;
                    pq.push({newd, next});
                }
            }
        }
        dp.assign(n+1 , -1);
       return solve(mat, dis, 1);
        return ans;
    }
};