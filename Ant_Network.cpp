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

vi g[N];
vi disc, low, comp;
vector<bool> used, art;
int timer;

void dfs(int u, int par = -1) {
  used[u] = 1;
  disc[u] = low[u] = ++timer;
  int child = 0;
  for (auto v : g[u]) {
    if (v == par) continue;
    if (used[v]) {
      low[u] = min(low[u], disc[v]);
    } else {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      child++;
      if (par != -1 and disc[u] <= low[v]) art[u] = 1;
    }
  }
  if (par == -1 and child > 1) art[u] = 1;
}

void dfs1(int u, int x) {
  used[u] = 1;
  comp[u] = x;
  for (auto v : g[u]) if (!used[v]) dfs1(v, x);
}

pair<int, ull> solve() {
  int n, m; cin >> n >> m;
  for (int i = 0; i <= n; ++i) g[i].clear();
  vector<pii> edge;
  for (int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
    edge.pb({u, v});
  }
  disc.assign(n + 2, 0);
  low.assign(n + 2, 0);
  used.assign(n + 2, 0);
  art.assign(n + 2, 0);
  comp.assign(n + 2, -1);
  timer = 0;
  dfs(1);
  used.assign(n + 2, 0);
  int numArtPoint = 0;
  for (int i = 0; i < n; ++i) {
    if (art[i]) {
      numArtPoint++;
      used[i] = 1;
    }
  }
  if (numArtPoint == 0) {
    ull way = (1ULL * (n * (n - 1))) / 2;
    return {2, way};
  }
  int scc = 0;
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      dfs1(i, scc++);
    }
  }
  vi cntComponent(scc);
  for (int i = 0; i < n; ++i) {
    if (comp[i] != -1) cntComponent[comp[i]]++;
  }
  vector<set<int>> cntConnectWithart(scc, set<int>());
  for (auto x : edge) {
    if (art[x.ff] and art[x.ss]) continue;
    if (comp[x.ff] == comp[x.ss]) continue;
    if (art[x.ff]) cntConnectWithart[comp[x.ss]].insert(x.ff);
    else cntConnectWithart[comp[x.ff]].insert(x.ss);
  }
  int num = 0;
  ull way = 1;
  for (int i = 0; i < scc; ++i) {
    if (szof(cntConnectWithart[i]) < 2) {
      num++;
      way *= cntComponent[i];
    }
  }
  return {num, way};
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
    pair<int, ull> ans = solve();
    cout << "Case " << ++tc << ": " << ans.ff << " " << ans.ss << nl;
  }
  return 0;
}
