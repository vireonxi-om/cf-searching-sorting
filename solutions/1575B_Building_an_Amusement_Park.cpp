// Problem: Building an Amusement Park
// URL: https://codeforces.com/problemset/problem/1575/B
// Rating: 2300
// Tags: binary search, geometry
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
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, k;
int px[N], py[N], num;
double angle[N];
pair<double, int> a[N];
int pp[N], f[N], tp[N];
double ang[N];
double sqr(double x) {
	return x * x;
}
const double pi = acos(-1.0);
double cal(double theta){
	if (theta >= pi) theta -= 2 * pi;
	if (theta <= -pi) theta += 2 * pi;
	return theta;
}
int check(double r) {
	int num = 0;
	int tk = k;
	repn(i, 1, n) {
		if (px[i] == 0 && py[i] == 0) {
			tk--;
			continue;
		}
		double dist = sqrt(sqr(px[i]) + sqr(py[i]));
		if (dist < 2 * r) {
			double theta = acos(dist / 2 / r);
			a[++num] = mp(cal(angle[i] - theta), i);
			a[++num] = mp(cal(angle[i] + theta), i);
		}
	}
	sort(a + 1, a + num + 1);
	memset(pp, 0, sizeof(pp));
	memset(f, 0, sizeof(f));
	repn(i, 1, num) {
		int idx = a[i].se;
		if (!pp[idx]) pp[idx] = i;
		else {
			double a1 = a[pp[idx]].fi;
			double a2 = a[i].fi;
			if (a2 - a1 > pi) {
				f[1]++;
				f[pp[idx] + 1]--;
				f[i]++;
			}
			else {
				f[pp[idx]]++;
				f[i + 1]--;
			}
		}
	}
	int cur = 0;
	if (cur >= tk) return 1;
	repn(i, 1, num) {
		cur += f[i];
		if (cur >= tk) return 1;
	}
	return 0;
}
int main()
{
	IO;
	cin >> n >> k;
	repn(i, 1, n) {
		cin >> px[i] >> py[i];
		angle[i] = atan2(py[i], px[i]);
	}
	double l = 0, r = 200000, ans;
	repn(i, 1, 100) {
		double mid = (l + r) / 2;
		if (check(mid)) r = mid, ans = mid;
		else l = mid;
	}
	printf("%.10f\n", ans);
	return 0;
}// maintenance note (3): note time complexity in this file — 2026-08-25
