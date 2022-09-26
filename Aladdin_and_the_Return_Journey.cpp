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
int par[N][22], dep[N];
int timer = 0;
vi sTime, eTime;

void dfs(int u, int p = -1, int l = 1) {
  sTime[u] = ++timer;
  dep[u] = l;
  par[u][0] = p;
  for (int k = 1; k <= 20; ++k) {
    if (par[u][k - 1] == -1) break;
    par[u][k] = par[par[u][k - 1]][k - 1];
  }
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u, l + 1);
  }
  eTime[u] = timer;
}

int findLCA(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int k = 20; k >= 0; --k) {
    if ((dep[u] - (1 << k)) >= dep[v]) u = par[u][k];
  }
  if (u == v) return u;
  for (int k = 20; k >= 0; --k) {
    if (par[u][k] != -1 and par[u][k] != par[v][k]) {
      u = par[u][k];
      v = par[v][k];
    }
  }
  return par[u][0];
}

class FenwikTree {
  vll tree;
  int n;
public:
  FenwikTree(int n) {
    this->n = n;
    tree.assign(n + 2, 0);
  }
  void update(int idx, ll val) {
    while (idx <= n) {
      tree[idx] += val;
      idx += (idx & -idx);
    }
  }

  ll query(int idx) {
    ll sum = 0;
    while (idx > 0) {
      sum += tree[idx];
      idx -= (idx & -idx);
    }
    return sum;
  }
};

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  cin >> test;
  while (test--) {
    int n; cin >> n;
    vll value(n, 0);
    for (auto& x : value) cin >> x;
    for (int i = 0; i < n; ++i) g[i].clear();
    for (int i = 1; i < n; ++i) {
      int u, v; cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    sTime.assign(n + 2, 0);
    eTime.assign(n + 2, 0);
    timer = 0;
    memset(par, -1, sizeof par);
    dfs(0);
    FenwikTree bit(n + 2);
    for (int i = 0; i < n; ++i) {
      bit.update(sTime[i], value[i]);
      bit.update(eTime[i] + 1, -value[i]);
    }
    int q; cin >> q;
    cout << "Case " << ++tc << ":\n";
    while (q--) {
      int op; cin >> op;
      if (op == 0) {
        int u, v; cin >> u >> v;
        int lca = findLCA(u, v);
        ll res = bit.query(sTime[u]) + bit.query(sTime[v]);
        res -= (bit.query(sTime[lca]) * 2);
        res += value[lca];
        cout << res << nl;
      } else {
        int u; cin >> u;
        ll val; cin >> val;
        val = val - value[u];
        value[u] += val;
        bit.update(sTime[u], val);
        bit.update(eTime[u] + 1, -val);
      }
    }
  }
  return 0;
}
