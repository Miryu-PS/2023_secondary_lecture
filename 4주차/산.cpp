#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
pii pa[1005][1005];
int arr[1005][1005];
int sz[1005][1005];
int H,W;
pii find(pii p)
{
	int x = p.first, y=p.second;
	if(p == pa[x][y]) return p;
	else return pa[x][y] = find(pa[x][y]);
}

void Union(pii x, pii y) // x <- y
{
	x = find(x); y = find(y);
	pa[y.first][y.second] = x;
	sz[x.first][x.second] += sz[y.first][y.second];
	sz[y.first][y.second] = 0;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>H>>W;
	for(int i=1; i<=H; i++) for(int j=1; j<=W; j++) 
	{
		cin>>arr[i][j];
		pa[i][j] = {i,j};
		sz[i][j] = 1;
	}
	for(int i=1; i<=H; i++) for(int j=1; j<=W; j++)
	{
		int mdx = 0, mdy = 0, mini = arr[i][j];
		for(int ii = -1; ii <= 1; ii++) for(int jj=-1; jj <= 1; jj++)
		{
			if(i+ii <= 0 || i+ii > H || j+jj <= 0 || j+jj > W) continue;
			if(arr[i+ii][j+jj] < mini) 
			{
				mini = arr[i+ii][j+jj];
				mdx = ii;
				mdy = jj;
			}
		}
		if(mdx != 0 || mdy != 0)
		{
			// (i,j) -> (i+mdx, j+mdy)
			Union({i+mdx, j+mdy}, {i,j});
		}
	}
	for(int i=1; i<=H; i++)
	{
		for(int j=1; j<=W; j++)
		{
			cout<<sz[i][j]<<' ';
		}
		cout<<'\n';
	}
}



/*
3 3
1 3 4
5 6 7
8 9 2
*/
