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

unordered_map<string, char> morse = {
    {".-", 'A'},   {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'},
    {".", 'E'},    {"..-.", 'F'}, {"--.", 'G'},  {"....", 'H'},
    {"..", 'I'},   {".---", 'J'}, {"-.-", 'K'},  {".-..", 'L'},
    {"--", 'M'},   {"-.", 'N'},   {"---", 'O'},  {".--.", 'P'},
    {"--.-", 'Q'}, {".-.", 'R'},  {"...", 'S'},  {"-", 'T'},
    {"..-", 'U'},  {"...-", 'V'}, {".--", 'W'},  {"-..-", 'X'},
    {"-.--", 'Y'}, {"--..", 'Z'},
    {"-----", '0'}, {".----", '1'}, {"..---", '2'}, {"...--", '3'},
    {"....-", '4'}, {".....", '5'}, {"-....", '6'}, {"--...", '7'},
    {"---..", '8'}, {"----.", '9'},
    {".-.-.-", '.'}, {"--..--", ','}, {"..--..", '?'}, {".----.", '\''},
    {"-.-.--", '!'}, {"-..-.", '/'},  {"-.--.", '('},  {"-.--.-", ')'},
    {".-...", '&'},  {"---...", ':'}, {"-.-.-.", ';'}, {"-...-", '='},
    {".-.-.", '+'},  {"-....-", '-'}, {"..--.-", '_'}, {".-..-.", '"'},
    {".--.-.", '@'}
};

void solve()
{
    string s;
    getline(cin, s);
    // dbg(s);

    string curr, word;
    vector<string> ans;
    for(int i = 0; i < sz(s); ++i) {
        if(s[i] == ' ') {
            if(!curr.empty()) {
                word.pb(morse[curr]);
                curr.clear();
            }
            if(i + 1 < sz(s) && s[i + 1] == ' ') {
                if(!word.empty()) {
                    ans.pb(word);
                    word.clear();
                }
                i++;
            }
        } else curr.pb(s[i]);
        // dbg(s[i], curr, word);
    }
    
    if(!curr.empty()) word.pb(morse[curr]);
    if(!word.empty()) ans.pb(word);

    for (int i = 0; i < sz(ans); ++i) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

signed main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int TCS = 1;
    cin >> TCS;
    cin.ignore();
    for (int TC = 1; TC <= TCS; ++TC)
    {
        if(TC > 1)  cout << endl;
        cout<<"Message #" << TC << endl;
        solve();
    }
}