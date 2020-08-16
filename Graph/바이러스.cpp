#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> g[101];
bool check[101];
int cnt = 0;

void dfs(int x){
	check[x] = true;
	cnt++;
	for(int i=0;i<g[x].size();i++){
		int y = g[x][i];
		if(check[y] == false){
			dfs(y);
		}
	}
}
int main(){
	int n, m;
    scanf("%d",&n);
    scanf("%d",&m);
    for (int i=0; i<m; i++) {
        int from, to;
        scanf("%d %d",&from,&to);
        g[from].push_back(to);
        g[to].push_back(from);
    }
    dfs(1);
    printf("%d",cnt-1);
    
}
