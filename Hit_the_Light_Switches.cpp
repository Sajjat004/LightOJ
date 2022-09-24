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
vector<bool> used;
vi topo;

void dfs(int u) {
  used[u] = 1;
  for (auto v : g[u]) if (!used[v]) dfs(v);
  topo.pb(u);
}

void dfs1(int u) {
  used[u] = 1;
  for (auto v : g[u]) if (!used[v]) dfs1(v);
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
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
    }
    for (int i = 1; i <= m; ++i) {
      int u, v; cin >> u >> v;
      g[u].pb(v);
    }
    used.assign(n + 2, 0);
    topo.clear();
    for (int i = 1; i <= n; ++i) if (!used[i]) dfs(i);
    reverse(all(topo));
    int ans = 0;
    used.assign(n + 2, 0);
    for (auto x : topo) {
      if (!used[x]) {
        ans++;
        dfs1(x);
      }
    }
    cout << "Case " << ++tc << ": " << ans << nl;
  }
  return 0;
}
