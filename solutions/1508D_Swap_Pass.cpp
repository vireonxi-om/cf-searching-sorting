// Problem: Swap Pass
// URL: https://codeforces.com/problemset/problem/1508/D
// Rating: 3000
// Tags: constructive algorithms, geometry, sortings
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

const int N = 2100;
const int M = 610000;
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = (LL)1e12 + 5;
const double eps = 1e-10;
const double pi = acos(-1.0);
inline int dcmp(double x) {
    return (x > eps) - (x < -eps);
}

struct Point {
	int x, y, id;
} p[N]; 
vector<pair<double, int>> a;
int n, cnt, d[N], f[N], v[N], pt[N], vis[N];
vector<PII> ans;

void work(int i, int j) {
	swap(p[i].id, p[j].id);
	ans.pb(mp(i, j));
}
int findfa(int x) {
	return x == f[x] ? x : f[x] = findfa(f[x]);
}

int main() {
	IO;
	cin >> n;
	int st = -1;
	repn(i, 1, n) {
		cin >> p[i].x >> p[i].y >> p[i].id;
		if (p[i].id == i) v[i] = 1;
		else {
			if (st < 0) st = i;
			if (i > st && st > 0) a.pb(mp(atan2(p[i].y - p[st].y, p[i].x - p[st].x), i));
		}
	}
	sort(all(a));
	repn(i, 1, n) {
		if (d[i] || v[i]) continue;
		d[i] = ++ cnt;
		int pos = i;
		while (!d[p[pos].id]) {
			d[p[pos].id] = cnt; pos = p[pos].id; 
		}
	}
	repn(i, 1, cnt) f[i] = i;
	int tot = a.size();
	rep(i, 0, tot) {
		int nxt = (i + 1) % tot;
		int fi = findfa(d[a[i].se]), fj = findfa(d[a[nxt].se]);
		double del = a[nxt].fi - a[i].fi; 
		if (dcmp(del - pi) >= 0) continue;
		if (fi == fj) continue;
		f[fj] = fi;
		work(a[i].se, a[nxt].se);
	}
	if (st > 0) {
		int pos = st;
		vis[pos] = 1;
		while (!vis[p[pos].id]) {
			pos = p[pos].id;
			ans.pb(mp(st, pos));
			vis[pos] = 1;
		}
		
	}
	cout << ans.size() << "\n";
	for (auto pr : ans) {
		cout << pr.fi << " " << pr.se << "\n";
	}
	return 0;
}