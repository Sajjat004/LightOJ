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
vi level;
vector<bool> used;
vi res;
int ed;

void dfs(int u, int par = -1) {
  if (u == ed) return;
  int node = -1, l = INF;
  for (auto v : g[u]) {
    if (v == par) continue;
    if (level[v] < l) {
      node = v;
      l = level[v];
    } else if (level[v] == l) node = min(node, v);
  }
  res.pb(node);
  dfs(node, u);

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
    vi node(n, 0);
    for (auto& x : node) cin >> x;
    used.assign(50005, 0);
    level.assign(50005, -1);
    for (int i = 1; i <= 50000; ++i) g[i].clear();
    for (int i = 1; i < n; ++i) {
      g[node[i]].pb(node[i - 1]);
      g[node[i - 1]].pb(node[i]);
    }
    queue<int> q;
    q.push(node[n - 1]);
    level[node[n - 1]] = 1;
    used[node[n - 1]] = 1;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      used[u] = 1;
      for (auto v : g[u]) {
        if (used[v]) continue;
        level[v] = level[u] + 1;
        used[v] = 1;
        q.push(v);
      }
    }
    res.clear();
    res.pb(node[0]);
    ed = node[n - 1];
    dfs(node[0]);
    cout << "Case " << ++tc << ":\n";
    for (auto x : res) cout << x << " ";
    cout << nl;
  }
  return 0;
}
