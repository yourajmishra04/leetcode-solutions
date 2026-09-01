class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n=classroom.size(), m=classroom[0].size();
        int sr=-1, sc=-1;
        int l=0;
        map<pair<int,int> , int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(classroom[i][j]=='S') {
                    sr=i;
                    sc=j;
                }
                if(classroom[i][j]=='L'){
                    mp[{i,j}] = l;
                    l++;
                }
            }
        }
        if(l==0) return 0;
          vector<int>dr= {0 , 0 , 1 , -1};
          vector<int>dc= {1,-1,0,0};
        int tar=(1<<l)-1;

          vector<vector<vector<vector<int>>>> dp (
            n , vector<vector<vector<int>>>(m, 
            vector<vector<int>>(
             energy+1 , vector<int>(tar+1 ,-1)
            ))
          );

          queue<tuple<int,int,int,int>>q;
          dp[sr][sc][energy][0]=0;
          q.push({sr,sc,energy , 0});

          while(!q.empty()){
            auto [r,c,curr,vis]=q.front();
            q.pop();
            int moves= dp[r][c][curr][vis];
            if(vis == tar) return moves;

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && classroom[nr][nc]!='X'
                && curr>0 ){
                    int nextmoves=moves+1;
                    int nexte=curr-1;
                    int nextmask=vis;

                    if(classroom[nr][nc]=='L') nextmask |=(1<< mp[{nr,nc}]);
                    else if(classroom[nr][nc]=='R') nexte=energy;

                    if(dp[nr][nc][nexte][nextmask]==-1){
                       dp[nr][nc][nexte][nextmask] = nextmoves;
                       q.push({nr,nc,nexte,nextmask});
                    }
                }
            }


          }
          return -1;

    }
};