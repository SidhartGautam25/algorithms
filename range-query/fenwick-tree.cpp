#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod LLONG_MAX


int getSum(vector<int>&BTree,int ind){
    int sum=0;
    ind=ind+1;
    while(ind>0){
        sum=sum+BTree[ind];
        ind=ind-(ind&(-ind));
    }
}


void updateBTree(vector<int>& BTree,int n,int ind,int val){
    ind=ind+1;
    while(ind<=n){
        BTree[ind]=BTree[ind]+val;
        ind=ind+(ind& (-ind));
    }

}



void constructBTree(vector<int>&BTree,int n,vector<int>&arr){
    for(int i=0;i<n;i++){
        updateBTree(BTree,n,i,arr[i]);
    }
}



void solve(){
    int n,q;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>BTree(n+1,0);
    constructBTree(arr,BTree);
    for(int i=0;i<q;i++){
        int type;
        cin>>type;
        if(type==1){
            int l,r;
            cin>>l>>r;
            int sumR=getSum(BTree,r);
            int sumL=getSum(BTree,l-1);
            int ans=sumR-sumL;

        }else{
            //at index ind,increase the value by val
            int ind,val;
            cin>>ind>>val;
            arr[ind]=arr[ind]+val;
            updateBTree(BTree,n,ind,val);
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    
    cin>>t;
    while(t--){
        solve();
     }

    return 0;
}