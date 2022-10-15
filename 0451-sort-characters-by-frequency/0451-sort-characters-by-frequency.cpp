class Solution {
public:
    string frequencySort(string s) {
        map<char,int>m;
        for(auto x:s){
            m[x]++;
        }
        string str="";
        multiset<pair<int,int>>mst;
        for(auto itr=m.rbegin();itr!=m.rend();itr++){
           mst.insert({itr->second,itr->first});
        }
        for(auto itr=mst.rbegin();itr!=mst.rend();itr++){
           for(int i=0;i<itr->first;i++){
               str.push_back(itr->second);
           }
        }
        return str;
    }
};