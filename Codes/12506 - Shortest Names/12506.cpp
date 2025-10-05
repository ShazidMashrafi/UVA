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
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        int count;
        
        TrieNode() {
            isEnd = false;
            count = 0;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };
    
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
            node->count++;
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                return false;
            node = node->children[index];
        }
        return node->isEnd;
    }

    int getPrefixLen(string word) {
        TrieNode* node = root;
        int len = 0;
        for(char c : word) {
            if(node->count == 1) {
                return len;
            }
            int index = c - 'a';
            node = node->children[index];
            len++;
        }
        return len;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<string> names(n);
    Trie trie;
    for(int i = 0; i < n; ++i) {
        cin >> names[i];
        trie.insert(names[i]);
    }

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        ans += trie.getPrefixLen(names[i]);
    }

    cout << ans << endl;
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