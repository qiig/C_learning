#include "EmpeMg.h"

EmpeMg::EmpeMg()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);	// read file
	// cout << "*****************************************" << endl;
	// no file
	if (!ifs.is_open())
	{
		// cout << "No Data File " << endl;
		this->EmpNum = 0;
		this->stArray = NULL;
		this->FileIsEpt = true;		// No file
		ifs.close();
		return;
	}
	// file is empty
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		// cout << "File Is Empty " << endl;
		this->EmpNum = 0;
		this->stArray = NULL;
		this->FileIsEpt = true;		// No file
		ifs.close();
		return;
	}
	// file is not empty
	int num = this->get_EmpNum();
	// cout << "Records Count:" << num << endl;
	this->EmpNum = num;
	// creat array
	this->stArray = new Staffs * [this->EmpNum];
	this->init_Emp();

#if 0
	for (int i = 0; i < EmpNum; i++)
	{
		cout << this->stArray[i]->ID << " "
			<< this->stArray[i]->Name << " "
			<< this->stArray[i]->DeptID << endl;
	}
#endif
}

EmpeMg::~EmpeMg()
{
	if (this->stArray != NULL)
	{
		delete[] this->stArray;
		this->stArray = NULL;
	}
}

void EmpeMg::Menu()
{
	cout << "*****************************************" << endl;
	cout << "*******  Welcom Employee Manager  *******" << endl;
	cout << "*****************************************" << endl;
	cout << "******* 1.New Staff               *******" << endl;
	cout << "******* 2.Edit Staff              *******" << endl;
	cout << "******* 3.All Staffs              *******" << endl;
	cout << "******* 4.Sort Staffs             *******" << endl;
	cout << "******* 5.Remove Staff            *******" << endl;
	cout << "******* 6.Search Staff            *******" << endl;
	cout << "******* 7.Clear Staffs            *******" << endl;
	cout << "******* 0.Quit Manager            *******" << endl;
	cout << "*****************************************" << endl;
	cout << "*******  Welcom Employee Manager  *******" << endl;
	cout << "*****************************************" << endl;
	cout << endl;
}

void EmpeMg::quitM()
{
	int a;
	cout << "You are exiting Manager ... " << endl;
	cout << "|  0 Cancel  |  1 Exit  |" << endl;
	cin >> a;
	if (a != 1) {
		system("cls");
	}
	else {
		cout << "Exiting ";
		Sleep(200);  cout << "."; Sleep(100); cout << ".";
		Sleep(200); cout << "."; Sleep(100); cout << " ";
		Sleep(100); cout << "."; Sleep(100); cout << ".";
		Sleep(100);  cout << ". " << endl;
		exit(0);
	}
}

void EmpeMg::Add_Emp()
{
#if 1
	cout << "Input number of new staffs: ";
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->EmpNum + addNum;	// new array size
		Staffs** newSpace = new Staffs * [newSize];
		int addIDcnt = 0, addID[ADDIDMAX] = { -1 };	// max new staffs
		// copy old data to new array
		if (this->stArray != NULL)
		{
			for (int i = 0; i < this->EmpNum; i++)
			{
				newSpace[i] = this->stArray[i];
			}
		}
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			int curSize = this->EmpNum;
			while (true)
			{
				cout << "Input No." << i + 1 << "'s Infomation: " << endl;
				cout << "ID: ";
				cin >> id;
				// check used ID
				int res = 0;
				res = this->IsID(id, 0, curSize);
#if 1
				for (int j = 0; j < addIDcnt; j++)
				{
					if (addID[j] == id)
					{
						res = 1; break;
					}
				}
#endif
				if (res != 1)	// ID is space
				{
					cout << "Name: ";
					cin >> name;
					while (true)
					{
						cout << "Department: " << endl;
						cout << "| 1 Employee | 2 Manager |  3 Boss  |" << endl;
						cout << "Select: ";
						cin >> dSelect;
						if (dSelect > 0 && dSelect < 4)
						{
							Staffs* worker = NULL;
							switch (dSelect)
							{
							case 1:
								worker = new Employee(id, name, 1);
								break;
							case 2:
								worker = new Manager(id, name, 2);
								break;
							case 3:
								worker = new Boss(id, name, 3);
								break;
							default:
								break;
							}
							// saving Staffs to array
							newSpace[this->EmpNum + i] = worker;
							addID[addIDcnt++] = id;
							curSize++;
							break;
						}
						else
						{
							cout << "wrong department index " << endl;
						}
					}
					break;
				}
				else
				{
					cout << "Staff ID has been used " << endl;
				}
			}
		}
		// free old array
		delete[] this->stArray;
		this->stArray = newSpace;
		this->EmpNum = newSize;
		this->saveF();	// saving data to file
		this->FileIsEpt = false;
		cout << addNum << " new staffs added " << endl;
	}
	else 
	{
		cout << "error: wrong number. " << endl;
	}
	system("pause");
	system("cls");
