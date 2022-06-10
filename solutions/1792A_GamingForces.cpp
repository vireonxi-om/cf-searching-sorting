// Problem: GamingForces
// URL: https://codeforces.com/problemset/problem/1792/A
// Rating: 800
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
const int M = 11000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, a[110]; 

void solve(){
	int cnt = 0;
	cin >> n;
	repn(i, 1, n) {
		cin >> a[i];
		if (a[i] == 1) cnt ++;
	}
	int ans = n - cnt + (cnt + 1) / 2;
	cout << ans << "\n"; 
}

int main() {
	IO;
	int t;
	cin >> t;
	repn(i, 1, t) solve();
	return 0;
}



