#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> g[1001];
bool check[1001];

int dfs(int x){
	check[x] = true;
	printf("%d ",x);
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(check[y]==false){
			dfs(y);
		}
	}
}

int bfs(int start){
	queue<int> q;
	memset(check,false,sizeof(check));
	check[start]=true;
	q.push(start);
	while(!q.empty()){
		int node=q.front();
		q.pop();
		printf("%d ",node);
		for(int i=0;i<g[node].size();i++){
			int next=g[node][i];
			if(check[next]==false){
				check[next]=true;
				q.push(next);
			}
		}
	}
}

int main(){
	int n,m,v;
	scanf("%d %d %d",&n,&m,&v);
	// cin>>n>>m>>v;
	for(int i=0;i<m;i++){
		int from,to;
		scanf("%d %d",&from,&to);
		g[from].push_back(to);
		g[to].push_back(to);
	}
	for(int i=1;i<=n;i++){
		sort(g[i].begin(),g[i].end());
	}
	dfs(v);
	puts("");
	bfs(v);
	puts("");
	return 0;
}

