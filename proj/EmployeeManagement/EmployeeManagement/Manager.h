#pragma once
#include<iostream>
#include "Staffs.h"
using namespace std;

class Manager :public Staffs
{
public:
	Manager(int ID, string Name, int dID);
	virtual void showInfo();
	virtual string getDeptName();
};