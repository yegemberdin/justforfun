#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack> 
using namespace std;
vector<string> mas;
const char grid = '#';
const char dot = '.';
int n,m;
struct point
{
    int x,y;
    point(){}
    point(int X, int Y)
    {
        x = X; y = Y;
    }
};
int moveX[4] = {-1,0,1,0};
int moveY[4] = {0,-1,0,1};
bool correct(int x, int y)
{
    if (x<0 || y<0)
        return false;
    if (x>=n || y>=m)
        return false;
    return true;
}
void dfs(int dx, int dy)
{
    stack<point> s;
    s.push(point(dx,dy));
    while (!s.empty())
    {
        point cur = s.top();
        s.pop();
        for (int i=0;i<4;i++)
        {
            int x = cur.x + moveX[i];
            int y = cur.y + moveY[i];
            if (correct(x,y) && mas[x][y] == grid)
            {
                mas[x][y] = dot;
                s.push(point(x,y));
            }
        }
    }
}

int main()

{
    cin>>n>>m;
    mas.resize(n);
    for (int i=0;i<n;i++)
        cin>>mas[i];
     int c=0;

     for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (mas[i][j] == grid)
            {
                dfs(i,j);
                c++;
            }
        }
    }
    cout<<c;

    return 0;
}