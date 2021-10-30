#include<bits/stdc++.h>
using namespace std;
int n,e,a,b;
vector<vector<int>>v;
void addedge(int a,int b)
{
  v[a].push_back(b);
}
bool dfs(int u,int color[])
{
  color[u]=0;
  vector<int>::iterator it;
  for(it=v[u].begin();it!=v[u].end();it++)
  {
    int v=*it;
    if(color[v]==0)
    return true;
    if(color[v]==-1&&dfs(v,color))
    return true;
  }
  color[u]=1;
  return false;
}
bool iscyclic()
{
  int color[n];
  for(int i=0;i<n;i++)
  color[i]=-1;
  for(int i=0;i<n;i++)
  {
    if(color[i]==-1)
    {
      if(dfs(i,color)==true)
      return true;
    }
  }return false;
}
int main()
{
  cout<<"Enter no. of edges and vertices:";
  cin>>e>>n;
  v.assign(n,vector<int>());
  for(int i=0;i<e;i++)
  {
    cin>>a>>b;
    addedge(a,b);
  }
  if(iscyclic())
  cout<<"Yes"<<endl;
  else
  cout<<"No"<<endl;
}
