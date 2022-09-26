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

vi g[N], rg[N], fg[N];
vector<bool> used;
vi order, comp;

void dfs(int u) {
  used[u] = 1;
  for (auto v : g[u]) {
    if (!used[v]) dfs(v);
  }
  order.pb(u);
}

void dfs1(int u, int x) {
  used[u] = 1;
  comp[u] = x;
  for (auto v : rg[u]) {
    if (!used[v]) dfs1(v, x);
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
    int n, m; cin >> n >> m;
    vector<pii> edge;
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
      rg[i].clear();
      fg[i].clear();
    }
    for (int i = 1; i <= m; ++i) {
      int u, v; cin >> u >> v;
      g[u].pb(v);
      rg[v].pb(u);
      edge.pb({u, v});
    }
    used.assign(n + 2, 0);
    order.clear();
    for (int i = 1; i <= n; ++i) {
      if (!used[i]) dfs(i);
    }
    reverse(all(order));
    int scc = 0;
    used.assign(n + 2, 0);
    comp.assign(n + 2, -1);
    int numComponent = 0;
    for (auto x : order) {
      if (!used[x]) {
        dfs1(x, ++scc);
        numComponent++;
      }
    }
    vi inDegree(scc + 2, 0), outDegree(scc + 2, 0);
    for (auto x : edge) {
      if (comp[x.ff] != comp[x.ss]) {
        inDegree[comp[x.ss]]++;
        outDegree[comp[x.ff]]++;
      }
    }
    int ind = 0, outd = 0;
    for (int i = 1; i <= scc; ++i) {
      if (inDegree[i] == 0) ind++;
      if (outDegree[i] == 0) outd++;
    }
    if (numComponent == 1) cout << "Case " << ++tc << ": 0\n";
    else cout << "Case " << ++tc << ": " << max(ind, outd) << nl;
  }
  return 0;
}
