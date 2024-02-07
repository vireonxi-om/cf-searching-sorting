// Problem: PriceFixed
// URL: https://codeforces.com/problemset/problem/1539/D
// Rating: 1600
// Tags: binary search, greedy, implementation, sortings, two pointers
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<pair<ll, ll>> t;
const ll MAX=1e15;

int main(){
    scanf("%d", &n);
    ll num1, num2;
    for(int i=1; i<=n; i++){
        scanf("%lld%lld", &num1, &num2);
        t.push_back(make_pair(num2, num1));
    }
    sort(t.begin(), t.end());
    auto it1=t.begin(), it2=t.end();
    it2--;
    ll ans=0, tot=0;
    while(it1<=it2){
        ll ed=(*it1).first;
        if(tot>=ed){
            ans+=(*it1).second;
            tot+=(*it1).second;
            it1++;
            continue;
        }
        else{
            ll num=(*it2).second;
            ll cnt=min(num, ed-tot);
            num-=cnt; tot+=cnt;
            ans+=2*cnt;
            t[it2-t.begin()].second=num;
            if(num<=0) it2--;
        }
    }
    printf("%lld\n", ans);
}

