#pragma once
#include<iostream>
#include<Windows.h>
#include<fstream>
#include "Staffs.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
#define FILENAME "StaffsData.txt"
using namespace std;

class EmpeMg
{
public:
	EmpeMg();
	~EmpeMg();
	void Menu();	// system menu
	void quitM();	// quit manager system
	int EmpNum;		// the number of employee
	Staffs** stArray;	// staffs array pointer
	void Add_Emp();		// new staff
	void saveF();	// saving file
	bool FileIsEpt;	// file is empty
	int get_EmpNum();	// count the num of records
	void init_Emp();	// init Staffs
	void Show_Emp();	// display all records
	void Del_Emp();		// remove staffs
	int IsExist(int id);	// staffs are existing
	void Mod_Emp();		// modify staffs' info.
	void Find_Emp();	// search staffs by ID or Name
	void Sort_Emp();	// sort ascending or descending
	void Clear_Emp();	// clear all staffs
	int IsID(int id, int bpos, int epos);	// check used ID
private:
	void QuickSort(int first, int last, int method);	// quick sort method
	int Partition(int first, int last, int method);	// for quick sort method
};