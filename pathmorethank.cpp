#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>adj[100];
int n,e,a,b,c,src,k;
vector<bool>path;
void addedge(int a,int b,int c)
{
  adj[a].push_back(make_pair(b,c));
  adj[b].push_back(make_pair(a,c));
}
bool pathmorethank(int src,int k)
{
  if(k<=0)
  return true;
  vector<pair<int,int>>::iterator it;
  for(it=adj[src].begin();it!=adj[src].end();it++)
  {
    int v=(*it).first;
    int w=(*it).second;
    if(path[v]==true)
    continue;
    if(w>=k)
    return true;
    path[v]=true;
    if(pathmorethank(v,k-w))
    return true;
    path[v]=false;
  }return false;
}
int main()
{
  cout<<"Enter number of edges and vertices-";
  cin>>e>>n;
  path.assign(n,false);
  for(int i=0;i<e;i++)
  {
    cin>>a>>b>>c;
    addedge(a,b,c);
  }
  int t=10;
  while(t--)
  {
  cout<<"Enter source and distance k-";
  cin>>src>>k;
  path[src]=1;
  if(pathmorethank(src,k))
  cout<<"Yes"<<endl;
  else
  cout<<"No"<<endl;
  }
}
