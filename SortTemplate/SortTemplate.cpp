// SortTemplate.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"Sort.h"
#include<assert.h>
#include<ctime>
#include<random>
using namespace std;
int main()
{
	
	static default_random_engine e(time(0));
	static uniform_int_distribution<int> u(1, 1000000000);
	vector<int>vec;
	for (size_t i = 0; i < 100; i++)
	{
		vec.push_back(u(e));
	}

	CSort<int>::MergeSort(vec);
	assert(CSort<int>::isSorted(vec));
	CSort<int>::show(vec);
    return 0;
}

