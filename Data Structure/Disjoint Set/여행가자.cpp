// 여행 가자
#include <cstdio>
#define MAX_SIZE 201 
int map[MAX_SIZE][MAX_SIZE];
int travel[1001];
int root[MAX_SIZE];
int rank[MAX_SIZE];
void set() {
	for (int i = 0; i < MAX_SIZE; i++) {
		root[i] = i;
		rank[i] = 0;
	}
} 


int find(int x) {
    if (root[x] == x) {
        return x;
    } else {
        return find(root[x]);
    }
}

void union1(int x, int y) {
   x = find(x);
   y = find(y);

   if(x == y)
     return;

   if(rank[x] < rank[y]) {
     root[x] = y;
   } else {
     root[y] = x;

     if(rank[x] == rank[y])
       rank[x]++;
   }
}

int main() {
	int n, num;
	scanf("%d",&n);
	scanf("%d",&num);
	set();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&map[i][j]);
			if(map[i][j]) union1(i,j);
		}
	}
	scanf("%d",&travel[1]);
	int p = find(travel[1]);
	for(int i=2;i<=num;i++){
		scanf("%d",&travel[i]);
		if(p!=find(travel[i])){
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
	
}
