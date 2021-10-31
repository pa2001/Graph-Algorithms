#include<bits/stdc++.h>
using namespace std;
int n,e,a,b,c;
vector<vector<int>>adj;
vector<bool>vis;
void dfs(int ed,int vert,int start,int &count)
{
  vis[vert]=true;
  if(ed==0)
  {
    vis[vert]=false;
    if(adj[vert][start])
    {
      count++;
      return;
    }
    else
    return;
  }
  for(int i=0;i<ed;i++)
  {
    if(!vis[i]&&adj[vert][i])
    dfs(ed-1,i,start,count);
  }
  vis[vert]=false;
}
int countcycle()
{
  int count=0;
  for(int i=0;i<n-c+1;i++)
  {
    dfs(n-1,i,i,count);
    vis[i]=true;
  }
  return count;
}
int main()
{
  cout<<"Enter number of vertices and cycle length-";
  cin>>n>>c;
  vis.assign(n,false);
  adj.assign(n,vector<int>());
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>a;
      adj[i].push_back(a);
    }
  }
  cout<<"There are "<<countcycle()<<" no. of cycle.";
}
