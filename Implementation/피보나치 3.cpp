#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
typedef vector<vector<long long>> matrix;
const long long mod = 1000000000LL;
matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<long long>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= mod;
        }
    }
    return c;
}
int main() {
    long long n;

    cin >> n;
    if(n>0) cout << 1 << '\n';
    else if(n==0) cout << 0 << '\n';
    else{
    	if(n%2==0) cout << -1 << '\n';
    	else cout << 1 << '\n';
	}
    
    if(n<0) n = -n; 

    if (n <= 1) {
        cout << n << '\n';
        return 0;
    }

    matrix ans = {{1, 0}, {0, 1}};
    matrix a = {{1, 1}, {1, 0}};

    while (n > 0) {
        if (n % 2 == 1) {
            ans = ans * a;
        }
        a = a * a;
        n /= 2;
    }

    cout << ans[0][1] << '\n';

    return 0;
}
