#include<bits/stdc++.h>
using namespace std;
string S, T;
int n,m; 

//91869542
//6985
int tdel[10]; // tdel[i] �� ������ �ϴ� i�� ����
//tdel (5 ,6, 8,9)
int usable[10]; // usable[i]�� �信�� ��밡���� i�� ����
//usable (1,2,4,9)
bool pos(int& posi, int& del, int x) // posi ���� ���鼭 �ִ� del���� ������ �� x�� �� �� �ִ°�? 
{
	if(usable[x] == 0) return false; // ���ʿ� x�� �� �� ���ٸ� false
	int tmp[10]; memset(tmp, 0, sizeof(tmp));
	int i;
	for(i=posi; i<posi+del && (S[i]-'0') != x; i++) { // ���� ����� x�� ã�´�.
		tmp[S[i] - '0']++; // ���� ����� x�� ã����� ��� ���� �������Ѵ�.
		if(tmp[S[i] - '0'] > tdel[S[i] - '0']) return false; // ���� ������ �ϴ� �ͺ��� ���� ����ٸ� �ȵȴ�.
	}
	if(S[i]-'0' != x) return false; // x�� �� ã�� ��� false
	// i ��ġ�� �ִ� x�� ã�Ұ�, x�� ���� ���ؼ� a��� ���� tmp[a]�� ����� �ȴ�.
	
	for(int i=1; i<10; i++) tdel[i] -= tmp[i]; // tmp �迭�� ���� �����
	del -= (i-posi); // posi ~ (i-1) ���� ���� �����
	posi = i+1; // ���� �� ���� i+1������ ���� �ȴ�
	usable[x]--; // x�� �� �� ���
	return true; // ����!
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>S>>T;
	for(auto i:S) usable[i-'0']++;
	for(auto i:T) tdel[i-'0']++, usable[i-'0']--;
	int n = S.size(), m = T.size();
	int nowpos = 0, del = m;
	for(int i=0; i<n-m; i++) // nowpos ���Ŀ��� ���� i�� ���ڸ� ã�´�.
	{
		for(int j=9; j; j--) // �� ���� ���� �ִ��� ũ��!
		{
			if(pos(nowpos, del, j)) // S�� nowpos��° �ڸ����� ���� �� �ִ� del���� ������ �� ���ڸ��� j�� ����� �ִ°�?
			{
				cout<<j; break;
			}
		}
	}
}

