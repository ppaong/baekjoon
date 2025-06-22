#include <iostream>
#include <cmath>
#include <complex>
using namespace std;
const double PI = acos(-1);
typedef complex<double> cp;


unsigned bitreverse(unsigned bit, unsigned bitsize) {
	unsigned k = 0;
	for (unsigned i = 0; i < bitsize; ++i)
		k |= ((bit >> i) & 1) << (bitsize - i - 1);
	return k;
}

void fft(cp* seq,int len,bool inverse = false) {

	unsigned int N = 1;
	unsigned int logN = 0;
	for (;N < len;N <<= 1) logN++;

	for (unsigned i = 0; i < N; i++) {
		unsigned j = bitreverse(i, logN);
		if (i < j) swap(seq[i], seq[j]);
	}

	for (int i = 1;i <= logN;i++) {
		int m = 1 << i;
		cp wn(cos(2 * PI / m), (inverse ? -1 : 1) * sin(2 * PI / m));
		for (int j = 0;j < N;j += m) {
			cp w(1, 0);
			for (int k = 0;k < (m >> 1);k++) {
				cout << m << "," << wn << " : " << w << "\n";
				cp u = seq[j + k];
				cp t = w * seq[j + k + (m >> 1)];
				seq[j + k] = u + t;
				seq[j + k + (m >> 1)] = u - t;
				w *= wn;
			}
		}
	}
	if (inverse)
		for (int i = 0;i < N;i++)
			seq[i] /= N;
}
void print(cp* seq, int n) {
	for (int i = 0;i < n;i++)
		cout << seq[i] << " ";
	cout << "\n";
}
int main() {
	cp A[] = { 1,2,3,4,5,0,0,0 };
	cp B[] = { 4,3,2,1,0,0,0,0 };
	
}
