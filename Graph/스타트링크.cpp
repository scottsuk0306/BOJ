// 스타트링크
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define MAX_SIZE 1000001

using namespace std;

int a[MAX_SIZE];
int dist[MAX_SIZE];
int F,S,G,U,D;

void bfs(int x){
	dist[x] = 0;
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		x = q.front();
		q.pop();
		int up = x+U;
		int down = x-D;
		if(1<=up&&up<=F){
			if(dist[up]==-1){
				q.push(up);
				dist[up]=dist[x]+1;
			}
		}
		if(1<=down&&down<=F){
			if(dist[down]==-1){
				q.push(down);
				dist[down]=dist[x]+1;
			}
		}
	}
}

int main(){
	scanf("%d %d %d %d %d",&F,&S,&G,&U,&D);
	memset(dist,-1,sizeof(dist));
	bfs(S);
	if(dist[G]==-1){
		printf("use the stairs");
	}
	else{
		printf("%d",dist[G]);
	}
	
	
}  
