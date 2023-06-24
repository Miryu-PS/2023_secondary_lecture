#include<bits/stdc++.h>
using namespace std;
using ll = long long;
char c[2200][2200];
void draw(int n, int x, int y) // (x,y)를 왼쪽 위로 해서 n단계를 그려라 
{
  if(n==1) {c[x][y] = '*';return ;}
  for(int i=0; i<3;i++) for(int j=0; j<3; j++)
  {
    if(i==1 && j==1) continue;
    draw(n/3, x+i * n/3, y+j * n/3);
  }
  
}
int main()
{
  int N; cin>>N;
  fill(&c[0][0], &c[2199][2200], ' ');
  draw(N, 0, 0);
  for(int i=0; i<N; i++) {for(int j=0; j<N; j++) cout<<c[i][j]; cout<<'\n';}
}

