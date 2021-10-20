// Problem: Arena
// URL: https://codeforces.com/problemset/problem/1487/A
// Rating: 800
// Tags: implementation, sortings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, cnt[110];

void solve(){
    scanf("%d", &n);
    for(int i=1; i<=100; i++) cnt[i]=0;
    int m=1000, num;
    for(int i=1; i<=n; i++){
        scanf("%d", &num);
        cnt[num]++;
        if(num<m) m=num;
    }
    printf("%d\n", n-cnt[m]);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
