#include <bits/stdc++.h>
using namespace std;
int N;
int sol[100][100];
	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int isSafe(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < N
			&& sol[x][y] == -1);
}
void printSolution()
{
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++)
			cout <<sol[x][y] << " ";
		cout << endl;
	}
}
bool solveKTUtil(int x, int y, int movei)
{
	int k, next_x, next_y;
	if (movei == N * N)
		return 1;
	for (k = 0; k < 8; k++) {
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if (isSafe(next_x, next_y)) {
			sol[next_x][next_y] = movei;
			if (solveKTUtil(next_x, next_y, movei + 1)
				== 1)
				return 1;
			else
				sol[next_x][next_y] = -1;
		}
	}
	return 0;
}
int main()
{	
  cin>>N;
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			sol[x][y]=-1;
	sol[0][0] = 0;
	if (solveKTUtil(0, 0, 1) == 0) {
		cout << "Solution does not exist";
	}
	else
		printSolution();
	return 0;
}
