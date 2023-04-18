#pragma once
#include<iostream>
#include<string>
using namespace std;

class Staffs
{
public:
	virtual void showInfo() = 0;	// display staff's infomation
	virtual string getDeptName() = 0;	// get department name
	int ID;
	int DeptID;
	string Name;
};