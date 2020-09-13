// 숫자 카드 2
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d",&n);

    vector<int> a(n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    
    sort(a.begin(), a.end());

    int m;
    scanf("%d",&m);

    for (int i=0; i<m; i++) {
        int number;
        scanf("%d",&number);
        auto p = equal_range(a.begin(), a.end(), number);
        printf("%d ",p.second - p.first);
    }

    printf("\n");
    return 0;
} 
