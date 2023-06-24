#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll len[50];
string st="Messi Gimossi";
char what(int x,int lvl)
{
    //cout<<x<<':'<<lvl<<" ";
	if(lvl<=2)
	{
		return st[x-1];
	}
	int t=len[lvl-1];
	if(x<=t) return what(x,lvl-1);
	if(x==t+1) return ' ';
	if(x>t+1) return what(x-t-1, lvl-2);
}
int main()
{
	len[1]=5;
	len[2]=13;
	for(int i=3;i<=41;i++)
	{
		len[i]=len[i-1]+len[i-2]+1;
	}
	//cout<<len[3];
	int n; cin>>n;
	char c=what(n,41);
	if(c==' ') cout<<"Messi Messi Gimossi";
	else cout<<c;
}
