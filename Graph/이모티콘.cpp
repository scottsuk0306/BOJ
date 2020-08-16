// 이모티콘 
#include <cstdio>
#include <cstring> 
#include <algorithm>
#include <queue>
#define MAX_SIZE 1001
using namespace std;

int dist[MAX_SIZE][MAX_SIZE];
int k;

void bfs(int x,int y){ // x: 화면에 있는 이모티콘, y: 클립보드에 있는 이모티콘 
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));
	dist[x][y] = 0;
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if(x==k) return;
		int del_x = x-1;
		int del_y = y;
		int copy_x = x;
		int copy_y = x;
		int paste_x = x+y;
		int paste_y = y;
		if(0<=del_x&&del_x<=MAX_SIZE && 0<=del_y&&del_y<=MAX_SIZE){
			if(dist[del_x][del_y]>(dist[x][y]+1)||dist[del_x][del_y]==-1){
				q.push(make_pair(del_x,del_y));
				dist[del_x][del_y] = dist[x][y]+1;
			}
		}
		if(0<=copy_x&&copy_x<=MAX_SIZE && 0<=copy_y&&copy_y<=MAX_SIZE){
			if(dist[copy_x][copy_y]>(dist[x][y]+1)||dist[copy_x][copy_y]==-1){
				q.push(make_pair(copy_x,copy_y));
				dist[copy_x][copy_y] = dist[x][y]+1;
			}
		}
		if(0<=paste_x&&paste_x<=MAX_SIZE && 0<=paste_y&&paste_y<=MAX_SIZE){
			if(dist[paste_x][paste_y]>(dist[x][y]+1)||dist[paste_x][paste_y]==-1){
				q.push(make_pair(paste_x,paste_y));
				dist[paste_x][paste_y] = dist[x][y]+1;
			}
		}
	}
}

int main(){
	scanf("%d",&k);
	memset(dist, -1, sizeof(dist));
	bfs(1,0);
	int mini = MAX_SIZE;
	for(int i=0;i<MAX_SIZE;i++){
		if(dist[k][i] == -1) continue;
		if(mini>dist[k][i]){
			mini=dist[k][i];
		}
	}
	printf("%d",mini);
	return 0;
} 
