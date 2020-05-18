#include <iostream>
using namespace std;

int v[10001];
int cnt;

void heapify(int k, int n) {
	int left = 2*k;
	int right = 2*k+1;
	int big;
	if(right<=n) {
		if(v[left] <= v[right]) big = right;
		else big = left;
	}
	else if(left <= n) big = left;
	else return;
	
	if(v[big] > v[k]) {
		cnt++;
		int temp = v[k];
		v[k] = v[big];
		v[big] = temp;
		heapify(big,n);
	}
}

void buildHeap(int n) {
	for (int i=n/2; i>0; i--) {
		heapify(i,n);
	}
	cnt = 0;
}

void heapSort(int n) {
	buildHeap(n);
	for (int i=n; i>=2; i--) {
		int temp = v[i];
		v[i] = v[1];
		v[1] = temp;
		heapify(1,i-1);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> v[i];
	}
	heapSort(n);
	cout << cnt;
}
