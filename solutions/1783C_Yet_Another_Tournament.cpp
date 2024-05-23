// Problem: Yet Another Tournament
// URL: https://codeforces.com/problemset/problem/1783/C
// Rating: 1700
// Tags: binary search, greedy, sortings
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

const int N = 510000;
const int M = 11000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, a[N], m, cnt[1100];

void solve() {
	cin >> n;
	cin >> m;
	repn(i, 0, 1000) cnt[i] = 0;
	repn(i, 1, n){
		cin >> a[i];
		cnt[a[i]] ++;
	} 
	int ans = n + 1;
	int l = 1, r = n + 1;
	while (l < r) {
		int mid = (l + r) / 2;
		bool yes = false;
		int tar = n - mid + 1;
		int sum = 0, tot = 0;
		repn(i, 0, 1000) {
			if (i == 0) {
				tot += cnt[0];
				continue;
			}
			if (sum >= m) break;
			int now = min(cnt[i], (m - sum) / i);
			tot += now;
			sum += now * i;
		}
		if (tot >= tar) {
			yes = true;
			//cout << "1\n";
		}
		
		cnt[a[tar]] --; 
		sum = a[tar]; tot = 0;
		repn(i, 0, 1000) {
			if (i == 0) {
				tot += cnt[0];
				continue;
			}
			if (sum >= m) break;
			int now = min(cnt[i], (m - sum) / i);
			tot += now;
			sum += now * i;
		}
		cnt[a[tar]] ++;
		if (sum <= m && tot >= tar - 2){
			yes = true;
			//cout << "2\n";
		} 
		if (yes) r = mid;
		else l = mid + 1;
	}
	ans = r;
	cout << ans << "\n";
}

int main() {
	IO;
	int t;
	cin >> t;
	repn(i, 1, t) solve();
	return 0;
}



