#include<bits/stdc++.h>
using namespace std;
string S, T;
int n,m; 

//91869542
//6985
int tdel[10]; // tdel[i] 는 지워야 하는 i의 개수
//tdel (5 ,6, 8,9)
int usable[10]; // usable[i]는 답에서 사용가능한 i의 개수
//usable (1,2,4,9)
bool pos(int& posi, int& del, int x) // posi 부터 보면서 최대 del개를 지워서 수 x를 고를 수 있는가? 
{
	if(usable[x] == 0) return false; // 애초에 x를 쓸 수 없다면 false
	int tmp[10]; memset(tmp, 0, sizeof(tmp));
	int i;
	for(i=posi; i<posi+del && (S[i]-'0') != x; i++) { // 가장 가까운 x를 찾는다.
		tmp[S[i] - '0']++; // 가장 가까운 x를 찾기까지 모든 수는 지워야한다.
		if(tmp[S[i] - '0'] > tdel[S[i] - '0']) return false; // 내가 지워야 하는 것보다 많이 지운다면 안된다.
	}
	if(S[i]-'0' != x) return false; // x를 못 찾은 경우 false
	// i 위치에 있는 x를 찾았고, x를 고르기 위해서 a라는 수는 tmp[a]개 지우면 된다.
	
	for(int i=1; i<10; i++) tdel[i] -= tmp[i]; // tmp 배열에 맞춰 지우기
	del -= (i-posi); // posi ~ (i-1) 까지 전부 지우고
	posi = i+1; // 다음 고를 수는 i+1번부터 보면 된다
	usable[x]--; // x를 한 번 썼다
	return true; // 가능!
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>S>>T;
	for(auto i:S) usable[i-'0']++;
	for(auto i:T) tdel[i-'0']++, usable[i-'0']--;
	int n = S.size(), m = T.size();
	int nowpos = 0, del = m;
	for(int i=0; i<n-m; i++) // nowpos 이후에서 답의 i번 숫자를 찾는다.
	{
		for(int j=9; j; j--) // 맨 앞의 수는 최대한 크게!
		{
			if(pos(nowpos, del, j)) // S의 nowpos번째 자리부터 봤을 때 최대 del개를 지워서 맨 앞자리를 j로 만들수 있는가?
			{
				cout<<j; break;
			}
		}
	}
}

