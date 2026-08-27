// Problem: Reverse Sort
// URL: https://codeforces.com/problemset/problem/1605/B
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
#define IO cin.sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)
 
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
 
const int N = 1100;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;
 
int n;
char s[N];
int cnt[N];
vector<int> ans;
 
void solve() {
	scanf("%d%s", &n, s + 1);
	repn(i, 1, n) cnt[i] = 0;
	repn(i, 1, n) {
		cnt[i] = cnt[i - 1];
		if (s[i] == '1') cnt[i] ++;
	}
	int pos = -1;
	repn(i, 0, n) {
		if (cnt[i] == n - i - (cnt[n] - cnt[i])){pos = i; break;}
	}
	ans.clear();
	repn(i, 1, pos) if (s[i] == '1') ans.pb(i);
	repn(i, pos + 1, n) if (s[i] == '0') ans.pb(i);
	if (ans.size() > 0) {
		printf("1\n%d ", (int)ans.size());
		for (auto x: ans) printf("%d ", x);
		printf("\n");
	}
	else printf("0\n");
}
 
int main() {
	int t;
	scanf("%d", &t);
	repn(i, 1, t) solve();
	return 0;
}
// maintenance note (4): add edge-case comment to this file — 2026-08-27
