#include<iostream>
#include<vector>
using namespace std;

void subseq(vector<int>& arr, vector<int>& sub, int index){
    if(index >= arr.size()) {
        cout<<"{";
        for(auto it: sub){
            cout<<it<<" ";
        }
        cout<<"}"<<endl;
        return ;
    }
    sub.push_back(arr[index]);
    subseq(arr,sub,index+1);

    sub.pop_back();
    subseq(arr,sub,index+1);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> sub;
    subseq(arr,sub,0);

    return 0;
}