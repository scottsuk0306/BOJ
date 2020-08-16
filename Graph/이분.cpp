#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> g[20001];
int check[20001];
bool ok = false;

void dfs(int node,int group){
	check[node]=group;
	for(int i=0;i<g[node].size();i++){
		int next=g[node][i];
		if(check[next]==0){
			dfs(next,3-group);
		}
		else if(check[next]==group){
			ok=true;
			break;
		}
	}
	return;
}

int main(){
	int k;
	scanf("%d",&k);
	while(k--){
		int n,m;
		ok=false;
		memset(g,0,sizeof(g));
		memset(check,0,sizeof(check));
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			if(check[i]==0){
				dfs(i,1);
			}
		}
		if(ok) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
