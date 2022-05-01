#include <vector>
#include <iostream>

using namespace std;
template <typename T> //타입을 쓸때 T로 대신하겠다는 내용 대신 속도가 느려짐

T sum(T a,T b) {
	return a + b;
}


int main() {

	vector<int> a;

	cout << sum<double>(5.0, 3.434) << endl;

	a.push_back(1);
	a.push_back(2);

	cout << a.size() << endl;

	a.push_back(4);
	a.push_back(8);
	a.push_back(16);

	cout << a.size() << endl;

	cout << a[0] << endl;
	cout << a[3] << endl;

	return 0;
}