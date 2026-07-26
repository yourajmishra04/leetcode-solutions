class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& c) {
        sort(c.begin(),c.end(),[](vector<int>&a , vector<int>&b){
            return abs(a[0]-a[1]) > abs(b[0]-b[1]);
        });

        int a =0 , b=0 , ans=0 , da,db;
        int n=c.size();
        for(int i=0;i<n;i++){
             
               da=c[i][0];
               db=c[i][1];
                
               if(da<db){
                   if(a<n/2) {
                    ans+=da;
                    a++;
                   }
                   else{
                    ans+=db;
                    b++;
                   }
               }
              else {
                if(b<n/2){
                    ans+=db;
                    b++;
                }
                else{
                    ans+=da;
                    a++;
                }
               }
               
            

        }
        return ans;
    }
};