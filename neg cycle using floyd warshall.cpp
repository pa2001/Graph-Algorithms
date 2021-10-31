#include<bits/stdc++.h>
using namespace std;
int n,e,a,b,c;
vector<vector<int>>adj;
vector<bool>vis;
bool negcycle()
{
  int dist[n][n],i,j,k;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      dist[i][j]=adj[i][j];
    }
  }
  for(k=0;k<n;k++)
  {
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
        if(dist[i][k]+dist[k][j]<dist[i][j])
        dist[i][j]=dist[i][k]+dist[k][j];
      }
    }
  }
  for(i=0;i<n;i++)
  {
    if(dist[i][i]<0)
    return true;
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
  }
  if(negcycle())
  cout<<"Yes"<<endl;
  else
  cout<<"No"<<endl;
}
