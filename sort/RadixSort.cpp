#include <iostream>
#include <queue>
using namespace std;

int v[10001];

int digit(int num,int idx) {
	for (int i=1; i<idx; i++) {
		num /= 10;
	}
	int ans = num % 10;
	return ans;
}

void radixSort(int n, int t) {
	queue<int> q[10];
	
	for (int i=1; i<=t; i++) {
		for (int j=1; j<=n; j++) {
			int d = digit(v[j], i);
			q[d].push(v[j]);
		}
		int p = 1;
		for (int j=0; j<=9; j++) {
			while(!q[j].empty()) {
				v[p++] = q[j].front();
				q[j].pop();
			}
		}
	}

	for (int i=1; i<=n; i++) {
		cout << v[i] << ' ';
	}
}

int main() {
	int n, t;
	int e_max = 0;
	cin >> n >> t;
	for (int i=1; i<=n; i++) {
		cin >> v[i];
		e_max < v[i] ? e_max = v[i] : 1;
	}
	radixSort(n,t);
	
}

