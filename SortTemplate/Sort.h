#pragma once
template<typename Compare>
class CSort
{

public:
	CSort();
	~CSort();
private:
	static bool less(Compare v, Compare w);
	static void exch(Compare *a, int i, int j);
	static void show(Compare *a);
};

