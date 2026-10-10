#include <bits/stdc++.h>
using namespace std;
#if defined(LOCAL) && !defined(ONLINE_JUDGE)
#include "debug.h"
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
ll binpow(ll x,ll y,ll m=LLONG_MAX) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

const int N = 1e6 + 10;
int spf[N];
vector<int> primes;

void sieve() {
    for (int i = 2; i < N; ++i) {
        if (!spf[i]) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > spf[i] || 1LL * i * p >= N) break;
            spf[i * p] = p;
        }
    }
}

int get_factors_count(int x) {
    int ct = 0;
    while (x > 1) {
        ct++;
        x /= spf[x];
    }
    return ct;
}

void solve()
{
    sieve();
    vector<int>dp(N, 0), pref(N, 0);
    for(int i = 2; i < N; ++i) {
        dp[i] = 1 + dp[i / spf[i]];
        pref[i] = pref[i - 1] + dp[i];
    }
    for(int i = 0; i < 20; ++i) {
        dbg(i, pref[i]);
    }

    int n;
    while(cin >> n) {
        cout << pref[n] << endl;
    }
}

signed main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int TCS = 1;
    // cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}