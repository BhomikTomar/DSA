#include<iostream>
#include<vector>
using namespace std;
// int f(vector<int>& arr,int index,int n,vector<int>& dp){
//     if(index == 0) return arr[index];
//     if(index<0) return 0;
//     if(dp[index] != -1) return dp[index];

//     int pick = arr[index] + f(arr,index-2,n,dp);
//     int notPick = f(arr,index-1,n,dp);

//     return dp[index] = max(pick,notPick);
// }
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        // vector<int> dp(n,-1);

        vector<int> nums(n);

        for(int i=0;i<n;i++){
            cin>>nums[i];
        }

        // return f(arr,n-1,n,dp);

        int prev = nums[0];
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1) pick += prev2;
            int nonPick = prev;
            int curi = max(pick,nonPick);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
    return 0;
}