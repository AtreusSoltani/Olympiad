#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int seg[4 * MAXN];

int get(int id, int L, int R, int l, int r) {
    if (r <= L or R <= l)
        return;
    if (l <= L and R <= r)
        return seg[id];
    int mid = (L + R) >> 1;
    return max(get(2 * id + 0, L, mid, l, r),
                get(2 * id + 1, mid, R, l, r));
}

void change(int id, int L, int R, int idx, int val) {
    if (idx < L or R <= idx)
        return;
    if (L + 1 == R) {
        seg[id] = val;
        return;
    }
    int mid = (L + R) >> 1;
    change(2 * id + 0, L, mid, idx, val);
    change(2 * id + 1, mid, R, idx, val);
    seg[id] = max(seg[2 * id + 0], seg[2 * id + 1]);
}

int a[MAXN];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        change(1, 0, n, i, a[i]);
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int idx, val;
            cin >> idx >> val;
            change(1, 0, n, idx, val);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << get(1, 0, n, l, r) << '\n';
        }
    }
}