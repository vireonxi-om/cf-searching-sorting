// Problem: Stable Groups
// URL: https://codeforces.com/problemset/problem/1539/C
// Rating: 1200
// Tags: greedy, sortings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll k, x, a[210000];
multiset<ll> s;

int main(){
    scanf("%d%lld%lld", &n, &k, &x);
    for(int i=1; i<=n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a+1, a+n+1);
    int ans=1;
    for(int i=2; i<=n; i++){
        if(a[i]-a[i-1]<=x) continue;
        ans++;
        ll num=(a[i]-a[i-1])/x;
        if((a[i]-a[i-1])%x==0) num--;
        s.insert(num);
    }
    for(auto t:s){
        if(k>=t){
            k-=t;
            ans--;
        }
        else break;
    }
    printf("%d\n", ans);
}

