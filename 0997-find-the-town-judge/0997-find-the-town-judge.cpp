class Solution {
public:
    bool check(int k,int n,map<int,set<int>>m){
       for(auto x:m){
           if(x.second.find(k)!=x.second.end()){
               return false;
           }
       }
        return true;
    }
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1){
            return 1;
        }
        map<int,set<int>>m;
        for(auto x:trust){
            m[x[1]].insert(x[0]);
        }
        int judge=-1;
        vector<int>judges;
        for(auto x:m){
            if(x.second.size()==n-1){
                // cout<<x.first<<endl;
                judges.push_back(x.first);
            }
        }
        for(auto x:judges){
            if(check(x,n,m)){
                return x;
            }
        }
        return -1;
    }
};