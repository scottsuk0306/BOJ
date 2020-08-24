#include <cstdio>
#include <algorithm>
#define MOD 9901
using namespace std;
int d[100001][3];

int f(int x, int y){
	if(x==1) return 1;
	else{
		if(d[x][y]>0){
			return d[x][y];
		}
		if(y==0){
			d[x][y]=f(x-1,0)+f(x-1,1)+f(x-1,2);
			d[x][y]%=MOD;
		}
		else if(y==1){
			d[x][y]=f(x-1,0)+f(x-1,2);
			d[x][y]%=MOD;
		}
		else{
			d[x][y]=f(x-1,0)+f(x-1,1);
			d[x][y]%=MOD;
		}
		return d[x][y]%MOD;
	}
}



int main(){
	int n;
	scanf("%d",&n);
	printf("%d",(f(n,0)+f(n,1)+f(n,2))%MOD);
}
