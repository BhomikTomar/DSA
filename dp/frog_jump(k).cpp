#include<iostream>
#include<vector>
#include <climits>
using namespace std;
// int min_steps(int index,vector<int>& heights,vector<int>& dp){
//    if(index == 0) return 0;
//    int right = INT_MAX;
//    if(dp[index]!=-1) return dp[index];
   
//    int left = min_steps(index - 1,heights,dp) + abs(heights[index]-heights[index-1]);
//    if(index>1) right = min_steps(index - 2,heights,dp) + abs(heights[index]-heights[index-2]);

//    return dp[index] = min(left,right);
// }
int main()
{
   int n,k;
   cin>>n>>k;

   vector<int> heights(n);
   for(int i=0;i<n;i++){
      cin>>heights[i];
   }

   vector<int> dp(n,0);
   dp[0]=0;
   int jump;
   for(int i=1; i<n; i++){
      int min_steps = INT_MAX;
      for(int j=1; j<k; j++){
         if((i-j)>0) jump = dp[i-j] + abs(heights[i]-heights[i-j]);
         min_steps = min(min_steps,jump);
      }
      dp[i] = min_steps;
   }
   return dp[n-1];
}