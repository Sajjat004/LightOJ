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
const int mxN    = (int) 1e4 + 6;
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

vi g[N], rg[N];
vector<bool> used;
vi order;
vi comp;

int numNode = 0;

void dfs(int u) {
  numNode++;
  used[u] = 1;
  for (auto v : g[u]) {
    if (!used[v]) dfs(v);
  }
  order.pb(u);
}

void dfs1(int u, int x) {
  comp[u] = x;
  for (auto v : rg[u]) {
    if (comp[v] == -1) dfs1(v, x);
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
    for (int i = 0; i < 1000; ++i) {
      g[i].clear();
      rg[i].clear();
    }
    order.clear();
    used.assign(1000, 0);
    set<int> nodes;
    vector<pii> edge;
    int n, m; cin >> m;
    for (int i = 1; i <= m; ++i) {
      int k; cin >> k;
      for (int j = 1; j <= k; ++j) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        nodes.insert(u);
        nodes.insert(v);
        rg[v].pb(u);
        edge.pb({u, v});
      }
    }
    numNode = 0;
    dfs(0);
    if (numNode != szof(nodes)) {
      cout << "Case " << ++tc << ": NO\n";
      continue;
    }
    reverse(all(order));
    comp.assign(1000, -1);
    int scc = 0;
    for (auto x : order) {
      if (comp[x] == -1) {
        dfs1(x, ++scc);
      }
    }
    vi outDegre(scc + 5);
    bool possible = 1;
    for (auto x : edge) {
      if (comp[x.ff] == comp[x.ss]) continue;
      outDegre[comp[x.ff]]++;
      if (outDegre[comp[x.ff]] == 2) possible = 0;
    }
    if (possible) cout << "Case " << ++tc << ": YES\n";
    else cout << "Case " << ++tc << ": NO\n";
  }
  return 0;
}
