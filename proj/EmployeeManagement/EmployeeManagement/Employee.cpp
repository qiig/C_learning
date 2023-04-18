#include "Employee.h"

Employee::Employee(int ID, string Name, int dID)
{
	this->ID = ID;
	this->Name = Name;
	this->DeptID = dID;
}

void Employee::showInfo()
{
	cout << "ID: " << this->ID;
	cout << "\tName:" << this->Name;
	cout << "\tDept:" << this->getDeptName();
	cout << "\tDuty: Finish works given by Managers. " << endl;
}

string Employee::getDeptName()
{
	return string("Employee");
}
