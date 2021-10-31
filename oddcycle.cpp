#include<bits/stdc++.h>
using namespace std;
int n,m,e,a,b,c;
vector<vector<int>>adj;
vector<bool>vis;
bool color_util(vector<int>g[],int src,int l,int color[])
{
  color[src]=1;
  queue<int>q;
  q.push(src);
  while(!q.empty())
  {
    int u=q.front();
    q.pop();
    for(int v=0;v<g[u].size();v++)
    {
      if(color[g[u][v]]==-1)
      {
        color[g[u][v]]=1-color[u];
        q.push(g[u][v]);
      }
      else if(color[g[u][v]]==color[u])
      return false;
    }
  }return true;
}
bool two_color(vector<int>g[],int l)
{
  int color[l+1];
  for(int i=1;i<=l;i++)
  color[i]=-1;
  for(int i=1;i<=l;i++)
  {
    if(color[i]==-1)
    if(color_util(g,i,l,color)==false)
    return false;
  }
  return true;
}
bool isodd()
{
  vector<int>g[2*n];
  int pseudo=n+1;
  int pseudo_count=0;
  for(int i=0;i<m;i++)
  {
    if(adj[i][2]%2==1)
    {
      int u=adj[i][0];
      int v=adj[i][1];
      g[u].push_back(v);
      g[v].push_back(u);
    }
    else
    {
      int u=adj[i][0];
      int v=adj[i][1];
      g[u].push_back(pseudo);
      g[pseudo].push_back(u);
      g[v].push_back(pseudo);
      g[pseudo].push_back(v);
      pseudo_count++;
      pseudo++;
    }
  }return two_color(g,n+pseudo_count);
}
int main()
{
  cout<<"Enter number of vertices -";
  cin>>n;
  vis.assign(n,false);
  adj.assign(n,vector<int>());
  for(int i=0;i<n;i++)
  {
    cin>>a>>b>>c;
    adj[i].push_back(c);
    adj[i].push_back(b);
    adj[i].push_back(a);
  }
  if(isodd())
  cout<<"Yes"<<endl;
  else
  cout<<"No"<<endl;
}
