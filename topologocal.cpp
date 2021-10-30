#include<bits/stdc++.h>
using namespace std;
int n,e,a,b;
vector<vector<int>>adj;
void addedge(int a,int b)
{
  adj[a].push_back(b);
}
void topological(int v,bool vis[],stack<int>&s)
{
  vis[v]=true;
  vector<int>::iterator it;
  for(it=adj[v].begin();it!=adj[v].end();it++)
  {
    if(!vis[*it])
    topological(*it,vis,s);
  }s.push(v);
}
void topologicalsort()
{
  stack<int>s;
  bool vis[n];
  for(int i=0;i<n;i++)
  vis[i]=false;
  for(int i=0;i<n;i++)
  {
    if(vis[i]==false)
    topological(i,vis,s);
  }
  while(!s.empty())
  {
    cout<<s.top()<<" ";
    s.pop();
  }
}
int main()
{
  cout<<"Enter number of edges and vertices-";
  cin>>n>>e;
  adj.assign(n,vector<int>());
  for(int i=0;i<n;i++)
  {
    cin>>a>>b;
    addedge(a,b);
  }topologicalsort();
}
