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
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

void solve() 
{
    int R, C;
    cin >> R >> C;

    vector<string> grid(R);
    queue<pair<int, int>> fq;
    queue<pair<int, int>> jq;
    vector<vector<int>> ft(R, vector<int>(C, INF));
    vector<vector<int>> jt(R, vector<int>(C, INF));

    int start_r = -1, start_c = -1;

    for (int i = 0; i < R; ++i) {
        cin >> grid[i];
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == 'F') {
                fq.push({i, j});
                ft[i][j] = 0;
            } else if (grid[i][j] == 'J') {
                start_r = i;
                start_c = j;
                jq.push({i, j});
                jt[i][j] = 0;
            }
        }
    }
    dbg(grid);
    dbg(fq, jq);
    dbg(ft, jt);

    while (!fq.empty()) {
        auto [r, c] = fq.front();
        fq.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] != '#') {
                if (ft[nr][nc] == INF) {
                    ft[nr][nc] = ft[r][c] + 1;
                    fq.push({nr, nc});
                }
            }
        }
    }

    while (!jq.empty()) {
        auto [r, c] = jq.front();
        int t = jt[r][c];

        if (r == 0 || r == R - 1 || c == 0 || c == C - 1) {
            cout << t + 1 << endl;
            return;
        }

        jq.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] != '#') {
                if (jt[nr][nc] == INF) {
                    if (t + 1 < ft[nr][nc]) {
                        jt[nr][nc] = t + 1;
                        jq.push({nr, nc});
                    }
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}


signed main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int TCS = 1;
    cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}
