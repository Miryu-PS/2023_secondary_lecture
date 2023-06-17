#include<bits/stdc++.h>
using namespace std;

int pa[1000005]; // pa[x] = x가 속한 집합의 대장(임시)

int find(int x) // x가 속한 그룹의 대장을 찾기
{
	if(x==pa[x]) return x; // 만약 x와 pa[x]가 같다면 대장
	else
	{
		int tmp = find(pa[x]); // 부모의 대장을 찾아서 저장
		pa[x] = tmp; // x의 대장도 tmp
		return tmp;
	}
}
void Union(int a, int b)
{
	a = find(a); b = find(b); // 쫄따구들끼리 할 얘기는 없다 대장 나와
	if(a != b) pa[b] = a;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int N,M; cin>>N>>M;
	for(int i=0; i<=N; i++) pa[i] = i; // 처음에는 모두 자신이 속한 그룹의 대장
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
