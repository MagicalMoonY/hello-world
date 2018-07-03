
#include <iostream>
using namespace std;
 
int n, V, hfV;
int v[50001], c[50001];
int f[50001];
 
int main() {
	cin >> n;
	for(int i=1; i<=n; i++) cin >> v[i];
	for(int i=1; i<=n; i++) {
		V += v[i];
		c[i] = v[i];
	}
	hfV = V/2;
	for(int i=1; i<=n; i++) 
		for(int j=hfV; j>=v[i]; j--)
			f[j] = max(f[j], f[j-v[i]] + c[i]);
	if(V % 2 == 0) cout << (hfV - f[hfV]) * 2 << endl;
	else cout << V - 2 * f[hfV] << endl;
	return 0;
}
