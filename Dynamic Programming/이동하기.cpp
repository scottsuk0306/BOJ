// 이동하기
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int d[101][101];
int memo[101][101];
int dx[] = {1,0};
int dy[] = {0,1};
int n,m;

int go(int x, int y){
	if(x==n-1&&y==m-1){
		return d[n-1][m-1];
	}
	if(memo[x][y]>=0){
		return memo[x][y];
	}
	for(int i=0;i<3;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(0<=nx&&nx<n&&0<=ny&&ny<m){
			memo[x][y]=max(memo[x][y],d[x][y]+go(nx,ny));
		}
	}
	return memo[x][y];
}

int main(){
	memset(memo,-1,sizeof(memo));
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&d[i][j]);
		}
	}
	printf("%d",go(0,0));
}
