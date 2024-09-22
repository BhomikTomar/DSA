#include<iostream>
#include<vector>
using namespace std;
int f(vector<int>& nums){
    int n=nums.size();
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

        if(n==1) return nums[0];

        vector<int> temp1;
        vector<int> temp2;

        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }

        cout << max(f(temp1),f(temp2));
    }
    return 0;
}