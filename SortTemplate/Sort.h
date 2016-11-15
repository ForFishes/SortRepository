#pragma once
#include<vector>
#include<iostream>
#include<functional>
using namespace std;
class CSort
{
public:
	CSort();
	~CSort();
	template<typename Compare>
	static bool isSorted(vector<Compare>& a)
	{
		for (size_t i = 1; i < a.size(); i++)
		{
			if (less(a[i], a[i-1]))return false;
		}
		return true;
	}
	//ѡ�������ʵ�֣���������
	template<typename Compare>
	static void Selectsort(vector<Compare>& a)
	{
		int N = a.size();
		for (int i = 0; i != N; ++i)
		{
			int min = i;
			//����Ѱ����С�ĽǱ�
			for (int j = i + 1; j != N; ++j)
			{
				if (less(a[j], a[min]))
				{
					min = j;
				}
			}
			exch(a, i, min);
		}
	}
	//��������
	template<typename Compare>
	static void Insertsort(vector<Compare>& a)
	{
		int N = a.size();
		for (int i = 1; i != N; ++i)
		{
			for (int j = i; j > 0 && less(a[j], a[j - 1]); --j)
				exch(a, j, j - 1);
		}
	}
	template<typename Compare>
	static void show(vector<Compare>& a)
	{
		for (auto i : a)
		{
			cout << i << endl;
		}
	}
private:
	template<typename Compare>
	static bool less(Compare& v, Compare& w)
	{
		return v<w;//������С��
				   //return std::less() < v, w > ;
	}
	template<typename Compare>
	static void exch(vector<Compare>& a, int i, int j)
	{
		Compare t = a[i];
		a[i] = a[j];
		a[j] = t;
	}

};

