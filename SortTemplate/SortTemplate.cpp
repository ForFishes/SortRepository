// SortTemplate.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"Sort.h"
#include<assert.h>
int main()
{
	vector<int>vec = { 7,3,2,5,7,8 };
	CSort::Selectsort(vec);
	assert(CSort::isSorted(vec));
	CSort::show(vec);
    return 0;
}

