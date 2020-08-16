// ºù»ê 
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int a[301][301];
int map[301][301];
bool visited[301][301];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n,m;

void check_arr(){
	for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
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
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (a[nx][ny] != 0 && visited[nx][ny] == false) {
                    q.push(make_pair(nx,ny));
                    visited[nx][ny] = true;
                }
            }
        }
    }
}
int main() {
    scanf("%d %d",&n,&m);
    int maxi = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d",&a[i][j]);
            if(maxi<a[i][j]) maxi=a[i][j];
        }
    }
    if(maxi==0){
    	printf("0");
    	return 0;
	}
	int answer = 0;
    for(int k=0;k<=300;k++){
    	// change a
    	if(k!=0){
    		for (int i=0; i<n; i++) {
		        for (int j=0; j<m; j++) {
		        	if(a[i][j]>0){
		        		int temp = 0;
		        		for (int h=0; h<4; h++) {
				            int nx = i+dx[h];
				            int ny = j+dy[h];
				            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				            	if(a[nx][ny]==0) temp++;
				            }
		        		}
		        		map[i][j]=a[i][j]-temp;
		        		if(map[i][j]<0) map[i][j]=0;
					}
		        	
		        }
	    	}
	    //copy a
	    for (int i=0; i<n; i++) {
	        for (int j=0; j<m; j++) {
	        	a[i][j] = map[i][j];
	        	}
	    	}
		}
    	
	    
//	    printf("\n");
//	    check_arr();
//	    printf("\n");
	    
	    memset(visited,false,sizeof(visited));
	    int cnt = 0;
	    for (int i=0; i<n; i++) {
	        for (int j=0; j<m; j++) {
	            if (a[i][j] != 0 && visited[i][j] == false) {
	                bfs(i, j);
	                ++cnt;
	            }
	        }
	    }
	    // printf("%dth groups: %d\n",k,cnt);
	    if(cnt>=2){
        	answer = k;
        	break;
        	
		}
	}
    printf("%d\n",answer);
    return 0;
} 
