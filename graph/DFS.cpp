#include <bits/stdc++.h>
using namespace std;

bool visited[10000];
vector<int> v[10000];

void dfs(int node) {
	if(visited[node]) return;
	visited[node] = true;
	cout << node << ' ';
	for (int i=0; i<v[node].size(); i++) {
		dfs(v[node][i]);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	
	for (int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for (int i=0; i<=n; i++) {
		sort(v[i].begin(), v[i].end());
	}
	int last;
	cin >> last;
	dfs(last);
}
