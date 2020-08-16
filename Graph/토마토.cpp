// ≈‰∏∂≈‰ wrong code 
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n,m;
int a[1001][1001];
bool visited[1001][1001];
int dist[1001][1001];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int bfs(int x, int y){
	int maxi = 0;
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));
	visited[x][y]=true;
	dist[x][y]=0;
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx=x+dx[k];
			int ny=y+dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (a[nx][ny] == 0 && visited[nx][ny] == false) {
                    q.push(make_pair(nx,ny));
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[x][y]+1;
                    maxi = max(maxi,dist[nx][ny]);
                }
            }
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==0&&visited[i][j]==false){
				return -1;
			}
		}
	}
	return maxi;
}


int main(){
	scanf("%d %d",&m,&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int check = 0;
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			if(a[i][j]==1 && visited[i][j]==false){
//				check = bfs(i,j);
//				memset(visited,sizeof(visited),false);
//			}
//		}
//	}
	// bfs(0,0);
	bfs(n-1,m-1); 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",dist[i][j]);
		}
		printf("\n");
	}
	printf("%d",check);
} 
