class Solution {
public:
    vector<bool> vis;
    void solve(vector<vector<int>>& rooms, int node){
        if(vis[node]) return;
        vis[node]=1;

        for(int child : rooms[node]){
              solve(rooms , child);
        }


    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
      
        vis.assign(n,0);
          
          solve(rooms,0);
           for( auto it : vis) if(it==0) return 0;
           return 1;
    }
};