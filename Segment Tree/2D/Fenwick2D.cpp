// https://quera.org/course/assignments/12035/problems/40753

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;

int a[maxn], pos[maxn];
vector<int> vec[maxn], fen[maxn];

int get(int x, int idx){
	idx = upper_bound(vec[x].begin(), vec[x].end(), idx) - vec[x].begin();
	int ret = 0;
	for (; idx; idx -= idx & -idx)
		ret += fen[x][idx];
	return ret;
}

int get(int idx, int l, int r){
	int ret = 0;
	for (; idx; idx -= idx & -idx)
		ret += get(idx, r) - get(idx, l - 1);
	return ret;
}

void add2(int x, int y){
	y = lower_bound(vec[x].begin(), vec[x].end(), y) - vec[x].begin() + 1;
	for (int idx = y; idx <= fen[x].size(); idx += idx & -idx)
		fen[x][idx] ++;
}

void add(int x, int y){
	for (int idx = x; idx < maxn; idx += idx & -idx)
		add2(idx, y);
}

void initadd(int idx, int x){
	for (; idx < maxn; idx += idx & -idx)
		vec[idx].push_back(x);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		pos[x] = i;
	}
	for (int i = 1; i <= n; i++)
		initadd(pos[a[i]], a[i]);
	for (int i = 1; i < maxn; i++)
		sort(vec[i].begin(), vec[i].end());
	for (int i = 0; i < maxn; i++)
		fen[i].resize((int)vec[i].size() + 1);
	ll answer = 0;
	for (int i = n; i >= 1; i--){
		answer += get(pos[a[i]], 1, n) - get(pos[a[i]], max(1, a[i] - k), min(n, a[i] + k));
		add(pos[a[i]], a[i]);
	}
	cout << answer << endl;
}
