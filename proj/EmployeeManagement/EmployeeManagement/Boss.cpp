#include "Boss.h"

Boss::Boss(int ID, string Name, int dID)
{
	this->ID = ID;
	this->Name = Name;
	this->DeptID = dID;
}

void Boss::showInfo()
{
	cout << "ID: " << this->ID;
	cout << "\tName:" << this->Name;
	cout << "\tDept:" << this->getDeptName();
	cout << "\tDuty: Divide works to Managers. " << endl;
}

string Boss::getDeptName()
{
	return string("Boss");
}