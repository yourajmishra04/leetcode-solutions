class Solution {
public:
    int n, m;
    queue<pair<int , int>> q;


    void solve( vector<vector<int>>& v ) {
       while(!q.empty()){
       auto it= q.front();
       q.pop();
       int i=it.first , j=it.second ;
           if(i>0 && v[i-1][j]== INT_MAX){
               
                v[i-1][j]=v[i][j]+1;
                q.push({i-1 , j});

           }
           if(i<n-1 && v[i+1][j]==INT_MAX){
                  v[i+1][j]=v[i][j]+1;
                q.push({i+1 , j});

           }
           if(j>0 && v[i][j-1]==INT_MAX){
                   v[i][j-1]=v[i][j]+1;
                q.push({i , j-1});

           }
           if(j<m-1 && v[i][j+1]==INT_MAX){
                   v[i][j+1]=v[i][j]+1;
                q.push({i , j+1});

           }
 
        
       }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        q=queue<pair<int,int>>();
        vector<vector<int>> v(n, vector<int>(m, INT_MAX));

         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(mat[i][j]==0)  {
                q.push({i,j});
                v[i][j]=0;
              }
            }
        }

        solve(v);
        return v;
    }
};