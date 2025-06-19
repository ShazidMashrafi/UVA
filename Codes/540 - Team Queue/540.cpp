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

signed main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t, k = 0;
    while(cin >> t)
    {
        if(t == 0) break;
        cout << "Scenario #" << ++k << endl;
        
        map<ll, ll> mp;
        for(int i = 0; i < t; ++i)
        {
            int n;
            cin >> n;
            while(n--)
            {
                int x;
                cin >> x;
                mp[x] = i;
            }
        }

        queue<ll> q;
        vector< queue<ll> > tq(t);
        vector<bool>in(t, false);

        string s;
        while(cin >> s)
        {
            if(s == "STOP") break;
            if(s == "ENQUEUE")
            {
                ll x;
                cin >> x;
                ll team = mp[x];
                if(!in[team])
                {
                    q.push(team);
                    in[team] = true;
                }
                tq[team].push(x);
            }
            else
            {
                ll team = q.front();
                ll x = tq[team].front();
                tq[team].pop();
                
                if(tq[team].empty())
                {
                    q.pop();
                    in[team] = false;
                }
                cout << x << endl;
            }
        }
        cout << endl;
    }
}