#endif
}
void EmpeMg::saveF()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);	// open file by out: write file
	for (int i = 0; i < this->EmpNum; i++)
	{
		ofs << this->stArray[i]->ID << " "
			<< this->stArray[i]->Name << " "
			<< this->stArray[i]->DeptID << endl;
	}
	ofs.close();	// close file
}

int EmpeMg::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id, did;
	string name;
	int cnt = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		cnt++;
	}
	ifs.close();
	return cnt;
}

void EmpeMg::init_Emp()
{
#if 1
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id, did;
	string name;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		int res = 0;
		res = this->IsID(id, 0, index);
#if 0	// get res. about repeating records when init.
		if (res == 1)
		{
			cout << "Repeat ID Record:\t" << id << "\t" << name << "\t" << did << endl;
			this->EmpNum--;
		}
		else
		{
			Staffs* worker = NULL;
			if (did == 1)
			{
				worker = new Employee(id, name, did);
			}
			else if (did == 2)
			{
				worker = new Manager(id, name, did);
			}
			else
			{
				worker = new Boss(id, name, did);
			}
			this->stArray[index] = worker;
			index++;
		}
#endif
#if 1
		if (res == 1)
		{
			cout << "Repeat ID Record:\t" << id << "\t" << name << "\t" << did << endl;
		}
		Staffs* worker = NULL;
		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			worker = new Manager(id, name, did);
		}
		else
		{
			worker = new Boss(id, name, did);
		}
		this->stArray[index] = worker;
		index++;
#endif
	}
	ifs.close();
#endif
}

