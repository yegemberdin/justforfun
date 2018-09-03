
#include <iostream>
 using namespace std;
 
int main(){
	int n;
	cin >> n;
	int a[n][n];
	int length = 0;
	for( int i=0 ; i<n ; i++ ){
		for( int j=0 ; j<n ; j++ ){
			cin >> a[i][j];
		}
	}
	for( int k=0 ; k<n ; k++ ){
		for( int i=0 ; i<n ; i++ ){
			for( int j=0 ; j<n ; j++ ){
				if(i != j && a[i][k] != -1 && a[k][j] != -1){
					if(a[i][j] == -1){
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