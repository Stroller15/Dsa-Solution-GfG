//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long , vector<long long> , greater<long long>> minHeap;
        
        for(int i = 0 ; i < n ; i++) {
            minHeap.push(arr[i]);
        }
        
        long long ans = 0 , a , b;
        
        while(minHeap.size() >= 2) {
    
            a = minHeap.top();
            minHeap.pop();
            b = minHeap.top();
            minHeap.pop();
            
            ans += (a + b);
            
            minHeap.push(a+b);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends