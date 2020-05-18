#include <bits/stdc++.h>
using namespace std;

bool visited[30001];
vector<int> v[30001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	int a, b;
	for (int i=0; i<m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	queue<int> q;
	int ans = 0;
	for (int i=1; i<=n; i++) {
		q.push(i);
		int cnt = 0;
		while(!q.empty()) {
			int idx = q.front();
			q.pop();
			if(visited[idx]) continue;
			visited[idx] = true;
			cnt++;
			for (int j=0; j<v[idx].size(); j++) {
				q.push(v[idx][j]);
			}
		}
		ans = max(ans,cnt);
	}
	cout << ans;
}
