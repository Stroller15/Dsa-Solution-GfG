//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    long long firstOcc(vector<long long> v, long long x) {
        long long low = 0, high = v.size() - 1;
        long long ans = -1;
        
        while(low <= high) {
            int mid = (low - (low - high)/2);
            
            if(v[mid] == x) {
                ans = mid;
                high = mid - 1;
            }else if(v[mid] < x) {
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
    
    long long lastOcc(vector<long long> v, long long x) {
        long long low = 0, high = v.size() - 1;
        long long ans = -1;
        
        while(low <= high) {
            int mid = (low - (low - high)/2);
            
            if(v[mid] == x) {
                ans = mid;
                low = mid + 1;
            }else if(v[mid] < x) {
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        pair<long long, long long> ans;
        
        long long ans1 = firstOcc(v, x);
        long long ans2 = lastOcc(v, x);
        
        return {ans1, ans2};
        
        
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends