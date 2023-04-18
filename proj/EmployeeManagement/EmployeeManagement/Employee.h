#pragma once
#include<iostream>
#include "Staffs.h"
using namespace std;

class Employee :public Staffs
{
public:
	Employee(int ID, string Name, int dID);
	virtual void showInfo();
	virtual string getDeptName();
};