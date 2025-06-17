#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include <debug.h>
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

void solve()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> g(n, vector<int>(m)), dist(n, vector<int>(m, INT_MAX));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    }

    priority_queue<pair<int, pair<int, int>>> pq;
    
    dist[0][0] = g[0][0];
    pq.push({-g[0][0], {0, 0}});
    
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    
    while (!pq.empty()) 
    {
        int cost = -pq.top().first;
        auto pos = pq.top().second;
        int r = pos.ff;
        int c = pos.ss;
        pq.pop();
        
        if (cost > dist[r][c]) continue;
        
        for (int i = 0; i < 4; i++) 
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) 
            {
                int new_cost = cost + g[nr][nc];
                
                if (new_cost < dist[nr][nc]) 
                {
                    dist[nr][nc] = new_cost;
                    pq.push({-new_cost, {nr, nc}}); 
                }
            }
        }
    }
    
    cout << dist[n-1][m-1] << endl;
}

signed main()
{
    FAST;
    int TCS = 1;
    cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        solve();
    }
}