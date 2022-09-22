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

vi g[N], fg[N];
vi disc, low, color;
vector<bool> used, used1;
int timer = 0;
map<pii, bool> bridge;

void dfs(int u, int par = -1) {
  used[u] = 1;
  disc[u] = low[u] = ++timer;
  for (auto v : g[u]) {
    if (par == v) continue;
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

bool oddLength = 0;
int cnt = 0;

void dfs1(int u, int c) {
  used[u] = 1;
  color[u] = c;
  for (auto v : g[u]) {
    if (bridge[{u, v}] or bridge[{v, u}]) continue;
    if (used[v]) {
      if (color[v] != (c ^ 1)) oddLength = 1;
    } else dfs1(v, c ^ 1);
  }
}

void dfs2(int u) {
  used1[u] = 1;
  cnt++;
  for (auto v : g[u]) {
    if (bridge[{u, v}] or bridge[{v, u}]) continue;
    if (!used1[v]) dfs2(v);
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
    for (int i = 0; i <= n; ++i) {
      g[i].clear();
      fg[i].clear();
    }
    for (int i = 1; i <= m; ++i) {
      int u, v; cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    disc.assign(n + 2, -1);
    low.assign(n + 2, -1);
    used.assign(n + 2, 0);
    color.assign(n + 2, -1);
    timer = 0;
    bridge.clear();

    for (int i = 0; i < n; ++i) {
      if (!used[i]) dfs(i);
    }
    used.assign(n + 2, 0);
    used1.assign(n + 2, 0);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (!used[i]) {
        oddLength = 0;
        cnt = 0;
        dfs1(i, 0);
        dfs2(i);
        if (oddLength) ans += cnt;
      }
    }
    cout << "Case " << ++tc << ": " << ans << nl;
  }
  return 0;
}
