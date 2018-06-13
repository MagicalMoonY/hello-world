#include <stdio.h>
#include <time.h>

//long long f1(long long x) {
//	if (x <= 2) return 1;
//	return f1(x-1) - 2*f1(x-2) + 3*f1(x-3);
//}

long f1(long x) {
	static long long y[60] = {1, 1, 1, 0};
	if (y[x]) return y[x];
	
	y[x] = f1(x-1) - 2*f1(x-2) + 3*f1(x-3);
	return y[x];
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int x;
		scanf("%d", &x);
		
		double start = clock();
		
		printf("%ld\n", f1(x));
		
//		printf("time: %lf\n", (clock() - start) / CLOCKS_PER_SEC);
	}
	
	return 0;
}
