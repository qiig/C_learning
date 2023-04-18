#pragma once
#include<iostream>
#include "Staffs.h"
using namespace std;

class Boss :public Staffs
{
public:
	Boss(int ID, string Name, int dID);
	virtual void showInfo();
	virtual string getDeptName();
};