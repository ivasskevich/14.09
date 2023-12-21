#pragma once
#include "DynamicArray.h"

DynamicArray GetObj()
{
	DynamicArray obj(2);
	obj.Input();
	return obj;
}

void main()
{
	DynamicArray a(10);
	a.Input();
	a.Output();
	
	DynamicArray b(3);
	b.Input();
	DynamicArray plusTenElems = a + 10;
	plusTenElems.Output();
	DynamicArray minusTwoElems = a - 2;
	minusTwoElems.Output();
	DynamicArray multiplyElems = a * 2;
	multiplyElems.Output();
	DynamicArray diffArr = a - b;
	diffArr.Output();
	DynamicArray SumArr = a + b;
	SumArr.Output();
	DynamicArray plusplusA(a);
	plusplusA.Input();
	++plusplusA;
	plusplusA.Output();
	DynamicArray minusminusA(b);
	minusminusA.Input();
	--minusminusA;
	minusminusA.Output();

	system("pause");
}