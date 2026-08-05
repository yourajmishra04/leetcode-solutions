class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0, y=0;
        set<pair<int,int>>st;
 st.insert({x,y});
        for(auto it : path){
            if(it=='N') y+=1;
            else if(it=='E') x+=1;
            else if(it=='S') y-=1;
            else x-=1;

            if(st.find({x,y})!=st.end()) return 1;

            st.insert({x,y});
        }
         
        return 0;
    }
};