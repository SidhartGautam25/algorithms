#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod LLONG_MAX


void dfs(ll node,ll p,vector<vector<ll>>&tree,vector<ll>&parent,vector<ll>&size,vector<ll>&heavy,vector<ll>&depth){
    for(ll i=0;i<tree[node].size();i++){
        ll child=tree[node][i];
        if(child != p){
            depth[child]=depth[node]+1;
            parent[child]=node;
            dfs(child,node,tree,parent,size,heavy,depth);
            size[node]=size[node]+size[child];

            if(size[child]>size[heavy[node]]){
                heavy[node]=child;
            }
        }
    }
    size[node]++;

}


void HLD(ll node,ll p,ll chain,vector<vector<ll>>&tree,vector<ll>&head,vector<ll>&heavy){
    head[node]=chain;

    if(heavy[node] != 0){
        HLD(heavy[node],node,chain,tree,head,heavy);
    }
    for(ll i=0;i<tree[node].size();i++){
        ll child=tree[node][i];
        if(child != p){
            if(child != heavy[node]){
                HLD(child,node,child,tree,head,heavy);
            }
            
        }
    }
}

ll LCA(ll a,ll b,vector<ll>&head,vector<ll>&depth,vector<ll>&parent){
    //cout<<"head of a "<<head[a]<<"  head of b "<<head[b]<<endl;
    while(head[a] != head[b]){
        //cout<<"loop  head a"<<head[a]<<"  "<<head[b]<<endl;
        if(depth[head[a]]<depth[head[b]]){
            ll t=a;
            a=b;
            b=t;
        }
        a=parent[head[a]];
    }

    if(depth[a]<depth[b]){
        ll t=a;
        a=b;
        b=t;
    }
    return b;
}



void solve(){
    ll n,q;
    cin>>n>>q;
    vector<vector<ll>>tree(n+1);
    for(ll i=2;i<=n;i++){
        ll u=i;
        ll v;
        cin>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<ll>parent(n+1,1);
    vector<ll>depth(n+1,0);
    vector<ll>size(n+1,0);
    vector<ll>head(n+1,0);
    vector<ll>heavy(n+1,0);
    
    dfs(1,1,tree,parent,size,heavy,depth);
    HLD(1,1,1,tree,head,heavy);


    for(ll i=0;i<q;i++){
        ll a,b;
        cin>>a>>b;
        //cout<<"call"<<endl;
        ll lca=LCA(a,b,head,depth,parent);
        //cout<<"here"<<endl;
        cout<<lca<<endl;
    }


   
   
}


int main(){
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
