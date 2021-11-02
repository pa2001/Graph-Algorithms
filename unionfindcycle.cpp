#include<bits/stdc++.h>
using namespace std;
int n,a,b,e;
vector<vector<int>>adj;
vector<int>parent;
vector<int>siz;
void addedge(int a,int b)
{
  adj[a].push_back(b);
}
void initialize()
{
  for(int i=0;i<=n;i++){
        parent.push_back(i);
        siz.push_back(1);
    }
}
int find(int i)
{
  if(parent[i]!=i)
  {
    parent[i]=parent[parent[i]];
    i=parent[i];
  }return i;
}
void Union(int x,int y)
{
  if(siz[x]<siz[y])
  {
    parent[x]=parent[y];
    siz[y]+=siz[x];
  }
  else
  {
    parent[y]=parent[x];
    siz[x]+=siz[y];
  }
}
bool iscyclic()
{
  int parent[n];
  for(int i=0;i<n;i++)
  parent[i]=-1;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<adj[i].size();j++)
    {
      int x=find(i);
      int y=find(adj[i][j]);
      if(x==y)
      return true;
      Union(x,y);
    }
  }return false;
}
int main()
{
  cout<<"Enter number of edges and vertices-";
  cin>>n>>e;
  adj.assign(e,vector<int>());
  for(int i=0;i<n;i++)
  {
    cin>>a>>b;
    addedge(a,b);
  }
  initialize();
  if(iscyclic())
  cout<<"Yes"<<endl;
  else
  cout<<"No"<<endl;
}
