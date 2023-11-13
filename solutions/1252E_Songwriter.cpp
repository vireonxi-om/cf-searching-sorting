// Problem: Songwriter
// URL: https://codeforces.com/problemset/problem/1252/E
// Rating: 2200
// Tags: greedy, two pointers
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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 110000;
const int M = 510000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-15;

int n;
LL L, R, k;
LL a[N];
pair<LL, LL> r[N];
LL ans[N];


int main() {
    scanf("%d%lld%lld%lld", &n, &L, &R, &k);
    repn(i, 1, n) scanf("%lld", &a[i]);
    bool can = true;
    r[n] = mp(L, R);
    pern(i, 1, n - 1) {
        if (a[i] > a[i + 1]) {
            r[i].se = min(R, r[i + 1].se + k);
            r[i].fi = r[i + 1].fi + 1;
        }
        else if (a[i] == a[i + 1]) {
            r[i].se = r[i + 1].se;
            r[i].fi = r[i + 1].fi;
        }
        else {
            r[i].fi = max(L, r[i + 1].fi - k);
            r[i].se = r[i + 1].se - 1;
        }
        if (r[i].fi > r[i].se) {can = false; break;}
    }
    if (can) {
        pair<LL, LL> now, cur;
        LL last = r[1].fi; ans[1] = last;
        repn(i, 2, n) {
            if (a[i] > a[i - 1]) {
                now.se = min(R, last + k);
                now.fi = last + 1;
            }
            else if (a[i] == a[i - 1]) now = mp(last, last);
            else {
                now.se = last - 1;
                now.fi = max(L, last - k);
            }
            if (now.se < now.fi) {can = false; break;}
            cur.fi = max(now.fi, r[i].fi);
            cur.se = min(now.se, r[i].se);
            if (cur.se < cur.fi) {can = false; break;}
            last = cur.fi;
            ans[i] = last;
        }
        if (can) {
            repn(i, 1, n) printf("%lld ", ans[i]);
            printf("\n");
        }
        else printf("-1\n");
    }
    else printf("-1\n");
    return 0;
}