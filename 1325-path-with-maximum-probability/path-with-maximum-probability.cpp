class Solution {
public:
     double ans=0;
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>mat(n);
         int m=succProb.size();
         for(int i=0;i<m;i++){
            mat[edges[i][0]].push_back({edges[i][1],succProb[i] });
            mat[edges[i][1]].push_back({edges[i][0],succProb[i] });
         }
         vector<double>vis(n,0.0);
           vis[start_node]=1.0;
         priority_queue<pair<double, int>>q;
         q.push({1.0 ,start_node });
         while(!q.empty()){
         auto[a,b]=q.top();
         q.pop();
           if(b==end_node) return a;
           if(a< vis[b]) continue;

            for(auto [next , pro] : mat[b]){
                double newp= pro*a;
                if(newp > vis[next]){
                    q.push({newp , next});
                    vis[next]=newp;
                }
            }
         }
         return 0.0;

    }
};