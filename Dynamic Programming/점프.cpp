// มกวม
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int d[101][101];
long long int memo[101][101];
int n;
int dx[] = {1,0};
int dy[] = {0,1};

long long int go(int x, int y){
	if(x==n-1&&y==n-1){
		return 1;
	}
	if(memo[x][y]>0){
		return memo[x][y];
	}
	if(d[x][y]==0){
		return 0;
	}
	for(int i=0;i<3;i++){
		int nx = x+dx[i]*d[x][y];
		int ny = y+dy[i]*d[x][y];
		if(0<=nx&&nx<n&&0<=ny&&ny<n){
			memo[x][y]+=go(nx,ny);
		}
	}
	return memo[x][y];
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&d[i][j]);
		}
	}
	printf("%lld",go(0,0));
} 
