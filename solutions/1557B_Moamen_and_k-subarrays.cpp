// Problem: Moamen and k-subarrays
// URL: https://codeforces.com/problemset/problem/1557/B
// Rating: 1100
// Tags: greedy, sortings
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = n - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 110000;
const int M = 1100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;

int n, k;
LL a[N];
vector<LL> b;

bool check(int i) {
    if (i == n) return false;
    auto it = upper_bound(b.begin(), b.end(), a[i]);
    if (it != b.end() && a[i + 1] == (*it)) return true;
    else return false;
}


void solve(){
    scanf("%d%d", &n, &k);
    b.clear();
    repn(i, 1, n) {
        scanf("%lld", &a[i]);
        b.pb(a[i]);
    }
    sort(all(b));
    int i = 1, cnt = 0;
    while(i <= n) {
        while (check(i)) i++;
        cnt ++;
        i ++;
    }
    if (cnt <= k) printf("Yes\n");
    else printf("No\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}
