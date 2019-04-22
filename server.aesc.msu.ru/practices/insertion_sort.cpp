#include <bits/stdc++.h>
using namespace std;

const int MAXN = 600'000;
const int INFI = 2.14e9+100;

int n;
int a[MAXN];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void gen() {
	for (int i = 0; i < n; ++i) {
		a[i] = uniform_int_distribution<int>(0, INFI)(rng);
	}
}

void print() {
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	} cout << endl;
}

void insertion_sort() {
	int i = 0;
	while (i < n) {
		int j = i;
		while (j > 0 && a[j - 1] > a[j]) {
			swap(a[j], a[j - 1]);
			--j;
		}

		++i;
	}
}

const int c = (1<<16);
void radix_sort () {
    vector<int> b[c];
    for (int i = 0; i < n; i++)
        b[a[i]%c].push_back(a[i]);
    int k = 0;
    for (int i = 0; i < c; i++) {
        for (size_t j = 0; j < b[i].size(); j++)
            a[k++] = b[i][j];
        b[i].clear();
    }
    for (int i = 0; i < n; i++)
        b[a[i]/c].push_back(a[i]);
    k = 0;
    for (int i = 0; i < c; i++)
        for (size_t j = 0; j < b[i].size(); j++)
            a[k++] = b[i][j];
}

int main() {
	freopen("input.txt", "r+", stdin);
	vector<int> values = {500, 1000, 2500, 5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000};
	for (int i = 0; i < values.size(); ++i) {
		n = values[i];
		gen();

		chrono::time_point<std::chrono::high_resolution_clock> start, end;
		start = chrono::high_resolution_clock::now();

		//insertion_sort();
		//sort(a, a + n);
		radix_sort();
		//print();

		end = std::chrono::high_resolution_clock::now();
		long long elapsed_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
		cout << "n = " << n << "; " "Elapsed Time: " << elapsed_time / 1'000'000 << "ms" << endl;
	}
}