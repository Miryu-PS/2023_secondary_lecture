#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll POW(ll x, ll y, ll z) // x^y%z
{
    if(y==0) return 1%z;
    ll tmp = POW(x,y/2,z); // x^y/2
    tmp = tmp*tmp%z; // y�� ¦���� tmp�� x^y Ȧ���� x�� �� �� �� ���ϸ� x^y
    if(y%2==1) tmp = tmp*x%z;
    return tmp;
}
int main()
{
    ll a,b,c; cin>>a>>b>>c;
    cout<<POW(a,b,c);
}
