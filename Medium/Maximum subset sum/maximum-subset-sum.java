//{ Driver Code Starts
import java.io.*;
import java.util.*;


class IntArray
{
    public static int[] input(BufferedReader br, int n) throws IOException
    {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for(int i = 0; i < n; i++)
            a[i] = Integer.parseInt(s[i]);

        return a;
    }

    public static void print(int[] a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }

    public static void print(ArrayList<Integer> a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            int N;
            N = Integer.parseInt(br.readLine());
            
            
            int[] A = IntArray.input(br, N);
            
            Solution obj = new Solution();
            long res = obj.findMaxSubsetSum(N, A);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends


class Solution {
    public static long findMaxSubsetSum(int n, int[] arr) {
        long[] dp=new long[n+1];
        Arrays.fill(dp,-1);
        return maxSum(arr,0,dp);
    }
    public static long maxSum(int[] arr,int index,long[] dp){
        if(index>=arr.length){
            return 0;
        }
        
        if(dp[index]!=-1) return dp[index];
        long notTake=arr[index]+maxSum(arr,index+1,dp);
        long take=0;
        if((index+1)<arr.length){
            take=arr[index+1]+maxSum(arr,index+2,dp);
        }
        return dp[index]=Math.max(notTake,take);
    }
}
   
        
