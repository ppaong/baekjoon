#include <iostream>
using namespace std;

/*
some class
heap(max)
parametric_search
*/
//==============================================================================
template <typename T>
class heap{
private :
	T* array;
	unsigned int max_size;
	unsigned int count;
public:
	heap(unsigned int size) : max_size(size + 1), count(0) {
		array = new T[max_size + 1];
	}
	heap() { heap(100); }
	heap(heap& obj) {
		heap(obj.max_size);
		for (int i = 0;i < obj.count;i++)
			this->array[i] = obj.array[i];
	}

	T top() { return array[0]; }
	int size() { return count; }
	bool empty() { return count == 0; }

	void pop() {
		count--;
		array[0] = array[count];
		unsigned int p = 0;
		unsigned int q = 1;
		for (;q < count;q <<= 1) {
			if (array[q] < array[q + 1])
				if (++q >= count)
					q--;
			if (array[p] < array[q])
				swap(array[p], array[q]);
			else
				break;
			p = q;
		}
	}
	void push(T data) {
		array[count] = data;
		unsigned int p = count >> 1;
		unsigned int q = count;
		for (;array[p] < array[q];p >>= 1) {
			swap(array[p], array[q]);
			q = p;
		}
		count++;
	}
};
//==============================================================================
int parametric_search(int* _First, int* _Last, const int& Val) {
	int L = 0, R = _Last - _First - 1, M = (L + R) >> 1;
	for (;L <= R;M = (L + R) >> 1) {
		if (_First[M] >= Val)// >= not contain Val , > contain Val
			R = M - 1;
		else
			L = M + 1;
	}
	return R;
}
//==============================================================================

int main(){
    cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
}