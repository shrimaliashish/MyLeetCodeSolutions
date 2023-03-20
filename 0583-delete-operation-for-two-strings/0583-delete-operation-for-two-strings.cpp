class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        
        vector<int> prev(m+1, 0), curr(m+1, 0);

        for(int j = 0; j<=m; j++)
            prev[j] = j;

        int ans = INT_MAX;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(j == 1)
                    curr[j-1] = i;
                
                // Either delete from word1 or word2
                curr[j] = min(prev[j], curr[j-1]) + 1;

                // If current letters are same then no deletion 
                if(word1[i-1] == word2[j-1])
                    curr[j] = min(curr[j], prev[j-1]);
                
                if(i == n || j == m){
                    // This is because any string will remain left to check will be deleted
                    curr[j] += (n-i) + (m-j);
                    ans = min(ans, curr[j]);
                }
            }

            prev = curr;
        }

        return ans;
    }
};