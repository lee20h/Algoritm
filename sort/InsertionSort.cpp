#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	int cnt = 0;
	for (int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	
	for (int k=1; k<n; k++) {
		int idx = k-1;
		int temp = v[k];
		while(idx >= 0 && temp < v[idx]) {
			v[idx+1] = v[idx];
			idx--;
			cnt++;
		}
		v[idx+1] = temp;
		cnt++;
	}
	cout << cnt;
}
