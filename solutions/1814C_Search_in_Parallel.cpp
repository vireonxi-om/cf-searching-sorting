// Problem: Search in Parallel
// URL: https://codeforces.com/problemset/problem/1814/C
// Rating: 1500
// Tags: constructive algorithms, greedy, sortings
// Language: C++20 (GCC 11-64)
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
const int M = 51000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, s1, s2; 
vector<int> a, b;
vector<PII> r;

void solve() {
	cin >> n >> s1 >> s2;
	r.clear();
	int num;
	repn(i, 1, n) {
		cin >> num;
		r.pb(mp(-num, i));
	}
	sort(all(r));
	a.clear();
	b.clear();
	
	for (auto it : r) {
		if (s1 * (a.size() + 1) < s2 * (b.size() + 1)) a.pb(it.se);
		else b.pb(it.se);
	}
	cout << a.size() << " ";
	for (auto x : a) cout << x << " ";
	cout << "\n"; 
	cout << b.size() << " ";
	for (auto x : b) cout << x << " ";
	cout << "\n"; 
} 

int main() {
	IO; 
	int t;
	cin >> t;
	repn(i, 1, t) solve(); 
	return 0;
}

