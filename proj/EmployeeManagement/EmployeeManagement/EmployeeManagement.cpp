#include<iostream>
#include "EmpeMg.h"
#include "Staffs.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

using namespace std;

int main()
{
#if 1
	int select;	// Input: Select a Method
	EmpeMg Em;

	while (true)
	{
		Em.Menu();
		cout << "Select a Method: ";
		cin >> select;

		switch (select)
		{
		case 0:	// 0.Quit Manager
			Em.quitM();
			break;
		case 1:	// 1.New Staff
			Em.Add_Emp();
			break;
		case 2:	// 2.Edit Staff
			Em.Mod_Emp();
			break;
		case 3:	// 3.All Staffs
			Em.Show_Emp();
			break;
		case 4:	// 4.Sort Staffs
			Em.Sort_Emp();
			break;
		case 5:	// 5.Remove Staff
			Em.Del_Emp();
			break;
		case 6:	// 6.Search Staff 
			Em.Find_Emp();
			break;
		case 7:	// 7.Clear Staffs
			Em.Clear_Emp();
			break;
		default:
			system("cls");
			break;
		}
	}
#endif
	// test classes
#if 0
	Staffs* w = NULL;
	w = new Employee(1, "ÕÅÈý", 1);
	w->showInfo();
	delete w;

	w = new Manager(2, "Tom", 2);
	w->showInfo();
	delete w;

	w = new Boss(3, "Job", 3);
	w->showInfo();
	delete w;
#endif
	system("pause");
	return 0;
}