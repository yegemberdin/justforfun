#include <iostream>
#include <queue>
using namespace std;
struct point
{
    int x,y;
    point(){}
    point(int X, int Y)
    {
        x = X; y = Y;
    }
};
int n;
bool correct(int x, int y)
{
    if (x<0 || y<0)
        return false;
    if (x>=n || y>=n)
        return false;
    return true;
}
int moveX[9]={0,2, 2, 1, 1,-1,-1,-2,-2};
int moveY[9]={0,1,-1, 2,-2, 2,-2, 1,-1};
bool mark[30][30];
int d[1000][1000];

int main()
{
	int x1,y1,x2,y2;
	cin>>n;
	cin>>x1>>y1>>x2>>y2;
	queue<point> q;
	q.push({x1, y1});
	mark[x1][y1]=true;

    d[x1][y1] = 0;
	
	while(!q.empty())
	{
		point cur=q.front();
        q.pop();

     	for(int i=1;i<=8;++i)
		{
			int x = cur.x + moveX[i];
            int y = cur.y + moveY[i];
            if (correct(x,y) && mark[x][y]==false)
            {
            	q.push({x, y});
            	mark[x][y]=true;
            	d[x][y]=d[cur.x][cur.y]+1;

                
            }
		}
	}
	cout << d[x2][y2];
    

	return 0;

}