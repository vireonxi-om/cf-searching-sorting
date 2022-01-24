// Problem: Elemental Decompress
// URL: https://codeforces.com/problemset/problem/1768/C
// Rating: 1300
// Tags: constructive algorithms, greedy, implementation, sortings
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

int n, num, p[N], q[N], st[N];
vector<int> a[N];
queue<int> l; 

void solve(){
	cin >> n;
	while (!l.empty()) l.pop();
	repn(i, 1, n){
		a[i].clear();
		p[i] =  0; q[i] = 0; st[i] = 0;
	} 
	repn(i, 1, n) {
		cin >> num; 
		a[num].pb(i); 
	}
	bool can = true;

	pern(i, 1, n) {
		if (a[i].size() > 2) can = false;
		if (!can) break; 
		if (a[i].size() == 1) {
			if (p[a[i][0]]) {
				can = false;
			}
			p[a[i][0]] = i; q[a[i][0]] = i;
			st[a[i][0]] = 1;
		}
		else {
			int tot = 2 - a[i].size();
			repn(j, 1, tot) {
				if (l.empty()) {
					can = false;
					break;
				}
				int pos = l.front();
				l.pop();
				if (st[pos] == 1) q[pos] = i;
				else p[pos] = i;
			} 
			if (a[i].size() == 2) {
				int x = a[i][0], y = a[i][1];
				if (st[x] || st[y]) can = false;
				p[x] = i; q[y] = i;
				st[x] = 1; st[y] = 2;
				l.push(x); l.push(y);
			}						
		}
	}

	if (!can) cout << "NO\n";
	else {
		cout << "YES\n";
		repn(i, 1, n) cout << p[i] <<" ";
		cout << "\n";
		repn(i, 1, n) cout << q[i] <<" ";
		cout << "\n";
	}
}

int main() {
	IO;
	int t;
	cin >> t;
	repn(i, 1, t) solve();
	return 0;
}



