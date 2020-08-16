// ¼¶ÀÇ °³¼ö
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int a[51][51];
bool visited[51][51];
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
int w,h;

void bfs(int x, int y){
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));
	visited[x][y]=true;
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int k=0; k<8; k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(0 <= nx && nx < h && 0 <= ny && ny < w){
				if(a[nx][ny]==1&&visited[nx][ny]==false){
					q.push(make_pair(nx,ny));
					visited[nx][ny]=true;
				}
			}
		}
	}
}

int main(){
	while(true){
		scanf("%d %d",&w,&h);
		if (w==0&&h==0) break;
		memset(a,-1,sizeof(a));
		memset(visited,false,sizeof(visited));
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				scanf("%d",&a[i][j]);
			}
		}
		int cnt = 0;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(a[i][j]==1&&visited[i][j]==false){
					bfs(i,j);
					cnt++;	
				}
			}
		}
		printf("%d\n",cnt);
	}
	
}
 
