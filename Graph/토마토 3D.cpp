// ≈‰∏∂≈‰ 3D 
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <tuple>
using namespace std;
int a[101][101][101];
int dist[101][101][101];
int dx[] = {0,0,1,-1,0,0};
int dy[] = {1,-1,0,0,0,0};
int dz[] = {0,0,0,0,-1,1};
int n,m,h;

int bfs(){
	int maxi = 0;
	queue<tuple<int,int,int>> q;
	for(int k=0;k<h;k++){
    	for (int i=0; i<n; i++) {
	        for (int j=0; j<m; j++) {
	            if(a[i][j][k]==1){
	            	q.push(make_tuple(i,j,k));
	            	dist[i][j][k] = 0;
				}
	        }
    	}
	}
	while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();
        for (int k=0; k<8; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            int nz = z+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && 0 <= nz && nz < h) {
            	if (a[nx][ny][nz] == 0 && dist[nx][ny][nz] == -1) {
                    q.push(make_tuple(nx,ny,nz));
                    dist[nx][ny][nz] = dist[x][y][z]+1;
                    maxi = max(maxi,dist[nx][ny][nz]);
                }
        	}
    	}
	}
	for(int k=0;k<h;k++){
    	for (int i=0; i<n; i++) {
	        for (int j=0; j<m; j++) {
	            if(dist[i][j][k]==-1) return -1;
	        }
    	}
	}
	return maxi;
}

int main() {
    scanf("%d %d %d",&m,&n,&h);
    memset(dist,-1,sizeof(dist));
    for(int k=0;k<h;k++){
    	for (int i=0; i<n; i++) {
	        for (int j=0; j<m; j++) {
	            scanf("%d",&a[i][j][k]);
	        }
    	}
	}
	// printf("%d",bfs());
    return 0;
}
