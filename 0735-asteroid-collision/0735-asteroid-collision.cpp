class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int>v;
        int sign=0;
        for(auto x:a){
            if(v.empty() || (v.back()*x)>0){
                v.push_back(x);
            }else{
                int flag=false;
                while(!v.empty() && v.back()>0 && x<0){
                flag=false;
                int temp=v.back();
                v.pop_back();
                flag=abs(x)==abs(temp);
                x=abs(x)>abs(temp)?x:temp;
                }
                if(!flag)
                v.push_back(x);
                
            }
        }
        return v;
    }
};