#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;
    cin>>x;
    sort(a.begin(),a.end());
    int left=0,right=n-1;
    bool found=false;
    while(left<right){
        int sum=a[left]+a[right];
        if(sum==x){
            found=true;
            break;
        }
        else if(sum<x){
            left++;
        }
        else right--;
    }
    cout<<(found ? "Yes":"No")<<endl;
    return 0;
}