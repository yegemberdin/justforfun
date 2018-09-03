#include <iostream>
using namespace std;
int path[1111][1111];
int d[1111][1111];
const int INF=10000000;
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; ++i){
            for (int j=1; j<=n; ++j){
                d[i][j]=INF;
        }
    }
    for(int p=1;p<=m;++p){
        for(int z=1;z<=3;++z){
            cin>>path[p][z];
        }
    }
    for(int p=1;p<=m;++p){
        for(int z=1;z<=3;++z){
            int s=path[p][1];
            int f=path[p][2];
            d[s][f]=path[p][3];
            for (int i=1; i<=n; ++i){
                for (int j=1; j<=n; ++j){
                    if(i==s && j==f){
                        d[i][j]=d[s][f];
                        d[j][i]=d[s][f];
                    }
                }
            }
        }
    }
    for (int k=1; k<=n; ++k){
        for (int i=1; i<=n; ++i){
            for (int j=1; j<=n; ++j){
                if (d[i][k] < INF && d[k][j] < INF){}
                    d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int max=0;
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=n; ++j){
                if(d[i][j] > max && d[i][j]<INF)
                    max=d[i][j];
        }
    }
    cout<<max;
    return 0;
}