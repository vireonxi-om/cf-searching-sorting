// Problem: Same Count One
// URL: https://codeforces.com/problemset/problem/1774/D
// Rating: 1600
// Tags: brute force, constructive algorithms, greedy, implementation, two pointers
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
const int M = 110000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, m, cnt[N];
vector<int> a[N];
vector<PII> m1, m2;
vector<pair<int, PII>> ans;

void solve() {
    cin >> n >> m;
    ans.clear(); m1.clear(); m2.clear();
    int tot = 0;
    repn(i, 1, n) {
        int num;
        cnt[i] = 0;
        a[i].clear();
        repn(j, 1, m) {
            cin >> num;
            a[i].pb(num);
            if (num) cnt[i] ++;
        }
        tot += cnt[i];
    }
    if (tot % n) {
        cout << "-1\n";
        return;
    }
    tot /= n;
    repn(i, 1, n) {
        if (cnt[i] > tot) m1.pb(mp(cnt[i] - tot, i));
        else if (cnt[i] < tot) m2.pb(mp(tot - cnt[i], i));
    }
    int st = 0;
    for (auto x : m1) {
        int i1 = x.se, t1 = x.fi;
        while (t1) {
            int i2 = m2[st].se, t2 = m2[st].fi;
            for (int j = 0; j < m; j ++) {
                if (t2 == 0 || t1 == 0) break;
                if (a[i1][j] && ! a[i2][j]){
                    ans.pb(mp(j + 1, mp(i1, i2)));
                    a[i1][j] = 0;  a[i2][j] = 1;
                    t1 --; t2 --;
                } 
            }
            if (t2 == 0) st ++;
            else m2[st].fi = t2;
        }
    }
    cout << ans.size() << "\n";
    for (auto x: ans) {
        cout << x.se.fi << " " << x.se.se << " " << x.fi << "\n";
    }
}

int main() {
    IO;
    int t;
    cin >> t;
    repn(i, 1, t) solve();
    return 0;
}



