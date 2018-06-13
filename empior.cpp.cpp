#include <stdio.h>
#include <string.h>

#define N 1000

/*

        0      1      2      3      4      5
a    3837   1001    384    167    166      1
c                     3      1      4      1
x                    -6      5     -1      1
y                    23     -6      5     -1


a[k] = a[k - 2] % a[k - 1];
c[k] = a[k - 2] / a[k - 1];


a[k] = a[k - 2] - c[k] * a[k - 1]

a[k] = x[k] * a[k - 2] + y[k] * a[k - 1]
     = x[k] * a[k - 2] + y[k] * (a[k - 3] - c[k - 1] * a[k - 2])
     = x[k] * a[k - 2] + y[k] * a[k - 3] - y[k] * c[k - 1] * a[k - 2]
     = y[k] * a[k - 3] + (x[k] - y[k] * c[k - 1]) * a[k - 2]
     = x[k - 1] * a[k - 3] + y[k - 1] * a[k - 2]

Ыљвд    
x[k - 1] = y[k]
y[k - 1] = x[k] - y[k] * c[k - 1]


*/



long a[N];
long c[N];
long x[N];
long y[N];


void f1(int k) {
	a[k] = a[k - 2] % a[k - 1];
	c[k] = a[k - 2] / a[k - 1];
	printf("%d = %d - %d * %d\n", a[k], a[k - 2], c[k], a[k - 1]);
	
	if (a[k] == 1) {
		x[k] = 1;
		y[k] = -c[k];
		
		printf("\n1\n");
		printf("  = %d * %d + %d * %d\n", x[k], a[k - 2], y[k], a[k - 1]);
		
		return;
	}
	
	f1(k + 1);
	
	x[k] = y[k + 1];
	y[k] = x[k + 1] - c[k] * y[k + 1];

	printf("  = %d * %d + %d * %d\n", x[k], a[k - 2], y[k], a[k - 1]);
}


int main() {
	for (; ; ) {
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		
		scanf("%ld%ld", &a[1], &a[0]);
		if (a[0] == 0 && a[1] == 0) break;
		
		f1(2);
		
		if (y[2] < 0) {
			printf("%ld\n", y[2] + a[0]);
		} else {
			printf("%ld\n", y[2]);
		}
	}
	
	
	return 0;
}

