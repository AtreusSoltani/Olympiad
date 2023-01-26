#include <iostream>

using namespace std;

const int MAXN = 1e5 + 10;
int sum[4 * MAXN], lazy[4 * MAXN];

void shift(int, int, int);

void change(int id, int L, int R, int l, int r, int value) {
    if (r <= L or R <= l)
        return;
    if (l <= L and R <= r) {
        sum[id] += (R - L) * value;
        lazy[id] += value;
        return;
    }
    shift(id, L, R);
    int mid = (L + R) >> 1;
    change(2 * id + 0, L, mid, l, r, value);
    change(2 * id + 1, mid, R, l, r, value);
    sum[id] = sum[2 * id + 0] + sum[2 * id + 1];
}

int get(int id, int L, int R, int l, int r) {
    if (r <= L or R <= l)
        return 0;
    if (l <= L and R <= r)
        return sum[id];
    shift(id, L, R);
    int mid = (L + R) >> 1;
    return get(2 * id + 0, L, mid, l, r) + get(2 * id + 1, mid, R, l, r);
}

void shift(int id, int L, int R) {
    if (lazy[id] == 0)
        return;
    int mid = (L + R) >> 1;
    change(2 * id + 0, L, mid, L, mid, lazy[id]);
    change(2 * id + 1, mid, R, mid, R, lazy[id]);
    lazy[id] = 0;
}

int main() {
    int n, q;
    cin >> n >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, value;
            cin >> l >> r >> value;
            change(1, 0, n, l, r, value);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << get(1, 0, n, l, r) << '\n';
        }
    }
}