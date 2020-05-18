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
	for (int k=n-1; k>0; k--) {
		int max = v[0];
		int idx = 0;
		for (int i=0; i<=k; i++) {
			if(max < v[i]) {
				max = v[i];
				idx = i;
				cnt++;
			}
		}
		
		int temp = v[k];
		v[k] = v[idx];
		v[idx] = temp;
	}
	
	cout << cnt;
}
