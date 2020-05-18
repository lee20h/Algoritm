#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int> v;
	int cnt = 0;
	cin >> n;
	for (int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	
	for (int k=n-1; k>0; k--) {
		for (int i=0; i<k; i++) {
			if(v[i] > v[i+1]) {
				int temp = v[i+1];
				v[i+1] = v[i];
				v[i] = temp;
				cnt++;
			}
		}
	}
	cout << cnt;
}
