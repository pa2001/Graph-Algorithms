#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<bool>v;
int n,e,a,b;
bool flag=false;
void addedge(int a,int b)
{
  adj[a].push_back(b);
}
void dfs(int index)
{
  if(index>=adj.size())
  return;
  for(int i=index;i<adj.size();i++)
  {
    for(int j=0;j<adj[i].size();j++)
    {
      if(v[adj[i][j]])
      {
        flag=true;
        return;
      }
      else
      {
        v[adj[i][j]]=true;
        dfs(adj[i][j]);
      }
    }
  }
}
int main()
{
  cout<<"Enter no. of nodes and edges:";
  cin>>n>>e;
  adj.assign(n,vector<int>());
	v.assign(n,false);
  for(int i=0;i<e;i++)
  {
    cin>>a>>b;
    addedge(a,b);
  }
  for(int i=0;i<adj.size();i++)
  {
    cout<<i<<" ";
    for(int j=0;j<adj[i].size();j++)
    cout<<adj[i][j]<<" ";
    cout<<endl;
  }
  dfs(0);
  if(flag)
  cout<<"Yes"<<endl;
  else
  cout<<"No"<<endl;
}
