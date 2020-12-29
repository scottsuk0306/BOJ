// 집합의 표현  
#include <cstdio>

using namespace std; 

int p[1000001];

int find(int x) {
    if (x == p[x]) return x;
    else return p[x] = find(p[x]);
}

int main () {
    int n, m, i, a, b, op;

    scanf("%d %d", &n, &m);

    for (i = 0; i <= n; i++) p[i] = i;

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &op, &a, &b);

        if (op == 0) {
            a = find(a);
            b = find(b);
            if (a > b) p[a] = b;
            else if (a < b) p[b] = a;
        }

        else if (op == 1) {
            a = find(a);
            b = find(b);
            if (a == b) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}
