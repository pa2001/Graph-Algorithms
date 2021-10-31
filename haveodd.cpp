#include<bits/stdc++.h>
using namespace std;
int n,m,e,a,b,c;
vector<vector<int>>adj;
vector<bool>vis;
bool haveodd(int src)
{
  int color[n];
  for(int i=0;i<n;i++)
  color[i]=-1;
  color[src]=1;
  queue<int>q;
  q.push(src);
  while(!q.empty())
  {
    int u=q.front();
    q.pop();
    if(adj[u][u]==1)
    return true;
    for(int v=0;v<n;v++)
    {
      if(adj[u][v]&&color[v]==-1)
      {
        color[v]=1-color[u];
        q.push(v);
      }
      else if(adj[u][v]&&color[v]==color[u])
      return true;
    }
  }return false;
}
int main()
{
  cout<<"Enter number of vertices -";
  cin>>n;
  vis.assign(n,false);
  adj.assign(n,vector<int>());
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>a;
      adj[i].push_back(a);
    }
  }cout<<haveodd(0);
}
