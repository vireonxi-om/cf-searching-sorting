// Problem: Monsters (easy version)
// URL: https://codeforces.com/problemset/problem/1785/A
// Rating: 1000
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

const int N = 210000;
const int M = 51000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, a[N]; 

void solve() {
	cin >> n;
	LL sum = 0;
	repn(i, 1, n){
		cin >> a[i];
	} 
	sort(a + 1, a + n + 1);
	int cur = 1, m = 1;
	repn(i, 1, n) {
		while (cur <= n && a[cur] < i) cur ++;
		if (cur > n) break;
		//cout << i << " " << cur << "\n";
		sum += a[cur] - i;
		a[cur] = i;
		m = i;
		cur ++;
	} 
	repn(i, 1, n) {
		if (a[i] - m > 0) sum += a[i] - m;
	}
	cout << sum << "\n";
}

int main() {
	IO;
	int t;
	cin >> t;
	repn(i, 1, t) solve();
	return 0;	
}



