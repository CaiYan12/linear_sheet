#pragma once

class LinearSheet
{
private:
	int a[100005];
	int length;

public:
	LinearSheet();
	LinearSheet(int n);
	LinearSheet(int n, int data);

	void show();

	int setValue(int data, int pos);

	int push(int data);
	int pop();

	int insert(int data, int pos);
	int remove(int pos);
};