// lab1_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int wyszukiwanie(int* list_num, int size, int searchin_for_n);

int main()
{
	int iteration;


    int* list_num;
    int* searchin_for_n;
    int size;
    int size_search;

	cin >> iteration;
	while (iteration >0)
	{
		cin >> size;
		list_num = (int*)malloc(sizeof(int) * size);
		for (int x = 0; x < size; x++)
		{
			cin >> list_num[x];

		}
		cin >> size_search;           //ile ma znalezc elementow
		searchin_for_n = (int*)malloc(sizeof(int) * size_search);
		for (int n = 0; n < size_search; n++)
		{
			cin >> searchin_for_n[n];
		}
        for (int p = 0; p < size_search; p++)
        {
            cout<< wyszukiwanie(list_num, size, searchin_for_n[p]) << endl;
        }
		iteration--;
	}
}
int wyszukiwanie(int* list_num, int size, int searchin_for_n)
{

    if ((size == 1) && (searchin_for_n == list_num[0]))// czy posuje pierwsza liczba 
    {
        return 0;
    }
    else if (size == 1)
    {
        return -1;
    }
    if (list_num[0] > list_num[size - 1])//rosnie czy malee(ciąg malegąćy)
    {
        if (list_num[size / 2] == searchin_for_n)//czy posuje średni element
        {
            return size / 2;//zwraca index
        }
        else if (list_num[size / 2] > searchin_for_n)//sprawdza czy środkowa większa od szukanej
        {
            int temporary = wyszukiwanie(list_num + (size / 2), size - (size / 2), searchin_for_n);

            if (temporary == -1)
            {
                return -1;
            }

            return (size / 2) + temporary;

        }
        else if (list_num[size / 2] < searchin_for_n)//sprawdza czy środkowa mniejsz od szukanej
        {
            return wyszukiwanie(list_num, size / 2, searchin_for_n);// przekazuje to , co dostałem 
        }

    }
    else//(ciąg rośnie)
    {

        if (list_num[size / 2] == searchin_for_n)//czy posuje średni element
        {

            return size / 2;
        }
        else if (list_num[size / 2] < searchin_for_n)
        {
            int temporary = wyszukiwanie(list_num + (size / 2), size - (size / 2), searchin_for_n);

            if (temporary == -1)
            {
                return -1;
            }

            return (size / 2) + temporary;

        }
        else if (list_num[size / 2] > searchin_for_n)
        {

            return wyszukiwanie(list_num, size / 2, searchin_for_n);
        }
    }



    return -1;
}


