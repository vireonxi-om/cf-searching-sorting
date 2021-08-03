// Problem: Mean Inequality
// URL: https://codeforces.com/problemset/problem/1526/A
// Rating: 800
// Tags: constructive algorithms, sortings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[60];

void solve(){
    scanf("%d", &n);
    for(int i=1; i<=2*n; i++){
        scanf("%d", &a[i]);
    }
    sort(a+1, a+2*n+1);
    for(int i=1; i<=n; i++){
        printf("%d %d ", a[2*n+1-i], a[i]);
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}


