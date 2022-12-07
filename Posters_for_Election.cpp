// In the name of Allah, Most Gracious, Most Merciful.
#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using vll = vector<ll>;
using vi  = vector<int>;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

const int N   = (int) 2e5 + 5;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9 + 9;

#define nl      '\n'
#define ff      first
#define ss      second
#define szof(x) (int) x.size()
#define all(x)  x.begin(), x.end()

template<typename type> class SegTreeLaxy {
private:
  struct Type {
    type color, lazy;
    Type() : color(0), lazy(0) {};
  };
  vector<Type> tree;
  int n;
  void propagate(int at, int b, int e) {
    tree[at].color = tree[at].lazy;
    if (b != e) {
      tree[2 * at].lazy = tree[at].lazy;
      tree[2 * at + 1].lazy = tree[at].lazy;
    }
    tree[at].lazy = 0;
  }
  void update(int at, int b, int e, int l, int r, type c) {
    if (tree[at].lazy) propagate(at, b, e);
    if (r < b or e < l) return;
    if (l <= b and e <= r) {
      tree[at].color = c;
      tree[at].lazy = 0;
      if (b != e) {
        tree[2 * at].lazy = c;
        tree[2 * at + 1].lazy = c;
      }
      return;
    }
    int mid = (b + e) >> 1;
    update(2 * at, b, mid, l, r, c);
    update(2 * at + 1, mid + 1, e, l, r, c);
  }
  type query(int at, int b, int e, int idx) {
    if (tree[at].lazy) propagate(at, b, e);
    if (b == e) return tree[at].color;
    int mid = (b + e) >> 1;
    if (mid >= idx) return query(2 * at, b, mid, idx);
    else return query(2 * at + 1, mid + 1, e, idx);
  }
public:
  SegTreeLaxy(int n) {
    this->n = n;
    tree.resize(3 * n);
  }
  void update(int l, int r, type c) {
    update(1, 1, n, l, r, c);
  }
  type query(int idx) {
    return query(1, 1, n, idx);
  }
};

int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0; cin >> test;
  while (test--) {
    int n; cin >> n;
    SegTreeLaxy<int> segTree(2 * n);
    for (int i = 1; i <= n; ++i) {
      int l, r; cin >> l >> r;
      segTree.update(l, r, i);
    }
    set<int> s;
    for (int i = 1; i <= 2 * n; ++i) {
      int color = segTree.query(i);
      if (color) s.insert(color);
    }
    cout << "Case " << ++tc << ": " << szof(s) << nl;
  }
  return 0;
}
