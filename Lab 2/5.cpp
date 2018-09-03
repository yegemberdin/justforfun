#include <iostream>
using namespace std; 
int arr[111][111];
int e1, e2;
int n, m;
bool hasWay;
void dfs(int a, int b) {
    if (a == e1 && b == e2) {
            hasWay = true;
            arr[a][b] = 3;
            cout<<"Yes\n";
            for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= m; j++) {
                                cout<<arr[i][j];
                    }
                    cout<<"\n";
            }
            return;
    }
    arr[a][b] = 2;
    if (arr[a + 1][b] == 0) {
    	dfs(a + 1, b);
        }
    if (arr[a - 1][b] == 0) {
        dfs(a - 1, b);
        }
    if (arr[a][b + 1] == 0) {
        dfs(a, b + 1);
        }
    if (arr[a][b - 1] == 0) {
        dfs(a, b - 1);
        }


}
int main(){   


    cin >> n>>m;
    int s1, s2;
    hasWay=false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    cin>>e1>>e2>>s1>>s2;
    if(arr[s1][s2]==1 || arr[e1][e2]==1){
    	cout<<"NO\n";

    }
    else{
    	dfs(s1,s2);
    	if(!hasWay){
    		cout<<"NO\n";
    		for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= m; j++) {
                                cout<<arr[i][j];
                    }
                    cout<<"\n";
            }
    	}
    }



   


    

    return 0;
}