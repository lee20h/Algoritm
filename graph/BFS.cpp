#include <bits/stdc++.h>
using namespace std;

vector<int> v[10000];
bool visited[10000];

int main() {
	int n, m;
	cin >> n;
	cin >> m;
	
	for (int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i=1; i<=n; i++) {
		sort(v[i].begin(),v[i].end());
	}
	int last;
	cin >> last;
	queue<int> q;
	q.push(last);
	while(!q.empty()) {
		int temp = q.front();
		q.pop();
		if(visited[temp]) continue;
		visited[temp] = true;
		for (int i=0; i<v[temp].size(); i++) {
			q.push(v[temp][i]);
		}
		cout << temp << ' ';
	}
}

