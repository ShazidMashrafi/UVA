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
ll power(ll x,ll y,ll m=LLONG_MAX) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

const int INF = 1e9;

signed main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int TCS = 1;
    // cin >> TCS;
    for (int TC = 1; ; ++TC)    
    {
        int c, s, q;
        cin >> c >> s >> q;
        if(c == 0 && s == 0 && q == 0)  break;

        vector<vector<int>> dist(c + 1, vector<int>(c + 1, INF));
        for(int i = 1; i <= c; ++i) {
            dist[i][i] = 0;
        }

        for(int i = 0; i < s; ++i) {
            int u, v, d;
            cin >> u >> v >> d;
            dist[u][v] = min(dist[u][v], d);
            dist[v][u] = min(dist[v][u], d);
        }

        for(int k = 1; k <= c; ++k) {
            for(int i = 1; i <= c; ++i) {
                for(int j = 1; j <= c; ++j) {
                    dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
                }
            }
        }

        if(TC > 1)  cout << endl;
        cout << "Case #" << TC << endl;
        while(q--) {
            int u, v;
            cin >> u >> v;
            if(dist[u][v] == INF) {
                cout << "no path" << endl;
            } else {
                cout << dist[u][v] << endl;
            }
        }
    }
}
