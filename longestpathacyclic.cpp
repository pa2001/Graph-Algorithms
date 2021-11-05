#include<bits/stdc++.h>
using namespace std;
int a,b,c,n,m,e;
void DFS(vector< pair<int,int> > graph[], int src,int prev_len, int *max_len,vector <bool> &visited)
{
	visited[src] = 1;
	int curr_len = 0;
	pair < int, int > adjacent;
	for (int i=0; i<graph[src].size(); i++)
  {
    adjacent = graph[src][i];
    if (!visited[adjacent.first])
		{
      curr_len = prev_len + adjacent.second;
      DFS(graph, adjacent.first, curr_len,
				max_len, visited);
		}
    if ((*max_len) < curr_len)
			*max_len = curr_len;
      curr_len = 0;
	}
}
int longestCable(vector<pair<int,int>>graph[],int n)
{
  int max_len=INT_MIN;
  for (int i=1;i<=n; i++)
	{
    vector< bool > visited(n+1, false);
    DFS(graph, i, 0, &max_len, visited);
	}return max_len;
}

int main()
{
  cout<<"Enter number of edges and vertices-";
  cin>>n>>e;  
  vector<pair<int,int>>graph[e+1];
  for(int i=0;i<n;i++)
  {
    cin>>a>>b>>c;
    graph[a].push_back(make_pair(b,c));
  }cout<<longestCable(graph,n)<<endl;
}
