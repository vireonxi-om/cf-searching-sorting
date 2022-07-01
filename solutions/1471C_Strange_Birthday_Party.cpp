// Problem: Strange Birthday Party
// URL: https://codeforces.com/problemset/problem/1471/C
// Rating: 1300
// Tags: brute force, greedy, sortings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, a[310000], c[310000];
ll suf[310000], pre[310000];

void solve(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<=m; i++){ scanf("%d", &c[i]); pre[i]=pre[i-1]+c[i];}
    sort(a+1, a+n+1);
    suf[n+1]=0;
    for(int i=n; i>=1; i--){
        suf[i]=suf[i+1]+c[a[i]];
    }
    ll sum=suf[1];
    for(int k=1; k<=min(m, n); k++){
        ll del=suf[n-k+1]-pre[k];
        sum=min(sum, suf[1]-del);
    }
    printf("%lld\n", sum);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}