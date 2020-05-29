#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 1e9

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> v[100];
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	for (int i=0; i<m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		v[x].push_back(make_pair(y,w));
	}
	int start, end;
	cin >> start >> end;
	
	int dist[100];
	int prev[100];
	fill(dist,dist+n+1, INF);
	dist[start] = 0;
	q.push(make_pair(start,0));
	prev[start] = 0;
	while(!q.empty()) {
		int node = q.top().first;
		int cost = q.top().second;
		q.pop();
		
		for (int i=0; i<v[node].size(); i++) {
			int next_node = v[node][i].first;
			int next_cost = v[node][i].second;
			if(dist[next_node] > dist[node] + next_cost) {
				dist[next_node] = dist[node] + next_cost;
				prev[next_node] = node;
				q.push(make_pair(next_node, dist[next_node]));
			}
		}
	}
	for (int i=1; i<=n; i++) {
		cout << prev[i] << ' ';
	}
	
	if(dist[end] == INF)
		cout << "Impossible";
	else
		cout << dist[end];
	
}
