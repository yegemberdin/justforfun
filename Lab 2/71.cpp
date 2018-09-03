#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct cow
{
	int x;
	int y;
	vector< pair< int, int > > v;
};
int px[9]={0,2, 2, 1, 1,-1,-1,-2,-2};
int py[9]={0,1,-1, 2,-2, 2,-2, 1,-1};
queue<cow> q;
cow p1,p2;
bool mark[30][30];
vector< pair< int,int> > temp,ans;
int main()
{
	int i,j,n,m,b,c,d,x1,y1,x2,y2;
	cin>>n;
	cin>>y1>>x1>>y2>>x2;
	mark[x1][y1]=true;
	temp.push_back(make_pair(x1,y1));
	p1.x=x1;
	p1.y=y1;
	p1.v=temp;	
	q.push(p1);
	while(!q.empty())
	{
		p1=q.front();
		q.pop();
		if(p1.x==x2 && p1.y==y2)
		{
			ans=p1.v;
			break;
		}
		for(i=1;i<=8;++i)
		{
			int x=p1.x+px[i];
			int y=p1.y+py[i];
			if( x>0 && y>0 && x<=n && y<=n && mark[x][y]==false)
			{
				mark[x][y]=true;
				temp=p1.v;
				temp.push_back(make_pair(x,y));
				p2.x=x;
				p2.y=y;
				p2.v=temp;
				q.push(p2);
			}
		}
	}
	cout<<ans.size()-1<<endl;
	for(i=0;i<ans.size();++i)
		cout<<ans[i].second<<" "<<ans[i].first<<endl;
	return 0;

}