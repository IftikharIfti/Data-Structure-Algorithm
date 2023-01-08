#include<bits/stdc++.h>

using namespace std;

vector<bool> visited;
vector<vector<int>> graph;

void _EDGE(int a,int b)
{
    graph[a].push_back(b);
}

void bfs (int u)
{
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        cout<<f<<" ";

        for(auto i=graph[f].begin();i!=graph[f].end();i++)
        {
            if(!visited[*i])
            {
                q.push(*i);
                visited[*i]=true;
            }
        }
    }
}
int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    visited.assign(nodes,false);
    graph.assign(nodes,vector<int>());

    int a,b;
    for(int i=0;i<edges;i++)
    {
        cin>>a>>b;//enter connected nodes. We don't need to repeat the same edge
        _EDGE(a,b);

    }
    for(int i=0;i<nodes;i++)
    {
        if(!visited[i])
        {
            bfs(i);
        }
    }
}