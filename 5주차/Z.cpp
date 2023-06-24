#include<bits/stdc++.h>
using namespace std;
int z(int n, int r, int c) // n단계짜리에서 (r,c)를 몇 번째로 방문하는가?
{
    if(n==0) return 0;
    int unit = (1<<(n-1)); // 2^(n-1);
    // n단계의 한 변의 길이는 2unit, 전체 정사각형의 1/4의 넓이 = unit*unit
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
