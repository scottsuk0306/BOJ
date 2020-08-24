// ¸»ÀÌ µÇ°íÇÂ ¿ø¼þÀÌ 
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int map[201][201];
bool visited[201][201];
int dist[201][201];
int dx[] = {-2,-1,1,2,2,1,-1,-2,0,1,-1,0};
int dy[] = {1,2,2,1,-1,-2,-2,-1,1,0,0,-1};
int k,w,h;

int bfs(int x, int y, int cnt){
	queue<pair<int,int> > q;
	q.push(make_pair(x,y));
	visited[x][y]=true;
	dist[x][y]=0;
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if(cnt--){
			for(int k=0;k<8;k++){
			int nx=x+dx[k];
			int ny=y+dy[k];
			if (0 <= nx && nx < w && 0 <= ny && ny < h && map[nx][ny]!=1) {
				//printf("this point is possible: %d %d",nx,ny);
                if (visited[nx][ny] == false || dist[nx][ny]>dist[x][y]+1) {
                    q.push(make_pair(nx,ny));
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[x][y]+1;
	            }
	        }
			}
		}
		else{
			for(int k=8;k<12;k++){
			int nx=x+dx[k];
			int ny=y+dy[k];
			if (0 <= nx && nx < w && 0 <= ny && ny < h && map[nx][ny]!=1) {
                if (visited[nx][ny] == false || dist[nx][ny]>dist[x][y]+1) {
                    q.push(make_pair(nx,ny));
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[x][y]+1;
		            }
				}
			}
		}
	}
	if(visited[w-1][h-1]==false) return -1;
	return dist[w-1][h-1];
}


int main(){
	memset(dist,400,sizeof(dist));
	scanf("%d",&k);
	scanf("%d %d",&h,&w);
	for(int i=0;i<w;i++){
		for(int j=0;j<h;j++){
			scanf("%d",&map[i][j]);
		}
	}
	int ans=400;
	for(int t=0;t<=k;t++){
		int temp=bfs(0,0,t);
		if(ans>temp&&temp!=-1) ans=temp;
		memset(visited,false,sizeof(visited));
		memset(dist,400,sizeof(dist));
	}
	printf("%d",ans);
} 
