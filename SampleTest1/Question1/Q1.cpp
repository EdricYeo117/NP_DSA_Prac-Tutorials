// Q1R.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "List.h"
int main()
{
	List list1;
	list1.sortedInsert(25);
	list1.sortedInsert(80);
	list1.sortedInsert(90);
	list1.sortedInsert(70);
	list1.sortedInsert(24);

	list1.print();
	cout << endl;

	List list2;
	list2.sortedInsertR(85);
	list2.sortedInsertR(90);
	list2.sortedInsertR(70);
	list2.sortedInsertR(20);
	list2.sortedInsertR(24);

	list2.print();
	cout << endl;

}
