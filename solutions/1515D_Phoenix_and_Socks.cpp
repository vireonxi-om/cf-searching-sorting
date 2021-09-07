// Problem: Phoenix and Socks
// URL: https://codeforces.com/problemset/problem/1515/D
// Rating: 1500
// Tags: greedy, sortings, two pointers
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, x, y, l[210000], r[210000];

void solve(){
    scanf("%d%d%d", &n, &x, &y);
    for(int i=1; i<=n; i++) {l[i]=0; r[i]=0;}
    int c;
    for(int i=1; i<=x; i++) {
        scanf("%d", &c);
        l[c]++;
    }
    for(int i=1; i<=y; i++) {
        scanf("%d", &c);
        r[c]++;
    }
    int lt=0, rt=0, lcnt=0, rcnt=0;
    for(int i=1; i<=n; i++){
        int num=min(r[i], l[i]);
        if(num){
            l[i]-=num; r[i]-=num;
        }
        lt+=l[i]; lcnt+=l[i]/2;
        rt+=r[i]; rcnt+=r[i]/2;
    }
    int cnt=lcnt, ans=0;
    if(rt>lt){ cnt=rcnt; swap(lt, rt);}
    if((lt-rt)/2<=cnt) ans+=(lt+rt)/2;
    else ans+=lt-cnt;
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}

