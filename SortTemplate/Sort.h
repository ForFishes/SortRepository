#pragma once
#include<vector>
#include<iostream>
#include<functional>
using namespace std;
template<typename Compare>
class CSort
{
public:
	CSort();
	~CSort();

	static bool isSorted(vector<Compare>& a)
	{
		for (size_t i = 1; i < a.size(); i++)
		{
			if (less(a[i], a[i-1]))return false;
		}
		return true;
	}
	//ѡ�������ʵ�֣���������

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

	static void Insertsort(vector<Compare>& a)
	{
		int N = a.size();
		for (int i = 1; i != N; ++i)
		{
			for (int j = i; j > 0 && less(a[j], a[j - 1]); --j)
				exch(a, j, j - 1);
		}
	}
	//ϣ������

	static void Shellsort(vector<Compare>& a)
	{
		int N = a.size();
		int h = 1;
		while (h<N/3)
		{
			h = 3 * h + 1;
		}
		while (h>=1)
		{
			for (int i = h; i < N; ++i)
			{
				for (int j = i; j >= h && less(a[j], a[j - h]); j -= h)
				{
					exch(a, j, j - h);
				}
			}
			h = h / 3;
		}
	}
	//�鲢����

	static void Merge(vector<Compare>& a, int lo, int mid, int hi)
	{
		int i = lo, j = mid + 1;
		for (int k = lo; k <= hi; ++k)
		{
			aux[k] = a[k];
		}
		for (int k = lo; k <= hi; ++k)
		{
			if (i > mid)					a[k] = aux[j++];
			else if (j > hi)				a[k] = aux[i++];
			else if (less(aux[j], aux[i]))	a[k] = aux[j++];
			else							a[k] = aux[i++];
		}
	}

	static void MergeSort(vector<Compare>& a)
	{
		//vector<Compare> aux;
		aux.resize(a.size());//һ���Է���ռ�
		//aux = new vector<Compare>(a.size());
		MergeSort(a, 0, a.size() - 1);
	}

	static void show(vector<Compare>& a)
	{
		for (auto i : a)
		{
			cout << i << endl;
		}
	}
private:

	static bool less(Compare& v, Compare& w)
	{
		return v<w;//������С��
				   //return std::less() < v, w > ;
	}

	static void exch(vector<Compare>& a, int i, int j)
	{
		Compare t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	//�鲢�������������
	static vector<Compare> aux;
	static void MergeSort(vector<Compare>& a, int lo, int hi)
	{
		if (hi <= lo)return;//��������ֹ����
		int mid = lo + (hi - lo) / 2;
		MergeSort(a, lo, mid);
		MergeSort(a, mid + 1, hi);
		Merge(a, lo, mid, hi);
	}
};

