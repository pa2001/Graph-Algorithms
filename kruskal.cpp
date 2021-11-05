#include<bits/stdc++.h>
using namespace std;
struct node {
	int parent;
	int rank;
};
struct Edge {
	int src;
	int dst;
	int wt;
};
vector<node> dsuf;
vector<Edge> mst;
int find(int v)
{
	if(dsuf[v].parent==-1)
		return v;
	return dsuf[v].parent=find(dsuf[v].parent);	
}
void union_op(int fromP,int toP)
{
	if(dsuf[fromP].rank > dsuf[toP].rank)	
		dsuf[toP].parent = fromP;
	else if(dsuf[fromP].rank < dsuf[toP].rank)
		dsuf[fromP].parent = toP;
	else
	{
		dsuf[fromP].parent = toP;
		dsuf[toP].rank +=1;
	}
}
bool comparator(Edge a,Edge b)
{
	return a.wt < b.wt;
}
void Kruskals(vector<Edge>& edge_List,int V,int E)
{
	sort(edge_List.begin(),edge_List.end(),comparator);
	int i=0,j=0;
	while(i<V-1 && j<E)
	{
		int fromP = find(edge_List[j].src);	
		int toP = find(edge_List[j].dst);
		
		if(fromP == toP)
		{	
      ++j;	
      continue;	
    }
		union_op(fromP,toP);
		mst.push_back(edge_List[j]);
		++i;
	}
}
void printMST(vector<Edge>& mst)
{
	cout<<"MST formed is\n";
	for(auto p: mst)
		cout<<"src: "<<p.src<<"  dst: "<<p.dst<<"  wt: "<<p.wt<<"\n";
}
int main()
{
	int E;
	int V;
	cin>>E>>V;
	dsuf.resize(V);
	for(int i=0;i<V;++i)
	{
		dsuf[i].parent=-1;
		dsuf[i].rank=0;
	}
	vector<Edge> edge_List;
	Edge temp;
	for(int i=0;i<E;++i)
	{
		int from,to,wt;
		cin>>from>>to>>wt;
		temp.src = from;
		temp.dst = to;
		temp.wt = wt;
		edge_List.push_back(temp);
	}
	Kruskals(edge_List,V,E);
	printMST(mst);	
	return 0;
}
