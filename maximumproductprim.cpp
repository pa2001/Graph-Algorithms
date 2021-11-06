#include <bits/stdc++.h>
using namespace std;
#define V 5
int minKey(int key[],bool mstSet[])
{
	int min = INT_MAX,min_index;
	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;
	return min_index;
}
void printMST(int parent[], int n, int graph[V][V])
{
	printf("Edge Weight\n");
	int minProduct = 1;
	for (int i = 1; i < V; i++) {
		printf("%d - %d %d \n",
			parent[i], i, graph[i][parent[i]]);
		minProduct *= graph[i][parent[i]];
	}
	printf("Minimum Obtainable product is %d\n",
		minProduct);
}
void primMST(int inputGraph[V][V], double logGraph[V][V])
{
	int parent[V]; 
	int key[V]; 
	bool mstSet[V];
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;
	key[0] = 0; 
	parent[0] = -1;
	for (int count = 0; count < V - 1; count++) {
		int u = minKey(key, mstSet);
		mstSet[u] = true;
		for (int v = 0; v < V; v++)
			if (logGraph[u][v] > 0 && mstSet[v] == false && logGraph[u][v] < key[v])
				parent[v] = u, key[v] = logGraph[u][v];
	}
	printMST(parent, V, inputGraph);
}
void minimumProductMST(int graph[V][V])
{
	double logGraph[V][V];
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (graph[i][j] > 0)
				logGraph[i][j] = log(graph[i][j]);
			else
				logGraph[i][j] = 0;
		}
	}
	primMST(graph, logGraph);
}
int main()
{
	int graph[V][V] = {
		{ 0, 2, 0, 6, 0 },
		{ 2, 0, 3, 8, 5 },
		{ 0, 3, 0, 0, 7 },
		{ 6, 8, 0, 0, 9 },
		{ 0, 5, 7, 9, 0 },
	};
	minimumProductMST(graph);

	return 0;
}
