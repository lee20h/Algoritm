#include <iostream>
using namespace std;

int N;
int v[10001];
int temp[10001];
int cnt = 0;


void merge(int p, int q, int r) {
	int i = p;
	int j = q+1;
	int t = 1;
	while(i <= q && j <= r) {
		if(v[i] < v[j]) {
			temp[t++] = v[i++];
			cnt++;
		}
		else {
			temp[t++] = v[j++];
			cnt++;
		}
	}
	
	while(i <= q) {
		temp[t++] = v[i++];
	}
	while(j <= r) {
		temp[t++] = v[j++];
	}
	
	i = p;
	t = 1;
	while(i <= r) {
		v[i++] = temp[t++];
	}
}

void mergesort(int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		mergesort(p,q);
		mergesort(q+1,r);
		merge(p,q,r);
	}
}

int main() {
	cin >> N;
	for (int i=1; i<=N; i++) {
		cin >> v[i];
	}
	mergesort(1,N);
	cout << cnt;
}
