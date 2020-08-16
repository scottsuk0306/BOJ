// ¹Ì·Î Å½»ö
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n,m;
int a[101][101];
bool visited[101][101];
int dist[101][101];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void bfs(int x, int y){
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));
	visited[x][y]=true;
	dist[x][y]=1;
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx=x+dx[k];
			int ny=y+dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (a[nx][ny] == 1 && visited[nx][ny] == false) {
                    q.push(make_pair(nx,ny));
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[x][y]+1;
                }
            }
		}
	}
}


int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&a[i][j]);
		}
	}
	bfs(0,0);
	printf("%d",dist[n-1][m-1]);
} 
