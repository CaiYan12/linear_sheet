#include <iostream>
#include "linear.h"

LinearSheet::LinearSheet()
{
	length = 0;
}

LinearSheet::LinearSheet(int n)
{
	length = n;
}

LinearSheet::LinearSheet(int n, int data)
{
	length = n;
	for (int i = 0; i < length; i++)
	{
		a[i] = data;
	}
}

void LinearSheet::show()
{
	for (int i = 0; i < length; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

int LinearSheet::setValue(int data, int pos)
{
	if (pos >= length)
	{
		std::cout << "Position out of range!" << std::endl;
		return 0;
	}
	a[pos] = data;
	return data;
}

int LinearSheet::push(int data) {
	a[length] = data;
	length++;
	return data;
}

int LinearSheet::pop() {
	length--;
	return a[length + 1];
}

int LinearSheet::insert(int data, int pos) {
	if (pos >= length) {
		std::cout << "Position out of range!" << std::endl;
		return 0;
	}
	for (int i = length - 1; i >= pos; i--) {
		a[i + 1] = a[i];
	}
	a[pos] = data;
	length++;
	return data;
}

int LinearSheet::remove(int pos) {
	if (pos >= length) {
		std::cout << "Position out of range!" << std::endl;
		return 0;
	}
	int data = a[pos];
	for (int i = pos; i < length; i++) {
		a[i] = a[i + 1];
	}
	length--;
	return data;
}