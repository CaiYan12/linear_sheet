#pragma once

class LinearSheet {
private:
	int a[100005];
	int length;
public:
	LinearSheet();
	LinearSheet(int n);
	LinearSheet(int n, int data);
	void show();
	void setValue(int data, int pos);
};