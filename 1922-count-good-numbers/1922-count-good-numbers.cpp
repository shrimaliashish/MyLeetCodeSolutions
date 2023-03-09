class Solution {
public:
    int power(long long x, long long  y, int p)
    {
      int res = 1;   

      x = x % p; 
      if (x == 0) return 0; 
      while (y > 0)
      {
        if (y & 1)
          res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;
      }
      return res;
    }
    int countGoodNumbers(long long n) {
        int mod=1e9+7;
        if(n==1)
            return 5;
        long long  odd=n/2;
        long long even=(n+1)/2;
        return ((long long)power(4,odd,mod)%mod*power(5,even,mod)%mod)%mod;   
    }
};