#include<bits/stdc++.h>
using namespace std;
int pa[111111], num[111111]; // num[i]는 i가 대표로 있는 도시연합에 속한 도시의 수
int unum; // 도시 연합의 수
int maxsize; // 도시 연합의 최고크기
int find(int x){
	if(x==pa[x]) return x;
	return pa[x] = find(pa[x]);
}
void union_(int x, int y) {
	x = find(x); y = find(y);
	if(x == y) return ;
	//x와 y를 병합. y를 x에 편입시킴
	pa[y] = x;
	num[x] += num[y]; 
	unum --; // 도시 연합의 수 1 감소
	maxsize = max(maxsize, num[x]);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m; cin>>n>>m; 
	for(int i=1; i<=n; i++) pa[i]=i, num[i]=1;
	unum = n;
	while(m--)
	{
		int x,y; cin>>x>>y;
		union_(x,y);
		cout<<unum<<" "<<maxsize<<'\n';
	}
}
