#include <iostream>
#include "linear.h"

LinearSheet::LinearSheet() {
	length = 0;
}

LinearSheet::LinearSheet(int n) {
	length = n;
}

LinearSheet::LinearSheet(int n, int data) {
	length = n;
	for (int i = 0; i < length; i++) {
		a[i] = data;
	}
}

void LinearSheet::show() {
	for (int i = 0; i < length; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

void LinearSheet::setValue(int data, int pos) {
	a[pos] = data;
}
