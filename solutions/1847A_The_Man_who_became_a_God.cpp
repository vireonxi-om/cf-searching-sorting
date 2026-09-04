// Problem: The Man who became a God 
// URL: https://codeforces.com/problemset/problem/1847/A
// Rating: 800
// Tags: greedy, sortings
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k << 1
#define RC k << 1 | 1
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
template<typename T> void down(T &x, T y) { if (x > y) x = y; }

const int N = 110000;
const int M = 610000;
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = (LL)1e12 + 5;
const double eps = 1e-15;
const double pi = acos(-1.0);

int n, k;
vector<int> num;
int a[N];

void solve() {
	num.clear();
	cin >> n >> k;
	int ans = 0;
	repn(i, 1, n) {
		cin >> a[i];
		if (i > 1) {
			ans += abs(a[i] - a[i - 1]);
			num.pb(- abs(a[i] - a[i - 1]));
		}
	}
	sort(all(num));
	rep(i, 0, k - 1) {
		ans += num[i];
	}
	cout << ans << "\n";
}

int main() {
	IO;
	int T;
	cin >> T;
	repn(i, 1, T) solve();
	return 0;
	
}
// maintenance note (7): small formatting cleanup on this file — 2026-09-04
