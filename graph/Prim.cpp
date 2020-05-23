#include <bits/stdc++.h>
using namespace std;

const int INF = 9999999;
vector<int> v[100];
int cost[100][100];
bool visited[100];

void prim(int n) {
	int a, b, node, ans = 0;
	node = 1;
	visited[node] = true;
	cout << "1" << ' ';
	
	while(node < n) {
		int temp_min = INF;
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				if(cost[i][j] < temp_min) {
					if(visited[i]) {
						temp_min = cost[i][j];
						a = i;
						b = j;
					}
				}
			}
		}
		if(!visited[a] || !visited[b]) {
			node++;
			cout << b << ' ';
			ans += temp_min;
			visited[b] = true;
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
	
	prim(n);
}
