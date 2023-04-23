// Problem: Charming Meals
// URL: https://codeforces.com/problemset/problem/1949/B
// Rating: 1500
// Tags: binary search, brute force, greedy, sortings
// Language: C++20 (GCC 13-64)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
#define LC k << 1
#define RC k << 1 | 1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n) - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;
typedef pair<LL, LL> PLL;

const int N = 5100;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((ull) new char);
#define rand Rand

int T, n, a[N], b[N], pp[N];
int main() {
    IO;
    cin >> T;
    while (T--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        int ans = 0;
        rep(d, 0, n) {
            int res = inf;
            rep(i, 0, n) {
                res = min(res, abs(a[i] - b[(i + d) % n]));
            }
            ans = max(ans, res);
        }
        cout << ans << "\n";
    }
    return 0;
}
