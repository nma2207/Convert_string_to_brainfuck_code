// string_to_bf.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<list>
#include<string>
#include<math.h>
using namespace std;
	//>	перейти к следующей €чейке
	//<		перейти к предыдущей €чейке
	//+ 	увеличить значение в текущей €чейке на 1
	//- 	уменьшить значение в текущей €чейке на 1
	//.	напечатать значение из текущей €чейки
	//, 	ввести извне значение и сохранить в текущей €чейке
	//[
	//	если значение текущей €чейки ноль, перейти вперЄд по тексту программы на €чейку, следующую за соответствующей](с учЄтом вложенности)
	//]

list<char>string_to_bf(string s)
{
	char arr[30000];
	int arr_i = 0;
	int arr_n = 1;
	for (int i = 0; i < 30000; i++)
		arr[i] = 0;
	//delete[]res;
	list<char> res;
	for (int i = 0; s[i] != '\0'; i++)
	{
		int min_d = 0;
		for (int j = 0;j < arr_n; j++)
		{
			if (abs(arr[min_d] - s[i])>abs(arr[j] - s[i]))
				min_d = j;
		}
		if (min_d < arr_i)
		{
			for (int j = 0; j < arr_i - min_d; j++)
			{
				res.push_back('<');
			}
		}
		else
		{

			for (int j = 0; j < min_d - arr_i; j++)
			{
				res.push_back('>');
			}
		}
		arr_i = min_d;
		//printf("%d, %d, %d\n", arr_i, (int)s[i], (int)arr[arr_i]);
		if (s[i] >arr[arr_i])
		{

			for (int j = 0; j < s[i] - arr[arr_i]; j++)
			{
				res.push_back('+');
			}
		}
		else
		{

			for (int j = 0; j < arr[arr_i] - s[i]; j++)
			{

				res.push_back('-');
			}
		}
		arr[arr_i] = s[i];
		res.push_back('.');
		if (min_d == arr_n - 1)
			arr_n++;
	}
	return res;
}
int main()
{
	string input;
	getline(cin,input);
	ofstream in("hw.txt");
	 list<char>s=string_to_bf(input);
	 for (list<char>::iterator i = s.begin(); i != s.end(); i++)
		 in << *i;
	 printf("%d\n", s.size());
	 in.close();
	return 0;
}

