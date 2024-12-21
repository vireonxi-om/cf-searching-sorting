// Problem: Easy Assembly
// URL: https://codeforces.com/problemset/problem/1773/E
// Rating: 1400
// Tags: greedy, sortings
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = (n) - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int n, m;
vector<int> f[N], g;
map<int, int> S;
int main() {
	IO;
	cin >> n;
	repn(i, 1, n) {
		int x;
		cin >> x;
		repn(j, 1, x) {
			int y;
			cin >> y;
			f[i].pb(y);
			g.pb(y);
		}
	}
	sort(all(g));
	rep(i, 0, g.size() - 1) {
		S[g[i]] = g[i + 1];
	}
	int s = 0, c = n - 1;
	repn(i, 1, n) {
		rep(j, 0, f[i].size() - 1) {
			if (S[f[i][j]] != f[i][j + 1]) s++, c++;
		}
	}
	cout << s << " " << c << "\n";
	return 0;
}