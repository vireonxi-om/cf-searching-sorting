// Problem: Mikasa
// URL: https://codeforces.com/problemset/problem/1554/C
// Rating: 1800
// Tags: binary search, bitmasks, greedy, implementation
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

const int N = 110000;
const int M = 1100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;

LL n, m;
vector<int> a;
LL dp[40], pow2[40];

void solve(){
    scanf("%lld%lld", &n, &m);
    a.clear();
    LL num=n;
    while(num){
        a.push_back(num%2);
        num/=2;
    }
    int tot=a.size();
    repn(i, tot, 40) a.push_back(0);
    LL sum=n;
    int pos=0;
    LL ans=0;
    while(sum<=m){
        if(a[pos]==0) sum+=pow2[pos];
        dp[pos]=sum;
        if(sum<=m){ pos++; continue;}
        LL now=m;
        while(now>0){
            repn(i, 0, pos) {
                if(dp[i]<=now) continue;
                if(pow2[i]+n > now){
                    ans+=pow2[i]-1;
                    now=0;
                }
                else{
                    now-=pow2[i];
                    ans+=pow2[i];
                }
                break;
            }
        }
        break;
    }
    if(m<n) printf("0\n");
    else printf("%lld\n", ans+1);
}

int main(){
    pow2[0]=1;
    repn(i, 1, 35) pow2[i]=pow2[i-1]*2;
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}



