// 안전영역 
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int a[101][101];
bool visited[101][101];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n;

void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    visited[x][y] = true;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (a[nx][ny] != 0 && visited[nx][ny] == false) {
                    q.push(make_pair(nx,ny));
                    visited[nx][ny] = true;
                }
            }
        }
    }
}
int main() {
    scanf("%d",&n);
    int maxi = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d",&a[i][j]);
            if(maxi<a[i][j]) maxi=a[i][j];
        }
    }
    
	int answer = 1;
    for(int k=1;k<=maxi;k++){
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			a[i][j]-=1;
    			if(a[i][j]<0) a[i][j]=0;
			}
		} 
	    memset(visited,false,sizeof(visited));
	    int cnt = 0;
	    for (int i=0; i<n; i++) {
	        for (int j=0; j<n; j++) {
	            if (a[i][j] != 0 && visited[i][j] == false) {
	                bfs(i, j);
	                ++cnt;
	            }
	        }
	    }
	    if(cnt>answer) answer=cnt;
	}
    printf("%d\n",answer);
    return 0;
} 
