#include <iostream>
using namespace std;
class Euclidean{
	public:
		Euclidean(long long int a, long long int n) {
			this->a = a;
			this->n = n;
		}
		~Euclidean() {}
		
		void solve_equation() {
			int j, p = a, q = n, r, s = 0;//p除数 q被除数 r商 s余数 
			for (j = 0; s!= 1; j++) {
				r = q / p;
				b[j] = r;
				s = q % p;
				q = p;
				p = s;
			}

			int t = j;
			j--;
			c[0] = 1;
			c[1] = b[j];
		j--;
			int i;
			for (i = 2; j >= 0; i++) {
				c[i] = c[i - 2] + c[i - 1] * b[j];
				j--;
			}
			i--;
			if (t % 2) {
				c[i] = n - c[i]; 
			}
			cout << c[i] << endl;
		}
		
		
	private:
		int b[100000];//商 
		int c[100000];//中间值 
		long long int a, n;
};

int main() {
	long long int a, n; //a除数 n被除数 
	while(1) {
		cin >> a >> n;
		if (a == 0 && n == 0) {
			break;
		}
		Euclidean Ecalgo(a, n);
		Ecalgo.solve_equation();
	}
	return 0;
}
