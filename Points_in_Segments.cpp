/*---------------------------------------
   BISMILLAHIR RAHMANIR RAHIM
   AUTHOR : Md. Sajjat Hossen
   TIME : 23-March,2021 10:37:36 AM
----------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

inline int Int() { int x; scanf("%d", &x); return x; }

const int N  = (int) 2e5 + 5;

int v[N + 2];

int lowerBound(int n, int val) {
    int l = 0, r = n - 1;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (v[mid] >= val) {
            ans = mid;
            r = mid -1;
        } else l = mid + 1;
    }
    return ans;
}

int upperBound(int n, int val) {
    int l = 0, r = n - 1;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (v[mid] <= val) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    int test = Int(), tc = 0;
    while (test--) {
        int n = Int(), q = Int();
        for (int i = 0; i < n; ++i) v[i] = Int();
        sort(v, v + n);
        printf("Case %d:\n", ++tc);
        while (q--) {
            int l = Int(), r = Int();
            int x = lowerBound(n, l);
            int y = upperBound(n, r);
            int ans = 0;
            if (x <= y && x != -1 && y != -1) ans = y - x + 1;
            printf("%d\n", ans);
        }
    }
    return 0;
}
