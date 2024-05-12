#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod LLONG_MAX


void update(vector<int>&arr,int bsize,int ind,int val){
    int blockNo=ind/bsize;
    block[blockNo]=block[blockNo]+(val-arr[ind]);
    arr[ind]=val;
}



int query(vector<int>&arr,int n,vector<int>&block,int blockSize,int l,int r){
    int sum=0;
    //traversing first block in range
    while(l<r and l%blockSize != 0 and l != 0){
        sum=sum+arr[l];
        l++;
    }
    //traversing completely overlapped blocks in range
    while(l+blockSize-1<=r){
        sum=sum+block[l/blockSize];
        l=l+blockSize;
    }
    //traversing last block in range
    while(l<=r){
        sum=sum+arr[l];
        l++;
    }
    return sum;

}



void preprocess(vector<int>&arr,int n,vector<int>&block){
    int blockInd=-1;
    blocksize=sqrt(n);
    for(int i=0;i<n;i++){
        if(i%blocksize==0){
            blockInd++;

        }
        block[blockInd]=block[blockInd]+arr[i];
    }
}




void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    int blockSize=sqrt(n);
    vector<int>block(blockSize);
    for(int i=0;i<n;i++){
        cin>>n;
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int type;
        cin>>type;
        if(type==1){
            int l,r;
            cin>>l>>r;
            int ans=query(arr,n,block,blockSize,l,r);
            cout<<ans<<endl;

        }else{
            //update

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