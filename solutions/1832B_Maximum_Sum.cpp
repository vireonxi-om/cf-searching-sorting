// Problem: Maximum Sum
// URL: https://codeforces.com/problemset/problem/1832/B
// Rating: 1100
// Tags: brute force, sortings, two pointers
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
typedef long double LD;
 
const int N = 210000;
const int M = 1100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;
 
 
int n, k;
LL a[N];
 
void solve() {
	cin >> n >> k;
	repn(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	repn(i, 1, n) a[i] += a[i - 1];
	
	LL ans = 0;
	repn(i, 0, k) {
		ans = max(ans, a[n - k + i] - a[2 * i]);
	}
	cout << ans << "\n";
}

int main() {
	int t;
	cin >> t;
	repn(i, 1, t) solve();
	return 0;
}

