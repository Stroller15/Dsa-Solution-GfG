//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countBits(long long N) {
        long long ans = 0;
        
        int a = 1;
        int b = 1 << a;
        
        for(int i = 0; i < 31; i++) {
            
            ans += (N / b) * a;
            int rem = (N % b) - a + 1;
            
            if(rem > 0)
                ans += rem;
                
            a <<= 1;
            b <<= 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends