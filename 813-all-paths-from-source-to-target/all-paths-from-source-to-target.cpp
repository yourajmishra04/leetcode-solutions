class Solution {
public:
    vector<vector<int>>ans;
     int n;
    void solve(vector<vector<int>>& graph, vector<int>& v){
        int curr=v.back();
        if(curr==n) {
            ans.push_back(v);
            return;
        }
        if(graph[curr].empty()) return;
        for(int x : graph[curr]){
            v.push_back(x);
            solve(graph , v);
            v.pop_back();
        }


    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       n=graph.size()-1;
       vector<int>v={0};
         ans.clear();
       solve(graph , v);
        return ans;
    }
};