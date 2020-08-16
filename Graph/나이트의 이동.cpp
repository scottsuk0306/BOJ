// 나이트의 이동 
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
bool visited[301][301];
int dist[301][301];
int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};

int bfs(int x, int y, int x1, int y1, int size){
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));
	visited[x][y]=true;
	dist[x][y]=0;
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int k=0;k<8;k++){
			int nx=x+dx[k];
			int ny=y+dy[k];
			if (0 <= nx && nx < size && 0 <= ny && ny < size) {
                if (visited[nx][ny] == false) {
                    q.push(make_pair(nx,ny));
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[x][y]+1;
                }
            }
		}
	}
	return dist[x1][y1];
}


int main(){ 
	int t;
	scanf("%d",&t);
	while(t--){
		memset(dist,0,sizeof(dist));
		memset(visited,false,sizeof(visited));
		int size;
		scanf("%d",&size);
		int x,y,x1,y1;
		scanf("%d %d",&x,&y);
		scanf("%d %d",&x1,&y1);
		int ans = bfs(x,y,x1,y1,size); 
		printf("%d\n",ans);
	}
} 
