#include<iostream>
#include<iomanip>
#include<string>
#define MAX 1000
using namespace std;

// Contact Struct
struct  Person
{
	string name;
	string sex;
	string age;
	string phone;
	string addr;
};
// List
struct AddBook
{
	struct Person pArray[MAX];
	int size;
};

// newContact
void newContact(AddBook* adb)
{
	if (adb->size == MAX) {
		cout << "Failed creating: Full " << endl;
		return;
	}
	else {
		cout << "Input name:  ";
		cin >> adb->pArray[adb->size].name;
		string sex;
		while (true) {
			cout << "Input sex:   " << endl;
			cout << "1 -- male " << endl;
			cout << "2 -- female " << endl;
			cin >> sex;
			if (sex == "1") {
				adb->pArray[adb->size].sex = "male";
				break;
			}
			if (sex == "2") {
				adb->pArray[adb->size].sex = "female";
				break;
			}
			cout << "Wrong sex index ... " << endl;
		}
		cout << "Input age:   ";
		cin >> adb->pArray[adb->size].age;
		cout << "Input phone: ";
		cin >> adb->pArray[adb->size].phone;
		cout << "Input addr:  ";
		cin >> adb->pArray[adb->size].addr;
		// update size
		adb->size++;
		cout << "Creating Succeed. " << endl;

		system("pause");
		system("cls");
	}
}

// showList
void showList(AddBook* adb) {
	if (adb->size == 0) {
		cout << "Empty List ... " << endl;
	}
	else {
		for (int i = 0; i < adb->size; i++) {
			cout << "No." << i + 1 << endl;
			cout << "Name:  " << adb->pArray[i].name << endl;
			cout << "Sex:   " << adb->pArray[i].sex << endl;
			cout << "Age:   " << adb->pArray[i].age << endl;
			cout << "Phone: " << adb->pArray[i].phone << endl;
			cout << "Addr:  " << adb->pArray[i].addr << endl;
		}
	}

	system("pause");
	system("cls");
}

// isExist	return index OR -1
int isExist(AddBook* adb, string name) {
	for (int i = 0; i < adb->size; i++) {
		if (adb->pArray[i].name == name) {
			return i;
		}
	}
	return -1;
}

// deleteContact
void deleteContact(AddBook* adb, string name) {
	int a = isExist(adb, name);
	if (a == -1) {
		cout << "No " << name << endl;
		return;
	}
	for (int i = a; i < adb->size; i++) {
		adb->pArray[i] = adb->pArray[i + 1];
	}
	adb->size--;
	cout << " Deleted. " << endl;
	system("pause");
	system("cls");
}

// searchContact
void findContact(AddBook* adb, string name) {
	int i = isExist(adb, name);
	if (i == -1) {
		cout << "No " << name << endl;
		return;
	}
	cout << "Name:  " << adb->pArray[i].name << endl;
	cout << "Sex:   " << adb->pArray[i].sex << endl;
	cout << "Age:   " << adb->pArray[i].age << endl;
	cout << "Phone: " << adb->pArray[i].phone << endl;
	cout << "Addr:  " << adb->pArray[i].addr << endl;
	system("pause");
	system("cls");
}

// Edit Contact
void editContact(AddBook* adb, string name) {
	int a = isExist(adb, name);
	if (a == -1) {
		cout << "No " << name << endl;
		return;
	}
	cout << "Input name:  ";
	cin >> adb->pArray[adb->size].name;
	string sex;
	while (true) {
		cout << "Input sex:   " << endl;
		cout << "1 -- male " << endl;
		cout << "2 -- female " << endl;
		cin >> sex;
		if (sex == "1") {
			adb->pArray[adb->size].sex = "male";
			break;
		}
		if (sex == "2") {
			adb->pArray[adb->size].sex = "female";
			break;
		}
		system("cls");
		cout << "Wrong sex index ... " << endl;
	}
	cout << "Input age:   ";
	cin >> adb->pArray[adb->size].age;
	cout << "Input phone: ";
	cin >> adb->pArray[adb->size].phone;
	cout << "Input addr:  ";
	cin >> adb->pArray[adb->size].addr;
	cout << "Editing Succeed. " << endl;

	system("pause");
	system("cls");
}

// Delete List
void deleteList(AddBook* adb) {
	int a = 0;
	if (adb->size == 0) {
		cout << "Empty List. " << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "sure to delete list ?  1 -- cancel  2 -- delete " << endl;
	cin >> a;
	if (a != 2) {
		system("cls");
		return;
	}
	adb->size = 0;
	cout << "List Deleted. " << endl;
	system("pause");
	system("cls");
}

// menu
void showMenu() {
	cout << "*****************************" << endl;
	cout << "***** 1.New Contact	*****" << endl;
	cout << "***** 2.Show List	*****" << endl;
	cout << "***** 3.Remove Contact	*****" << endl;
	cout << "***** 4.Find Contact	*****" << endl;
	cout << "***** 5.Edit Contact	*****" << endl;
	cout << "***** 6.Delete List	*****" << endl;
	cout << "***** 0.Quit		*****" << endl;
	cout << "*****************************" << endl;
}

int main() {
	AddBook adb;
	string name;
	// init adb
	adb.size = 0;
	int select = 0;
	while (true) {
		showMenu();
		cout << "Input: ";
		cin >> select;
		switch (select)
		{
		case 1:	// 1.New Contact
			newContact(&adb);
			break;
		case 2:	// 2.Show List
			showList(&adb);
			break;
		case 3:	// 3.Remove Contact
			cin >> name;
			deleteContact(&adb, name);
			break;
		case 4:	// 4.Find Contact
			cin >> name;
			findContact(&adb, name);
			break;
		case 5:	// 5.Edit Contact
			cin >> name;
			editContact(&adb, name);
			break;
		case 6:	// 6.Delete List
			deleteList(&adb);
			break;
		case 0:	// 0.Quit
			cout << "Quit Succeed ... " << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}