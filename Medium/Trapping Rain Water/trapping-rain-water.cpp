//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        int maxL[n];
        int maxR[n];
        
        int maxSoFarLeft = INT_MIN;
        int maxSoFarRight = INT_MIN;
        
        
        
        for(int i = 0 ; i < n ; i++) {
            maxSoFarLeft = max(arr[i], maxSoFarLeft);
            maxL[i] = maxSoFarLeft;
        }
        
        for(int i = n-1 ; i >= 0 ; i--) {
            maxSoFarRight = max(arr[i], maxSoFarRight);
            maxR[i] = maxSoFarRight;
        }
        
        int heightOfWater[n];
        
        for(int i = 0 ; i < n ; i++) {
            heightOfWater[i] = (min(maxL[i], maxR[i])) - arr[i];
        }
        
        long long ans = 0;
        
        for(int i = 0 ; i < n ; i++) {
            ans += heightOfWater[i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends