#include<bits/stdc++.h>
using namespace std;

int pa[1000005]; // pa[x] = x�� ���� ������ ����(�ӽ�)

int find(int x) // x�� ���� �׷��� ������ ã��
{
	if(x==pa[x]) return x; // ���� x�� pa[x]�� ���ٸ� ����
	else
	{
		int tmp = find(pa[x]); // �θ��� ������ ã�Ƽ� ����
		pa[x] = tmp; // x�� ���嵵 tmp
		return tmp;
	}
}
void Union(int a, int b)
{
	a = find(a); b = find(b); // �̵����鳢�� �� ���� ���� ���� ����
	if(a != b) pa[b] = a;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int N,M; cin>>N>>M;
	for(int i=0; i<=N; i++) pa[i] = i; // ó������ ��� �ڽ��� ���� �׷��� ����
	while(M--)
	{
		int c,a,b; cin>>c>>a>>b;
		if(c==0) Union(a,b);
		if(c==1)
		{
			if(find(a) == find(b)) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
}
