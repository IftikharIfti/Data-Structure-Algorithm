#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100000];
bool visited[100000];
void dfs(int k)
{
 if(visited[k])
 {
     return;
 }
 visited[k]=true;
 cout<<k<<' '; //for printing the visited nodes
 for(auto u:adj[k]) dfs(u);
}
int main()
{
    int n=6;
    while(n--)
    {
         //directed graph
         int p,q;
         cin>>p>>q;
         adj[p].push_back(q);
         
    }
    //dfs(0);

    // for(int i=0;i<=7;i++)
    // {
    //     cout<<i<<':'<<adj[i]<<" ";//To check the nodes if visited
    // }

    //can you go from l to m?
    //solve:
    
    int l,m;
    cin>>l>>m;
    dfs(l);
    if(visited[m]==true) cout<<"YES";
    else cout<<"NO";

    
}