void EmpeMg::Show_Emp()
{
	if (this->FileIsEpt)
	{
		cout << "No File OR File is Empty " << endl;
	}
	else
	{
		for (int i = 0; i < EmpNum; i++)
		{
			this->stArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

void EmpeMg::Del_Emp()
{
	if (this->FileIsEpt)
	{
		cout << "No File OR File is Empty " << endl;
	}
	else
	{
		cout << "Delete: ";
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)	// id is existing
		{
			int a;
			cout << "You are Delete Staff " << this->stArray[index]->Name << endl;
			cout << "|  0 Cancel  |  1 Delete  |" << endl;
			cin >> a;
			if (a == 1)
			{
				for (int i = index; i < this->EmpNum; i++)
				{
					this->stArray[i] = this->stArray[i + 1];
				}
				this->EmpNum--;
				this->saveF();
				cout << "Delete Succeed " << endl;
			}
			else
			{
				cout << "canceled " << endl;
			}
		}
		else
		{
			cout << "Staff No." << id << " is not existing " << endl;
		}
	}
	system("pause");
	system("cls");
}

int EmpeMg::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->EmpNum; i++)
	{
		if (this->stArray[i]->ID == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void EmpeMg::Mod_Emp()
{
	if (this->FileIsEpt)
	{
		cout << "No File OR File is Empty " << endl;
	}
	else
	{
		int s = 1;	// default: ID
		cout << "Select a method to Edit: " << endl;
		cout << "|  1 ID  |  2 Name  |" << endl;
		cin >> s;
		if (s == 2)	// Name
		{
			cout << "Input Staff Name: ";
			string name;
			cin >> name;
			int flag = 0, firstIndex = 0;;
			for (int i = 0; i < this->EmpNum; i++)
			{
				if (this->stArray[i]->Name == name)
				{
					flag++;
					if (flag == 1) firstIndex = i;
				}
			}
			if (flag == 0)
			{
				cout << "No staff named " << name << endl;
			}
			else if (flag == 1)
			{
				delete this->stArray[firstIndex];
				int res = firstIndex;
				int newId = 0;
				string newName = "";
				int dSelect = 0;
				while (true)
				{
					int res2 = 0, res3 = 0;
					cout << "New ID: ";
					cin >> newId;
					res2 = this->IsID(newId, 0, res);
					res3 = this->IsID(newId, res + 1, this->EmpNum);
					if (res2 == 0 && res3 == 0)
					{
						cout << "New Name: ";
						cin >> newName;
						cout << "New Department: " << endl;
						cout << "| 1 Employee | 2 Manager |  3 Boss  |" << endl;
						cin >> dSelect;

						Staffs* worker = NULL;
						switch (dSelect)
						{
						case 1:
							worker = new Employee(newId, newName, 1);
							break;
						case 2:
							worker = new Manager(newId, newName, 2);
							break;
						case 3:
							worker = new Boss(newId, newName, 3);
							break;
						default:
							break;
						}

						this->stArray[res] = worker;
						this->saveF();
						cout << "Modify Succeed " << endl;
						break;
					}
					else
					{
						cout << "Staff ID has been used " << endl;
					}
				}
			}
			else	// more than one staff named "name"
			{
				bool flag = false;
				int reptS = 0, reptID[ADDIDMAX] = { 0 };	// max repeated name = 20
				bool reptFlag = false;
				for (int i = 0; i < this->EmpNum; i++)
				{
					if (this->stArray[i]->Name == name)
					{
						reptID[reptS++] = this->stArray[i]->ID;
						this->stArray[i]->showInfo();
						flag = true;
					}
				}
				if (!flag)
				{
					cout << "No Staff named " << name << endl;
				}
				while (true)
				{
					cout << "Input Staff ID from repeated Staff Name: ";
					int id;
					cin >> id;
					for (int k = 0; k < reptS; k++)
					{
						if (reptID[k] == id)
						{
							reptFlag = true; break;
						}
					}
					// id in ids of the name
					if (reptFlag)
					{
						int res = this->IsExist(id);
						if (res != -1)
						{
							delete this->stArray[res];

							int newId = 0;
							string newName = "";
							int dSelect = 0;

							while (true)
							{
								int res2 = 0, res3 = 0;
								cout << "New ID: ";
								cin >> newId;
								res2 = this->IsID(newId, 0, res);
								res3 = this->IsID(newId, res + 1, this->EmpNum);
								if (res2 == 0 && res3 == 0)
								{
									cout << "New Name: ";
									cin >> newName;
									while (true)
									{
										cout << "New Department: " << endl;
										cout << "| 1 Employee | 2 Manager |  3 Boss  |" << endl;
										cin >> dSelect;
										if (dSelect > 0 && dSelect < 4)
										{
											Staffs* worker = NULL;
											switch (dSelect)
											{
											case 1:
												worker = new Employee(newId, newName, 1);
												break;
											case 2:
												worker = new Manager(newId, newName, 2);
												break;
											case 3:
												worker = new Boss(newId, newName, 3);
												break;
											default:
												break;
											}

											this->stArray[res] = worker;
											this->saveF();
											cout << "Modify Succeed " << endl;
											break;
										}
										else
										{
											cout << "wrong department index " << endl;
										}
									}
									break;
								}
								else
								{
									cout << "Staff ID has been used " << endl;
								}
							}
						}
						else
						{
							cout << "No Staff ID is " << id << endl;
						}
						break;
					}
					else
					{
						cout << "no " << name << "'s ID is " << id << endl;
					}
				}	
			}
		}
		else if (s == 1)	// ID
		{
			cout << "Input Staff ID: ";
			int id;
			cin >> id;

			int res = this->IsExist(id);
			if (res != -1)
			{
				delete this->stArray[res];

				int newId = 0;
				string newName = "";
				int dSelect = 0;

				while (true)
				{
					int res2 = 0, res3 = 0;
					cout << "New ID: ";
					cin >> newId;
					res2 = this->IsID(newId, 0, res);
					res3 = this->IsID(newId, res + 1, this->EmpNum);
					if (res2 == 0 && res3 == 0)
					{
						cout << "New Name: ";
						cin >> newName;
						while (true)
						{
							cout << "New Department: " << endl;
							cout << "| 1 Employee | 2 Manager |  3 Boss  |" << endl;
							cin >> dSelect;
							if (dSelect > 0 && dSelect < 4)
							{
								Staffs* worker = NULL;
								switch (dSelect)
								{
								case 1:
									worker = new Employee(newId, newName, 1);
									break;
								case 2:
									worker = new Manager(newId, newName, 2);
									break;
								case 3:
									worker = new Boss(newId, newName, 3);
									break;
								default:
									break;
								}

								this->stArray[res] = worker;
								this->saveF();
								cout << "Modify Succeed " << endl;
								break;
							}
							else
							{
								cout << "wrong department index " << endl;
							}
						}
						break;
					}
					else
					{
						cout << "Staff ID has been used " << endl;
					}
				}
			}
			else
			{
				cout << "No Staff ID is " << id << endl;
			}
		}
		else
		{
			cout << "wrong method index " << endl;
		}
	}
	system("pause");
	system("cls");
}

void EmpeMg::Find_Emp()
{
	if (this->FileIsEpt)
	{
		cout << "No File OR File is Empty " << endl;
	}
	else
	{
		cout << "Select a method to Find: " << endl;
		cout << "|  1 ID  |  2 Name  |" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "Input ID: ";
			cin >> id;
			int res = 0;
			res = this->IsExist(id);
			if (res != -1)
			{
				this->stArray[res]->showInfo();
			}
			else
			{
				cout << "No Staff ID is " << id << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "Input Name: ";
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->EmpNum; i++)
			{
				if (this->stArray[i]->Name == name)
				{
					this->stArray[i]->showInfo();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "No Staff named " << name << endl;
			}
		}
		else
		{
			cout << "error: wrong index " << endl;
		}
	}
	system("pause");
	system("cls");
}

int EmpeMg::IsID(int id, int bpos, int epos)
{
	if (epos <= 0) return 0;
	if (bpos >= epos) return 0;
	for (int i = bpos; i < epos; i++)
	{
		if (this->stArray[i]->ID == id)
		{
			return 1;
		}
	}
	return 0;
}

void EmpeMg::Sort_Emp()
{
	if (this->FileIsEpt)
	{
		cout << "No File or File is Empty " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		while (true)
		{
			cout << "Select a rule to sort: " << endl;
			cout << "| 0 Ascending | 1 Descending |" << endl;
			int s1 = 0;		// default: ascending
			cin >> s1;
			if (s1 == 0 || s1 == 1)
			{
				QuickSort(0, this->EmpNum - 1, s1);
				this->saveF();
				cout << "Sort Succeed and Current List is " << endl;
				this->Show_Emp();
				break;
			}
			else
			{
				cout << "wrong method index " << endl;
			}
		}
	}
}

void EmpeMg::Clear_Emp()
{
	cout << "You are Cleaning ALL " << endl;
	cout << "|  1 Cancel  | 0 Go on  | " << endl;
	int select;
	cin >> select;
	if (select != 0)
	{
		cout << "canceled " << endl;
	}
	else
	{
		cout << "You are Cleaning ALL " << endl;
		cout << "|  1 Cancel  | 0 Go on  | " << endl;
		cin >> select;
		if (select != 0)
		{
			cout << "canceled " << endl;
		}
		else
		{
			ofstream ofs(FILENAME, ios::trunc);
			ofs.close();

			if (this->stArray != NULL)
			{
				for (int i = 0; i < this->EmpNum; i++)
				{
					if (this->stArray[i] != NULL)
					{
						delete this->stArray[i];
					}
				}
				this->EmpNum = 0;
				this->stArray = NULL;
				this->FileIsEpt = true;
			}
			cout << "ALL have been cleared " << endl;
		}
	}
	system("pause");
	system("cls");
}

void EmpeMg::QuickSort(int first, int last, int method)
{
	if (method != 0 && method != 1)
	{
		cout << "wrong method index" << endl;
		return;
	}
	if (first >= last) return;	// end of recurrence
	else
	{
		int pivot = Partition(first, last, method);
		QuickSort(first, pivot - 1, method);	// l
		QuickSort(pivot + 1, last, method);		// r
	}
}
int EmpeMg::Partition(int first, int last, int method)
{
	int i = first, j = last;
	Staffs* temp;
	if (method == 0)
	{
		while (i < j)
		{
			while (i < j && this->stArray[i]->ID <= this->stArray[j]->ID) j--;	// scan right area
			if (i < j)
			{
				temp = this->stArray[i]; this->stArray[i] = this->stArray[j];
				this->stArray[j] = temp; i++;
			}
			while (i < j && this->stArray[i]->ID <= this->stArray[j]->ID) i++;	// scan left area
			if (i < j)
			{
				temp = this->stArray[i]; this->stArray[i] = this->stArray[j];
				this->stArray[j] = temp; j--;
			}
		}
	}
	else if (method == 1)	// descending
	{
		while (i < j)
		{
			while (i < j && this->stArray[i]->ID >= this->stArray[j]->ID) j--;	// scan right area
			if (i < j)
			{
				temp = this->stArray[i]; this->stArray[i] = this->stArray[j];
				this->stArray[j] = temp; i++;
			}
			while (i < j && this->stArray[i]->ID >= this->stArray[j]->ID) i++;	// scan left area
			if (i < j)
			{
				temp = this->stArray[i]; this->stArray[i] = this->stArray[j];
				this->stArray[j] = temp; j--;
			}
		}
	}
	else
	{
		cout << "wrong method index " << endl;
		return -1;
	}
	
	return i;	// return pivot
}