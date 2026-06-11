// Problem: Diamond Miner
// URL: https://codeforces.com/problemset/problem/1496/C
// Rating: 1200
// Tags: geometry, greedy, sortings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
vector<int> a, b;

void solve(){
    scanf("%d", &n);
    a.clear(); b.clear();
    int num;
    for(int i=1; i<=2*n; i++){
        scanf("%d", &num);
        if(num==0){ scanf("%d", &num); b.push_back(abs(num));}
        else{
            a.push_back(abs(num));
            scanf("%d", &num);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    double ans=0;
    for(int i=0; i<n; i++){
        ans+=sqrt((double)a[i]*a[i]+(double)b[i]*b[i]);
    }
    printf("%.15f\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
