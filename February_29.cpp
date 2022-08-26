/*  Bismillahir Rahmanir Rahim
    Author  :  Md. Sajjat Hosen
    Created :  Friday, 05 June, 2020 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long               ll;
typedef long double             ld;
typedef unsigned long long      ull;
typedef pair<int, int>          pii;
typedef pair<ll, ll>            pll;
typedef vector<int>             vi;
typedef vector<ll>              vll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_multiset;

inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

const int N       = (int) 2e5 + 5;
const int maxN    = (int) 1e6 + 6;
const int Mod     = (int) 1e9 + 7;

#define     debug(x)    cerr << #x << " = " << x << '\n';
#define     all(x)      x.begin(), x.end()
#define     szof(x)     (int) x.size()
#define     ff          first
#define     ss          second
#define     pb          push_back
#define     mp          make_pair
#define     PI          acos(-1.0)
#define     TN          typename
#define     nl          '\n'
#define     Fast_IO     ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

inline int add(int a, int b) { a += b; return a >= Mod ? a - Mod : a < 0 ? a + Mod : a; }
inline int mult(int a, int b) { return (ll) a * b % Mod; }

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

map<string, int> m;

bool leapYear(int n) {
    if (n % 400 == 0) return 1;
    if (n % 4 == 0 && n % 100 != 0) return 1;
    return 0;
}

int cntleapYear(int n) {
    int ans = n / 4;
    ans += (n / 400);
    ans -= (n / 100);
    return ans;
}

void process(string s, string& month, int& date, int& year) {
    string x = "", y = "";
    date = year = 0;
    int l;
    for (int i = 0; i < szof(s); ++i) {
        l = i;
        if (s[i] == ' ') break;
        month += s[i];
    }
    for (int i = l + 1; i < szof(s); ++i) {
        l = i;
        if (s[i] == ',') break;
        x += s[i];
    }
    for (int i = l + 2; i < szof(s); ++i) {
        y += s[i];
    }
    for (int i = 0; i < szof(x); ++i){
        date *= 10;
        date += (x[i] - '0');
    }
    for (int i = 0; i < szof(y); ++i) {
        year *= 10;
        year += (y[i] - '0');
    }
}

int main() {
    //Fast_IO
    //clock_t tStart = clock();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test = 1, tc = 0;
    cin >> test;
    cin.ignore();

    m["January"] = 1;
    m["February"] = 2;
    m["March"] = 3;
    m["April"] = 4;
    m["May"] = 5;
    m["June"] = 6;
    m["July"] = 7;
    m["August"] = 8;
    m["September"] = 9;
    m["October"] = 10;
    m["November"] = 11;
    m["December"] = 12;

    while (test--) {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        string month1 = "", month2 = "";
        int date1 = 0, date2 = 0, year1 = 0, year2 = 0;
        process(s1, month1, date1, year1);
        process(s2, month2, date2, year2);
        int ans = cntleapYear(year2) - cntleapYear(year1 - 1);
        if (leapYear(year1) && m[month1] > 2) ans--;
        if (leapYear(year2)) {
            if (m[month2] == 1) ans--;
            else if (m[month2] == 2 && date2 < 29) ans--;
        }
        cout << "Case " << ++tc << ": " << ans << nl;
    }
    //fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
} 
