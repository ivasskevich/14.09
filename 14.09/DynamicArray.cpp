#include "DynamicArray.h"
#include<Windows.h>

DynamicArray::DynamicArray() :ptr(nullptr), size(0)
{}
DynamicArray::DynamicArray(int S)
{
	cout << "Construct by 1 param\n";
	size = S;
	ptr = new int[S] {0};
}

DynamicArray::DynamicArray(const DynamicArray& a)
{
	cout << "Copy construct\n";
	size = a.size;
	ptr = new int[size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = a.ptr[i];
	}
}
DynamicArray::~DynamicArray()
{
	cout << "Destruct\n";
	if (ptr != 0)
	{
		delete[] ptr;
	}
	Sleep(1000);
}
void DynamicArray::Input()
{
	for (int i = 0; i < size; i++)
	{
		ptr[i] = rand() % 20;
	}
}
void DynamicArray::Output() const
{
	for (int i = 0; i < size; i++)
	{
		cout << ptr[i] << "\t";
	}
	cout << "\n----------------------------------------------------\n";
}
int* DynamicArray::GetPointer() const
{
	return ptr;
}
int DynamicArray::GetSize() const
{
	return size;
}

void DynamicArray::ReSize(int s)
{
	if (size != s) {
		int* newPointer = new int[s];

		for (int i = 0; i < size; i++) {
			newPointer[i] = ptr[i];
		}
		for (int i = size; i < s; i++) {
			newPointer[i] = 0;
		}

		delete[] ptr;
		ptr = newPointer;
		size = s;
	}
	else {
		cout << "Array have same size. Input" << endl;
	}
}

void DynamicArray::Sort()
{
	for (int i = 1; i < size; i++) {
		int key = ptr[i];
		int j = i - 1;

		while (j >= 0 && ptr[j] > key) {
			ptr[j + 1] = ptr[j];
			j = j - 1;
		}
		ptr[j + 1] = key;
	}
}

int DynamicArray::Search(int a)
{
	for (int i = 0; i < size; i++) {
		if (ptr[i] == a) {
			return i;
		}
	}
	return -1;
}

void DynamicArray::Reverse()
{
	int startIndex = 0;
	int endIndex = size - 1;

	while (startIndex < endIndex) {
		int temp = ptr[startIndex];
		ptr[startIndex] = ptr[endIndex];
		ptr[endIndex] = temp;
		startIndex++;
		endIndex--;
	}
}


DynamicArray DynamicArray::operator+(int j)
{
	DynamicArray arr(size + j);
	for (int i = 0; i < size; i++) {
		arr.ptr[i] = ptr[i];
	}

	for (int i = size; i < arr.size; i++) {
		arr.ptr[i] = 0;
	}
	cout << endl;
	return arr;
}


DynamicArray DynamicArray::operator*(int k)
{
	DynamicArray res;
	res.size = this->size;
	res.ptr = new int[res.size];
	for (int i = 0; i < size; i++) {
		res.ptr[i] = ptr[i];
	}

	for (int i = 0; i < res.size; i++) {
		res.ptr[i] *= k;
	}
	return res;
}

DynamicArray DynamicArray::operator-(int count)
{
	int newSize;
	if (count >= size) {
		newSize = 0;
	}
	else {
		newSize = size - count;
	}

	DynamicArray temp(newSize);
	for (int i = 0; i < newSize; i++) {
		temp.ptr[i] = ptr[i];
	}
	return temp;
}


DynamicArray DynamicArray::operator-(const DynamicArray& diff)
{
	if (size != diff.size) {
		return *this;
	}

	DynamicArray mass(size);
	for (int i = 0; i < size; i++) {
		mass.ptr[i] = ptr[i] - diff.ptr[i];
	}
	return mass;
}

DynamicArray DynamicArray::operator+(DynamicArray sum)
{
	DynamicArray summ(size + sum.size);
	for (int i = 0; i < size; i++) {
		summ.ptr[i] = ptr[i];
	}

	for (int i = size; i < summ.size; i++) {
		summ.ptr[i] = sum.ptr[sum.size - i - 1];
	}
	return summ;
}

DynamicArray& DynamicArray::operator++()
{
	if (size > 0) {
		int* newPtr = new int[size + 1];
		for (int i = 0; i < size; i++) {
			newPtr[i] = ptr[i];
		}
		newPtr[size] = 0;
		delete[] ptr;
		ptr = newPtr;
		size++;
	}
	else {

		delete[] ptr;
		ptr = new int[1];
		ptr[0] = 0;
		size = 1;
	}
	return *this;
}


DynamicArray& DynamicArray::operator--()
{
	if (size > 0) {
		int* newPtr = new int[size - 1];
		for (int i = 0; i < size - 1; i++) {
			newPtr[i] = ptr[i];
		}
		delete[] ptr;
		ptr = newPtr;
		size--;
	}
	return *this;
}
