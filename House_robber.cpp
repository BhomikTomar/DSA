#include<iostream>
#include<vector>
using namespace std;
int f(vector<int>& nums,int n){
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
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> nums(n);

        for(int i=0;i<n;i++){
            cin>>nums[i];
        }

        cout<<f(nums,n)<<endl;
    }
    return 0;
}