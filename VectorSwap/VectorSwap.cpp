#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<vector>

using namespace std;

void out(int n, vector<int> a) {

	for (int i = 0;i < n; i++) {
		cout << a[i];
	}
}

void in(int n) {
	int x;
	vector<int> a;
	for (int i = 0;i < n; i++) {
		scanf("%d", &x);
		a.push_back(x);
	}
	exchange(n, a);
	out(n, a);
}

void exchange(int n, vector<int> a) {
	for (int i = 0;i < n; i++ ) {
		if (a[i] > a[n - 1]) {
			swap(a[i], a[n - 1]);
		} 
		if (a[i] < a[0]) {
			swap(a[i], a[0]);
		}
	}
}

int main() {
	int n = 10;
	in(n);
	return 0;
}
