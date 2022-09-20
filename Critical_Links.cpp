#include <bits/stdc++.h>
using namespace std;

typedef long long          ll;
typedef long double        ld;
typedef unsigned long long ull;
typedef pair<int, int>     pii;
typedef pair<ll, ll>       pll;
typedef vector<int>        vi;
typedef vector<ll>         vll;

const int N      = (int) 2e5 + 5;
const int mxN    = (int) 1e6 + 6;
const int MOD    = (int) 1e9 + 7;
const int INF    = (int) 1e9 + 9;
const double EPS = (double) 1e-9;

#define all(x)   x.begin(), x.end()
#define szof(x)  (int) x.size()
#define ff       first
#define ss       second
#define pb       push_back
#define nl       '\n'
#define PI       acos(-1.0)
#define debug(x) cerr << #x << " = " << x << '\n';

/*................. let's try one more time .................*/

#ifdef LOCAL
#include "headerFile/debug.h"
#endif

vi g[N];
vi dist, low;
vector<bool> used;
int T = 0;

vector<pii> artBridge;

int get(string s) {
  int num = 0;
  int k = szof(s);
  for (int i = 1; i < (k - 1); ++i) {
    num *= 10;
    num += (s[i] - '0');
  }
  return num;
}

void dfs(int u, int par = -1) {
  used[u] = 1;
  dist[u] = low[u] = ++T;
  for (auto v : g[u]) {
    if (v == par) continue;
    if (used[v]) {
      low[u] = min(low[u], dist[v]);
    } else {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > dist[u]) {
        int x = u, y = v;
        if (x > y) swap(x, y);
        artBridge.pb({x, y});
      }
    }
  }
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  cin >> test;
  while (test--) {
    int n; cin >> n;
    for (int i = 0; i <= n; ++i) g[i].clear();
    for (int i = 1; i <= n; ++i) {
      int u; cin >> u;
      string s; cin >> s;
      int m = get(s);
      for (int j = 1; j <= m; ++j) {
        int v; cin >> v;
        g[u].pb(v);
      }
    }
    used.assign(n + 2, 0);
    dist.assign(n + 2, 0);
    low.assign(n + 2, 0);
    artBridge.clear();
    for (int i = 0; i < n; ++i) {
      if (!used[i]) {
        T = 0;
        dfs(i);
      }
    }
    sort(all(artBridge));
    cout << "Case " << ++tc << ":\n";
    cout << szof(artBridge) << " critical links" << nl;
    for (auto x : artBridge) cout << x.ff << " - " << x.ss << nl;
  }
  return 0;
}
