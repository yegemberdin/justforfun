#include <iostream>
using namespace std;
int d[101][101];
const int INF=10000000;
int main() 
{
	int n,s,f;
	cin>>n>>s>>f;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			cin>>d[i][j];
			if(d[i][j]==-1)
				d[i][j]=INF;
		}
	for (int k=1; k<=n; ++k)
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=n; ++j)
				if (d[i][k] < INF && d[k][j] < INF)
					d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
	if(d[s][f]==INF)
		cout<<-1;
	else
		cout<<d[s][f];
	return 0;
}