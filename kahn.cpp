#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,e;
vector<int>indegree;
vector<vector<int>>adj;
vector<bool>vis;
vector<int>res;
void addedge(int a,int b)
{
  adj[a].push_back(b);
}
void topologicalsort()
{
  for(int i=0;i<n;i++)
  {
    vector<int>:: iterator it;
    for(it=adj[i].begin();it!=adj[i].end();it++)
    {
      indegree[*it]++;
    }
  }
  queue<int>q;
  for(int i=0;i<n;i++)
  {
    if(indegree[i]==0)
    q.push(i);
  }
    int cnt=0;
    vector<int>top;
    while(!q.empty())
    {
      int u=q.front();
      q.pop();
      top.push_back(u);
      vector<int>:: iterator it;
      for(it=adj[u].begin();it!=adj[u].end();it++)
      {
        if(--indegree[*it]==0)
        q.push(*it);
      }
      cnt++;
    }
    if(cnt!=n)
    {
      cout<<"There exsist cycle in graph"<<endl;
      return;
    }
    for(int i=0;i<top.size();i++)
    cout<<top[i]<<" ";
    cout<<endl;
}
int main()
{
  cout<<"Enter number of edges and vertices-";
  cin>>n>>e;
  adj.assign(e,vector<int>());
  indegree.assign(e,0);
  vis.assign(e,false);
  for(int i=0;i<n;i++)
  {
    cin>>a>>b;
    addedge(a,b);
  }topologicalsort();
}
