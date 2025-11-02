#include <bits/stdc++.h>
using namespace std;
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

class Trie {
public:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        ll weight;
        
        TrieNode() {
            isEnd = false;
            weight = 0;
            for (ll i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };
    
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word, ll w) {
        TrieNode* node = root;
        for (char c : word) {
            ll index = c - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEnd = true;
        node->weight = w;
    }
};

void solve()
{
    ll n, p;
    cin >> n >> p;
    Trie trie;

    for(ll i = 0; i < n; ++i) {
        string word;
        ll weight;
        cin >> word >> weight;
        trie.insert(word, weight);
    }

    string s;
    cin >> s;
    ll len = sz(s);

    vector<ll>dp(len + 1, LLONG_MIN);
    dp[0] = 0;
    for(ll i = 0; i < len; ++i) {
        if(dp[i] == LLONG_MIN)  continue;

        Trie::TrieNode* node = trie.root;
        
        for(ll j = i; j < len; ++j) {
            ll index = s[j] - 'a';
            ll wordLen = j - i + 1;
            
            if(node->children[index]) {
                node = node->children[index];
                if(node->isEnd) {
                    dp[j + 1] = max(dp[j + 1], dp[i] + node->weight);
                } else {
                    dp[j + 1] = max(dp[j + 1], dp[i] - p * wordLen);
                }
            } else {
                dp[j + 1] = max(dp[j + 1], dp[i] - p * wordLen);
                break;
            }
        }
    }
    cout << dp[len] << endl;
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
        cout<<"Case "<<TC<<": ";
        solve();
    }
}