class StockSpanner {
public:
    StockSpanner() {
    
    }
    stack<pair<int,int>>s;
    int next(int price) {
        int c=1;
        while(!s.empty() && s.top().first<=price){
            c+=s.top().second;
            s.pop();
        }
        s.push({price,c});
        return c;
    }
};
