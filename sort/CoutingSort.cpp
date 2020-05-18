#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int e_max = 0;
int e_min = 987654321;
vector<int> a;
vector<int> b;
vector<int> c;

void coutingSort(int n) {
	int k = e_max - e_min + 1;
	for (int i=0; i<k; i++)
		c.push_back(0);
	for (int i=0; i<n; i++)
		c[a[i]-e_min]++;
	for (int i=1; i<k; i++)
		c[i] += c[i-1];
		
	for (int i=0; i<k; i++)
		cout << c[i] << ' ';
	/*
	for (int i=n-1; i>=0; i--) {
		b[c[a[i]-e_min]] = a[i];
		c[a[i]-e_min]--;
	}*/
}


int main() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		temp > e_max ? e_max = temp : 1;
		temp < e_min ? e_min = temp : 1;
		a.push_back(temp);
	}
	coutingSort(n);
}
