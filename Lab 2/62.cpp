#include <iostream>
using namespace std; 

char mas[100][100]; 

void dfs(int i, int j) 
{
	mas[i][j]=' '; 
	if(mas[i+1][j]=='#')
		dfs(i+1,j); 
	if(mas[i-1][j]=='#') 
		dfs(i-1,j); 
	if(mas[i][j+1]=='#') 
		dfs(i,j+1); 
	if(mas[i][j-1]=='#') 
		dfs(i,j-1); 


} 
int main() 
{ 
int n,m;
int cnt=0; 

cin>>n>>m; 

for(int i=0; i<n; i++) 
	for(int j=0; j<m; j++) 
		cin>>mas[i][j]; 
	

for(int i=0 ; i<n ; i++) 
{ 
	for(int j=0 ; j<m ; j++) 
		{ 
			if(mas[i][j]=='#') 
				dfs(i,j),cnt++; 
} 
} 
cout<<cnt; 
}