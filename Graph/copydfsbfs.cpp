#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> g[1001];
bool check[1001];
int cnt=0;

int dfs(int node){
	check[node]=true;
	for(int i=0;i<g[node].size();i++){
		int next=g[node][i];
		if(check[next]==false){
			dfs(next);
		}
	}
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int from,to;
		scanf("%d %d",&from,&to);
		g[from].push_back(to);
		g[to].push_back(from);
	}
	for(int i=1;i<=n;i++){
		sort(g[i].begin(), g[i].end());
	}
	for(int i=1;i<=n;i++){
		if(check[i]) continue;
		cnt++;
		dfs(i);
	}
	printf("%d",cnt);
} 
