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
  indegree[b]++;
}
void alltopologicalsort()
{
  bool flag=false;
  for(int i=0;i<e;i++)
  {
    if(indegree[i]==0&&!vis[i])
    {
      vector<int>:: iterator j;
      for(j=adj[i].begin();j!=adj[i].end();j++)
      {
        indegree[*j]--;
      }
        res.push_back(i);
        vis[i]=true;
        alltopologicalsort();
        vis[i]=false;
        res.erase(res.end()-1);
        for(j=adj[i].begin();j!=adj[i].end();j++)
        {
          indegree[*j]++;
        }
        flag=true;
    }
  }
  if(!flag)
  {
    for(int i=0;i<res.size();i++)
    {
      cout<<res[i]<<" ";
    }cout<<endl;
  }
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
  }alltopologicalsort();
}
