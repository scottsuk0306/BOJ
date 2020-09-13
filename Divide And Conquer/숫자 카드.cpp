#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n, m;
int a[500000];
int binary_search(int num) {
    int l = 0;
    int r = n-1;
    while (l <= r) {
        int mid = (l+r)/2;
        if (a[mid] == num) {
//        	// lower bound
//			ans = mid;
//			right = mid-1; 
//			// upper bound
//			ans = mid+1;
//			left = mid+1;
            return 1;
        } else if (a[mid] > num) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return 0;
}
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    scanf("%d",&m);
    while (m--) {
        int num;
        scanf("%d",&num);
        printf("%d ",binary_search(num));
    }
    printf("\n");
    return 0;
}
