/*==========================================
    Bismillahir Rahmanir Rahim
    Author  : Md. Sajjat Hosen
    Created : 12-January,2021 10:36:51 PM
==========================================*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef  long long               ll;
typedef  long double             ld;
typedef  unsigned long long      ull;
typedef  pair<int, int>          pii;
typedef  pair<ll, ll>            pll;
typedef  vector<int>             vi;
typedef  vector<ll>              vll;
typedef  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;
typedef  tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_multiset;

inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

const int N       = (int) 2e5 + 5;
const int mxN     = (int) 1e6 + 6;
const int Mod     = (int) 1e9 + 7;

#define    debug(x)    cerr << #x << " = " << x << '\n';
#define    all(x)      x.begin(), x.end()
#define    szof(x)     (int) x.size()
#define    ff          first
#define    ss          second
#define    pb          push_back
#define    mp          make_pair
#define    PI          acos(-1.0)
#define    TN          typename
#define    nl          '\n'
#define    Fast_IO     ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

template<TN T> class bit {
private:
    vector<T> g;
    int n;

    void fcq(int idx, int val) {
        while (idx <= n) {
            g[idx] += val;
            idx += (idx & -idx);
        }
    }

public:
    bit(int _n) {
        n = _n;
        g.resize(n + 5, 0);
    }

    void update(int l, int r) {
        fcq(l, 1);
        fcq(r + 1, -1);
    }

    int query(int idx) {
        T sum = 0;
        while (idx > 0) {
            sum += g[idx];
            idx -= (idx & -idx);
        }
        return sum % 2;
    }
};

int main() {
    //Fast_IO
    //clock_t tStart = clock();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test = 1, tc = 0;
    cin >> test;
    while (test--) {
        int n, q;
        string s;
        cin >> s;
        cin >> q;
        n = szof(s);
        int ar[n + 2];
        for (int i = 0; i < n; ++i) ar[i + 1] = s[i] - '0';
        bit<ll> ds(n);
        cout << "Case " << ++tc << ":\n";
        while (q--) {
            char ck;
            cin >> ck;
            if (ck == 'I') {
                int l, r;
                cin >> l >> r;
                ds.update(l, r);
            } else if (ck == 'Q') {
                int idx;
                cin >> idx;
                int ans = ds.query(idx);
                cout << (ar[idx] ^ ans) << nl;
            }
        }

    }
    //fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
