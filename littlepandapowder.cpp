#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define NN  1000001

int euler(int n) {
    int ac = n;
    for (int p=2; p*p<=n; p++) if (n%p==0) {
        ac -= ac/p;
        do n /= p; while (n%p==0);
    }
    if (n>1) ac -= ac/n;
    return ac;
}
int modpow(int a, int b, int M) {
    if (!b) return 1;
    int t = modpow(a,b/2,M);
    t = (t*(long)t) % M;
    if (b&1) t = (t*(long)a) % M;
    return t;
}
int test() {
    int A,B,X;
    cin >> A >> B >> X;
    if (X==1) return 0;
    int ph = euler(X);

    B %= ph; if (B<0) B+=ph;
    return modpow(A,B,X);
}

int main() {
  
    int T;
    cin >> T;
    while (T-->0) cout << test() << endl;
    return 0;
}

