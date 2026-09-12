#include <bits/stdc++.h>
using namespace std;
#if defined(LOCAL) && !defined(ONLINE_JUDGE)
#include <debug.h>
#else
#define dbg(...)
#endif
#define  ll  long long
#define  endl  '\n'
#define  ff  first
#define  ss  second
#define  pb  push_back
#define  sz(x)  (int)(x).size()
#define  all(x)  x.begin(), x.end()
#define  Dpos(n) fixed << setprecision(n)
#define  yn(f)  f? cout<<"YES\n":cout<<"NO\n"
#define  FAST  (ios_base::sync_with_stdio(false), cin.tie(nullptr));
ll power(ll x,ll y,ll m=LLONG_MAX) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

void solve(int n)
{
    ll temp = n, tot = 1;

    for(ll d = 2; d * d <= temp; ++d) {
        if(temp % d)    continue;
        ll exp = 0;
        while(temp % d == 0) {
            exp++;
            temp /= d;
        }
        tot *= (2ll*exp + 1);
    }
    if(temp > 1) tot *= (2ll * 1 + 1);
    cout << n << " " << (tot + 1) / 2 << endl;
}

signed main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int TCS = 1;
    // cin >> TCS;
    ll n;
    while(cin >> n && n != 0)
    {
        // cout<<"Case "<<TC<<": ";
        solve(n);
    }
}