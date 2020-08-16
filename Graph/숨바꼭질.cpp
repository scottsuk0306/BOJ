// ¼û¹Ù²ÀÁú
#include <cstdio>
#include <vector>
#include <cstring> 
#include <algorithm>
#include <queue>
#include <stack> 
#define MAX_SIZE 100001
using namespace std;

int dist[MAX_SIZE];
int rec[MAX_SIZE];
stack<int> s;
int n, k;

void bfs(int x,int k){
	queue<int> q;
	q.push(x);
	dist[x] = 0;
	while(!q.empty()){
		x = q.front();
		q.pop();
		int dx1 = x+1;
		int dx2 = x-1;
		int dx3 = 2*x;
		if(0<=dx1&&dx1<=MAX_SIZE){
			if(dist[dx1]>(dist[x]+1)||dist[dx1]==-1){
				q.push(dx1);
				dist[dx1] = dist[x]+1;
				rec[dx1] = x;
			}
		}
		if(0<=dx2&&dx2<=MAX_SIZE){
			if(dist[dx2]>(dist[x]+1)||dist[dx2]==-1){
				q.push(dx2);
				dist[dx2] = dist[x]+1;
				rec[dx2] = x;
			}
		}
		if(0<=dx3&&dx3<=MAX_SIZE){
			if(dist[dx3]>dist[x]||dist[dx3]==-1){
				q.push(dx3);
				dist[dx3] = dist[x]+1;
				rec[dx3] = x;
			}
		}
	}
	while(k != n){
		s.push(k);
		k = rec[k];
	}
	s.push(n);
	
}

int main(){
	scanf("%d %d",&n,&k);
	memset(dist, -1, sizeof(dist));
	bfs(n,k);
	printf("%d\n",dist[k]);
	while(!s.empty()){
		printf("%d ",s.top());
		s.pop();
	}
	
} 
