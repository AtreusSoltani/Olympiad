#include <iostream>

using namespace std;

struct Node {
    Node* lc;
    Node* rc;
    int sum;
    int lazy;

    Node* get_lc() {
        if (lc == nullptr)
            lc = new Node();
        return lc;
    }

    Node* get_rc() {
        if (rc == nullptr)
            rc = new Node();
        return rc;
    }

    void shift(int L, int R) {
        if (lazy == 0)
            return;
        int mid = (L + R) >> 1;
        get_lc()->change(L, mid, L, mid, lazy);
        get_rc()->change(mid, R, mid, R, lazy);
        lazy = 0;
    }

    void change(int L, int R, int l, int r, int value) {
        if (r <= L or R <= l)
            return;
        if (l <= L and R <= r) {
            sum += (R - L) * value;
            lazy += value;
            return;
        }
        shift(L, R);
        int mid = (L + R) >> 1;
        get_lc()->change(L, mid, l, r, value);
        get_rc()->change(mid, R, l, r, value);
        sum = lc->sum + rc->sum;
    }

    int get(int L, int R, int l, int r) {
        if (r <= L or R <= l)
            return 0;
        if (l <= L and R <= r)
            return sum;
        shift(L, R);
        int mid = (L + R) >> 1;
        return get_lc()->get(L, mid, l, r) + get_rc()->get(mid, R, l, r);
    }
};

int main() {
    Node *root = new Node();
    int n, q;
    cin >> n >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, value;
            cin >> l >> r >> value;
            root->change(0, n, l, r, value);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << root->get(0, n, l, r) << '\n';
        }
    }
}