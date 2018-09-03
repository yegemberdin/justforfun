
#include <iostream>
 using namespace std;
 
int main(){
	int n,m;
	cin >> n>>m;
	int a[101][101];
	int d[101][101];
	int length = 0;
	for( int i=0 ; i<m ; i++ ){
		for( int j=0 ; j<3 ; j++ ){
			cin >> d[i][j];
		}
	}
	for( int i=0 ; i<m ; i++ ){
		for( int j=0 ; j<3 ; j++ ){
			int s=d[i][0];
            int f=d[i][1];
            a[s][f]=d[i][2];
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    if(i==s && j==f){
                        a[i][j]=a[s][f];
                        a[j][i]=a[s][f];
                    }
                }
            }
		}
	}
	
	for( int k=0 ; k<n ; k++ ){
		for( int i=0 ; i<n ; i++ ){
			for( int j=0 ; j<n ; j++ ){
				if(i != j && a[i][k] != -1 && a[k][j] != -1){
					if(a[i][j] > a[i][k] + a[k][j]){
						a[i][j] = a[i][k] + a[k][j];
					}
						else
					{
						a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
					}
				}
			}
		}
	}
	for( int i=0 ; i<n ; i++ )
	{
		for( int j=0 ; j<n ; j++ )
		{
			if(a[i][j] > length) length = a[i][j];
		}
	}
	cout << length << endl;
}