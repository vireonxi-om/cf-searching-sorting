// Problem: Pursuit
// URL: https://codeforces.com/problemset/problem/1530/C
// Rating: 1200
// Tags: binary search, brute force, greedy, sortings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[110000], b[110000];

bool cal(int t){
    int cala=0, calb=0, now=t-t/4;
    if(t-now<n){
        cala=a[t-now+1]+100*(t-n);
        calb=b[max(1, n-now+1)];
        if(cala>=calb) return true;
        else return false;
    }
    else return true;
}

void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<=n; i++) scanf("%d", &b[i]);
    sort(a+1, a+n+1); sort(b+1, b+n+1);
    for(int i=n-1; i>=1; i--){
        a[i]=a[i+1]+a[i]; b[i]=b[i+1]+b[i];
    }
    int l=0, r=3*n, mid;
    int ans=4*n;
    while(l<r){
        mid=(l+r)/2;
        if(cal(mid+n)){ ans=min(ans, mid); r=mid;}
        else l=mid+1;
    }
    ans=min(ans, l);

    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
