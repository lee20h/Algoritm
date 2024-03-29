#include <bits/stdc++.h>
using namespace std;

struct mat {
	int r, c;
};
mat m[101];

int dp[101][101];

int sol(int x, int y) {
	if (x==y) return 0;
	int& ref = dp[x][y];
	if (ref != -1) return ref;
	int temp = 987654321;
	for (int k=x; k<y; k++) {
		temp = min(temp, sol(x,k) + sol(k+1,y) + m[x].r * m[k].c * m[y].c);
	}
	return ref = temp;
	
}

int main() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> m[i].r >> m[i].c;
	}
	memset(dp, -1, sizeof(dp));
	int ans = sol(0,n-1);
	cout << ans;
}
