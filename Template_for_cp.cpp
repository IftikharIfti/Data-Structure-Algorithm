#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pi acos(-1)
#define pb push_back
#define mp make_pair
#define fast                   \
  ios::sync_with_stdio(false); \
  cin.tie(NULL);               \
  cout.tie(NULL);
typedef vector<ll> vl;
typedef vector<int> vi;

#define MAXN 202020

vector<bool> visited(MAXN,false);
vector<int> graph[MAXN];

void ADD_EDGE(int a,int b)
{
 graph[a].push_back(b);
 graph[b].push_back(a);
}

void bfs(int u)
{
  queue<int> q;
  q.push(u);
  visited[u]=true;
  while(!q.empty())
  {
    int front=q.front();
    q.pop();
    cout<<front<<' ';//bfs print
    for(auto i=graph[front].begin();i!=graph[front].end();i++)
    {
      if(!visited[*i])
      {
        q.push(*i);
        visited[*i]=true;
      }
    }
  }
}

void dfs(int k)
{
  if(visited[k]) return;
  visited[k]=true;
  //cout<<k<<" ";//dfs print
  for(auto child:graph[k]) dfs(child);
}

void solve()
{
 
}
int main()
{
  fast;
  int testcase;
  testcase = 1;
 // cin >> testcase;
  while (testcase--)
  {
    solve();
    cout << endl;
  }
}
