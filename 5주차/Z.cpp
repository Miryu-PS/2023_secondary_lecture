#include<bits/stdc++.h>
using namespace std;
int z(int n, int r, int c) // n�ܰ�¥������ (r,c)�� �� ��°�� �湮�ϴ°�?
{
    if(n==0) return 0;
    int unit = (1<<(n-1)); // 2^(n-1);
    // n�ܰ��� �� ���� ���̴� 2unit, ��ü ���簢���� 1/4�� ���� = unit*unit
    if(r<unit && c<unit) return z(n-1,r,c);
    else if(r<unit && c>=unit) return unit*unit + z(n-1, r, c-unit);
    else if(r>=unit && c<unit) return unit*unit*2 + z(n-1, r-unit, c);
    else return unit*unit*3 + z(n-1, r-unit, c-unit);
}
int main()
{
    int n,r,c; cin>>n>>r>>c;
    cout<<z(n,r,c);
}
