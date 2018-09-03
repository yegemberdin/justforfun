#include <iostream>
#include <vector>

using namespace std;

int n;
int cnt=0;
int a[111][111];
bool used[111];
vector<int>g[100100];

void dfs(int v) {
    used[v] = true;
    for (int i = 0; i <g[v].size(); i++) {
        int u=g[v][i];
        if (used[u] == false) {
            dfs(u);
            cnt++;
            
        }
    }
}

int main(){    

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
   

    int total = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i < j && a[i][j] == 1) {
                total++;
            }
        }
    }
    dfs(1);
    cout<<total-cnt;//for calculating unused edges

    

    return 0;
}