// ÃÌ¼ö°è»ê
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define MAX_SIZE 101

using namespace std;

vector<int> v[MAX_SIZE];
int dist[MAX_SIZE];

void bfs(int x){
	dist[x] = 0;
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		x = q.front();
		q.pop();
		for(int i=0;i<v[x].size();i++){
			if(dist[v[x][i]]==-1){
				q.push(v[x][i]);
				dist[v[x][i]] = dist[x]+1;
			} 
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int a,b;
	scanf("%d %d",&a,&b);
	int m;
	scanf("%d",&m);
	memset(dist,-1,sizeof(dist));
	for(int i=1;i<=m;i++){
		int from, to;
		scanf("%d %d",&from, &to);
		v[from].push_back(to);
		v[to].push_back(from);
	}
	bfs(a);
	printf("%d",dist[b]);
	
} 
