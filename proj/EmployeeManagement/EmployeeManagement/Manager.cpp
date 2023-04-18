#include "Manager.h"

Manager::Manager(int ID, string Name, int dID)
{
	this->ID = ID;
	this->Name = Name;
	this->DeptID = dID;
}

void Manager::showInfo()
{
	cout << "ID: " << this->ID;
	cout << "\tName:" << this->Name;
	cout << "\tDept:" << this->getDeptName();
	cout << "\tDuty: Finish works given by Boss. " << endl;
}

string Manager::getDeptName()
{
	return string("Manager");
}