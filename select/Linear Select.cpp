#include <iostream>
#include <cmath>
using namespace std;

int partition(int v[], int p, int r)
{
   int x = v[r];
   int i = p - 1;
   for (int j=p; j<=r-1; j++)
 	  	if(v[j] <= x) {
	     	int temp = v[++i];
	     	v[i] = v[j];
	     	v[j] = temp;
		}
	int temp = v[i+1];
	v[i+1] = v[r];
	v[r] = temp;
   return i + 1;
}

int partitionByMedian(int v[], int p, int r, int M){
   int idx;
	for (int i=p; i<=r; i++) {
		if(v[i] == M){
			idx = i;
			break;
		}		
	}
	
	int temp = v[idx];
	v[idx] = v[r];
	v[r] = temp;
 
   return partition(v, p, r);
}

int select(int v[], int p, int r, int i) //배열 A[p..r]에서 i번째를 찾는다.
{
   if(p == r) return v[p];
   int q = partition(v, p, r);
   int k = q - p + 1;
   if(i < k) return select(v, p, q - 1, i);
   else if(i > k) return select(v, q + 1, r, i - k);
   else return v[q]; //i == k
}

int linearSelect(int v[], int p, int r, int idx){
	
	int middle[2001];
	
	int size = r-p+1;
    if (size<=5) {
    	return select(v,p,r,idx);
	}
	
	int a = ceil((double)size/5);
	int b = size % 5;
	int temp = p;
	for (int i=1; i<=a; i++) {
		if((i == a) && b) {
			if(b%2==0)
				middle[i] = select(v, temp, temp+b-1, b/2);
			else 
				middle[i] = select(v, temp, temp+b-1, b/2 + 1);
		}
		else {
			middle[i] = select(v,temp,temp+4,3);
			temp += 5;
		}
	}
	int c = ceil((double)a/2);
	int m = linearSelect(middle, 1, a, c);
 	cout << m << '\n';
 	int q = partitionByMedian(v, p, r, m);
 	
 	int k = q - p + 1;
 	
 	if(k>idx) return linearSelect(v,p,q-1,idx);
 	else if (k<idx) return linearSelect(v,q+1,r,idx-k);
 	else return v[q];
}

int main() {
	int idx;
	int n;
	int v[10001];
	cin >> n >> idx;
	for (int i=1; i<=n; i++)
		cin >> v[i];
	linearSelect(v,1,n,idx);
}
