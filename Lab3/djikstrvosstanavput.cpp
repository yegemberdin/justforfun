#include <iostream>
using namespace std;
int d[101][101];
const int INF=10000000;
int weights[101];
bool used[101];
int n, s, f;
int min_vertex()
{
	int m = INF, index = -1;
	for (int i = 0; i < n; i++) {
		if (!used[i] && weights[i] <= m) {
			m = weights[i];
			index = i;
		}
	}
	return index;
}

void djikstra()
{
	int ind;
	ind = min_vertex();
	if (weights[ind] == INF || ind == -1) {
		return;
	}
	for (int i = 0; i < n; i++) {
		if (d[i][ind] != -1 && i != ind) {
			weights[i] = min(weights[i], weights[ind] + d[i][ind]);
		}
	}
	used[ind] = true;
	djikstra();
}
 
void path(int cur)
{
	int min = INF, ind;
	cout << cur+1  << " ";
	if (cur == f-1) {
		return;
	}
	for (int i = 0; i < n; i++) {
		if (i != cur && d[cur][i] != -1 && weights[i] < min && weights[cur] == weights[i] + d[cur][i]) {
			min = weights[i];
			ind = i;
		}
	}
	path(ind);
}

int main()
{
	cin >> n >> s >> f;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> d[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		used[i] = false;
		weights[i] = INF;
	}	
	weights[f - 1] = 0;
	djikstra();
	if (weights[s ] == INF) {
		cout << -1;
	}
	else {
		path(s-1);
	}
}