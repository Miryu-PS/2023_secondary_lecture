#include<bits/stdc++.h>
using namespace std;
int pa[111111], num[111111]; // num[i]�� i�� ��ǥ�� �ִ� ���ÿ��տ� ���� ������ ��
int unum; // ���� ������ ��
int maxsize; // ���� ������ �ְ�ũ��
int find(int x){
	if(x==pa[x]) return x;
	return pa[x] = find(pa[x]);
}
void union_(int x, int y) {
	x = find(x); y = find(y);
	if(x == y) return ;
	//x�� y�� ����. y�� x�� ���Խ�Ŵ
	pa[y] = x;
	num[x] += num[y]; 
	unum --; // ���� ������ �� 1 ����
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
