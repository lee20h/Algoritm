#include <bits/stdc++.h>
using namespace std;

const int INF = 9999999;
int cost[10000][10000];
vector<int> v[10000];
int parent[10000];

int find(int n) {
	while(parent[n]) n=parent[n];
	return n;
}

bool _union(int a, int b) {
	if(a!=b) {
		parent[b]=a;
		return true;
	}
	return false;
}

void kruskal(int n) {
	int a, b, u, v, node = 1;
	int ans = 0;
	while(node < n) {
		int temp_min = INF;
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				if(temp_min > cost[i][j]) {
					temp_min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}
		u = a;
		v = b;
		u = find(u);
		v = find(v);
		if (_union(u,v)) {
			node++;
			cout << temp_min << ' ';
			ans += temp_min;
		}
		cost[a][b] = cost[b][a] = INF;
	}
	cout << ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cost[i][j] = INF;
		}
	}
	
	for (int i=0; i<m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		v[a].push_back(b);
		v[b].push_back(a);
		cost[a][b] = cost[b][a] = w;
	}
	kruskal(n);
}
