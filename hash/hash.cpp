#include <iostream>
#include <cstring>
using namespace std;

bool IsPrime(int x) {
	for (int i=2; i<x; i++) {
		if(x % i == 0) return false;
	}
	return true;
}


int main() {
	bool visited[10001];
	int n, m;
	int x;
	int cnt = 0;
	cin >> n;
	m = 2 * n;
	memset(visited,false,sizeof(visited));
	
	while(1) {
		if(IsPrime(m)) break;
		m++;
	}
	
	for (int i=0; i<n; i++) {
		cin >> x;
		
		
		for (int j=1; j<m; j++) {
			int idx = (x + j) % m;
			if(!visited[idx]) {
				visited[idx] = true;
				break;
			}
			else {
				cnt++;
				continue;
			}
		}
		
	}
	
	cout << cnt;
}
