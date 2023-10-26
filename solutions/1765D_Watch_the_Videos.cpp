// Problem: Watch the Videos
// URL: https://codeforces.com/problemset/problem/1765/D
// Rating: 1700
// Tags: binary search, constructive algorithms, two pointers
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

const int N = 210000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int n, m, a[N];
int check(int x) {
	int l = 1, r = x;
	while (l < r) {
		if (a[l] + a[r] > m) return 0;
		l++, r--;
	}
	return 1;
}
LL sum;
int main() {
	IO;
	cin >> n >> m;
	repn(i, 1, n) cin >> a[i], sum += a[i];
	sort(a + 1, a + n + 1);
	int l = 0, r = n, ans;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	sum += (n - ans) + 1;
	cout << sum << "\n";
	return 0;
}