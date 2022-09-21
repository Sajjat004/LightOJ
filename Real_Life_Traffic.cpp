#include <bits/stdc++.h>
using namespace std;

typedef long long          ll;
typedef long double        ld;
typedef unsigned long long ull;
typedef pair<int, int>     pii;
typedef pair<ll, ll>       pll;
typedef vector<int>        vi;
typedef vector<ll>         vll;

const int N      = (int) 1e4 + 5;
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

vi g[N], ng[N];
vi disc, low, comp, comps;
vector<bool> used;
map<pii, bool> bridge;
int timer = 0;

void dfs(int u, int par = -1) {
  used[u] = 1;
  disc[u] = low[u] = ++timer;
  for (auto v : g[u]) {
    if (v == par) continue;
    if (used[v]) {
      low[u] = min(low[u], disc[v]);
    } else {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > disc[u]) {
        bridge[{u, v}] = 1;
        bridge[{v, u}] = 1;
      }
    }
  }
}

void dfs1(int u, int x) {
  comp[u] = x;
  for (auto v : g[u]) {
    if (bridge[{u, v}] or bridge[{v, u}]) continue;
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
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      g[i].clear();
      ng[i].clear();
    }
    for (int i = 1; i <= m; ++i) {
      int u, v; cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    disc.assign(n + 2, 0);
    low.assign(n + 2, 0);
    used.assign(n + 2, 0);
    comp.assign(n + 2, -1);
    comps.clear();
    bridge.clear();
    timer = 0;
    dfs(1);
    for (int i = 0; i < n; ++i) {
      if (comp[i] == -1) {
        dfs1(i, i);
        comps.pb(i);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (auto j : g[i]) {
        if (comp[i] != comp[j]) {
          ng[comp[i]].pb(comp[j]);
          ng[comp[j]].pb(comp[i]);
        }
      }
    }
    int cnt = 0;
    for (auto x : comps) {
      if (szof(ng[x]) == 2) cnt++;
    }
    cout << "Case " << ++tc << ": " << (cnt + 1) / 2 << nl;
  }
  return 0;
}
