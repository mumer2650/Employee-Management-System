#include <iostream>
#include <windows.h>
#include <conio.h>
#include <array>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;
void gotoxy(int X, int Y);
void setColor(int textColor);
void admin();
void user();
void print_front();
void disply_front();
void print_front();
void print_header();
void sign_up_menu();
void Login_menu();
int admin_menu();
int user_menu();
void add_record(int n);
void update_record(string id);
void show_record();
void delete_record(string id);
void search_record(string id);
void PerformanceRemarks(string id);
void view_performance();
void exit_menu();
void print_box();
void exit_menu();
void creat_account();
void reset_pass(string id);
void view_payRoll();
void request_leave(string id);
bool check_user(string email, string pass);
bool check_admin(string email, string pass);
bool is_integer(string s);
bool is_alpha(string s);
void sayThanks();

void accessDefaulltAdmin();
void GetRecord();
void EnterRecord(string record);
string getField(string record, int field);
void GetAccountInfo();
void EnterAccountInfo(string record);
void GetPerformance();
void EnterPerformance(string record);

void displayAddRecord();
void displayLoginMenu();
void displayAdminMenu();
void displayEmpMenu();
void displayShowRecord();
void displayUpdateRecord();
void displayDelRecord();
void displaySearchRecord();
void displayresetpass();
void displayCreatAcc();
void displayPayRoll();
void displayViewRoll();
void displayExitMenu();
void displayperform();
void displayViewperform();
void CollectInfo();
void CollectRecord();
void CollectPerformance();
void clearAllRecords();
void clearAllInfo();
void clearAllReport();

string identity;
string user_name, password;
const int Max_Emp = 100;
string emp_name[Max_Emp], emp_id[Max_Emp], emp_address[Max_Emp];
string emp_cell[Max_Emp], emp_salery[Max_Emp];
string performance[Max_Emp];
string Remarks[Max_Emp];
string bonus[Max_Emp];
string deductions[Max_Emp];
string leaveDays[Max_Emp];
string netSalary[Max_Emp];
string review_id[Max_Emp];
string user_email[Max_Emp];
int user1 = 0;
int enter = 0;
int enter1 = 0;
int end1 = 0;
string AdminEmail[2];
string AdminPass[2];
string user_pass[20] = {"12345678", "09876543"};
string user_id[20], user_type[20];
string admin1 = "umer@admin.com";
string pass1 = "pakistan";
string admin2 = "saad@admin.com";
string pass2 = "12345678";
fstream file;
int main()
{
	system("cls");
	system("color 0B");
	disply_front();
	accessDefaulltAdmin();
	GetRecord();
	GetAccountInfo();
	GetPerformance();
login:
	Login_menu();
	if (identity == "admin")
	{
		admin();
		if (end1 == 0)
		{
			goto login;
		}
	}
	if (identity == "employee")
	{
		user();
		if (end1 == 0)
		{
			goto login;
		}
	}
	return 0;
}
void setColor(int textColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);
}
void accessDefaulltAdmin()
{
	file.open("defaultAdmin.txt", ios::in);

	if (!file.is_open())
	{
		cout << "Error: Unable to open file." << endl;
		return;
	}

	string line;
	int idx = 0;

	while (getline(file, line))
	{
		string email = "";
		string password = "";
		bool isEmailPart = true;

		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == ',')
			{
				isEmailPart = false;
			}
			else
			{
				if (isEmailPart)
				{
					email += line[i];
				}
				else
				{
					password += line[i];
				}
			}
		}
		AdminEmail[idx] = email;
		AdminPass[idx] = password;
		idx++;

		if (idx >= 2)
		{
			break;
		}
	}
	file.close();
}
string getField(string record, int field)
{
	int commaCount = 1;
	string item;
	for (int x = 0; x < record.length(); x++)
	{
		if (record[x] == ',')
		{
			commaCount = commaCount + 1;
		}
		else if (commaCount == field)
		{
			item = item + record[x];
		}
	}
	return item;
}
void GetRecord()
{
	file.open("employeeRecord.txt", ios::in);
	string record;
	int i = 0;
	while (getline(file, record))
	{
		emp_id[i] = getField(record, 2);
		emp_name[i] = getField(record, 1);
		emp_salery[i] = getField(record, 3);
		bonus[i] = getField(record, 4);
		deductions[i] = getField(record, 5);
		leaveDays[i] = getField(record, 6);
		emp_address[i] = getField(record, 7);
		emp_cell[i] = getField(record, 8);
		netSalary[i] = (getField(record, 9));
		i++;
		enter++;
	}
	file.close();
}
void EnterRecord(string record)
{
	file.open("employeeRecord.txt", ios::app);
	file << record << '\n';
	file.close();
}
void CollectRecord()
{
	string record = "";
	for (int i = 0; emp_id[i] != "\0"; i++)
	{
		if (emp_id[i] != "***")
		{
			record += emp_name[i] + ",";
			record += emp_id[i] + ",";
			record += emp_salery[i] + ",";
			record += bonus[i] + ",";
			record += deductions[i] + ",";
			record += leaveDays[i] + ",";
			record += emp_address[i] + ",";
			record += emp_cell[i] + ",";
			record += netSalary[i];
			EnterRecord(record);
			record = "";
		}
	}
}
void CollectInfo()
{
	string record = "";
	for (int i = 0; user_id[i] != "\0"; i++)
	{
		record += user_id[i] + ",";
		record += user_type[i] + ",";
		record += user_email[i] + ",";
		record += user_pass[i];
		EnterAccountInfo(record);
		record = "";
	}
}
void GetAccountInfo()
{
	file.open("AccountInfo.txt", ios::in);
	string record;
	int i = 0;
	while (getline(file, record))
	{
		user_id[i] = getField(record, 1);
		user_type[i] = getField(record, 2);
		user_email[i] = getField(record, 3);
		user_pass[i] = getField(record, 4);
		i++;
		user1++;
	}
	file.close();
}
void EnterAccountInfo(string record)
{
	file.open("AccountInfo.txt", ios::app);
	file << record << '\n';
	file.close();
}
void GetPerformance()
{

	file.open("report.txt", ios::in);
	string record;
	int i = 0;
	while (getline(file, record))
	{
		review_id[i] = getField(record, 1);
		performance[i] = getField(record, 2);
		Remarks[i] = getField(record, 3);
		i++;
		enter1++;
	}
	file.close();
}
void EnterPerformance(string record)
{
	file.open("report.txt", ios::app);
	file << record << '\n';
	file.close();
}
void CollectPerformance()
{
	string record = "";
	for (int i = 0; review_id[i] != "\0"; i++)
	{
		record += review_id[i] + ",";
		record += performance[i] + ",";
		record += Remarks[i];
		EnterPerformance(record);
		record = "";
	}
}
void clearAllRecords()
{
	file.open("employeeRecord.txt", ios::out);
	file.close();
}
void clearAllInfo()
{
	file.open("AccountInfo.txt", ios::out);
	file.close();
}
void clearAllReport()
{
	file.open("report.txt", ios::out);
	file.close();
}
void admin()
{
	bool endprogram = false;
	system("cls");
val3:
	int op = admin_menu();
	if (op == 1)
	{
		system("cls");
		int size;
		string stsize;
		gotoxy(2, 4);
		cout << "How many Employees data you want to enter (Maximum " << Max_Emp - enter << ") : ";
		cin >> stsize;
		if (!is_integer(stsize))
		{
			gotoxy(20, 20);
			setColor(12);
			cout << "Invalid Choice ";
			Sleep(1000);
			setColor(11);
			system("cls");
			goto val3;
		}
		size = stoi(stsize);
		if ((size <= 0) || (size > 20 - enter))
		{
			gotoxy(20, 20);
			setColor(12);
			cout << "Invalid Choice ";
			Sleep(1000);
			setColor(11);
			system("cls");
			goto val3;
		}
		else
		{
			add_record(size + enter);
			system("cls");
			Sleep(300);
			goto val3;
		}
	}
	else if (op == 2)
	{
		if (emp_id[0] == "")
		{
			system("cls");
			gotoxy(2, 8);
			setColor(12);
			cout << "You have not entered a record Yet : ";
			Sleep(2000);
			setColor(11);
			system("cls");
			goto val3;
		}
		else
		{
			system("cls");
			creat_account();
			system("cls");
			Sleep(300);
			goto val3;
		}
	}
	else if (op == 3)
	{
		system("cls");
		if (emp_id[0] == "")
		{
			gotoxy(2, 8);
			setColor(12);
			cout << "You have not entered a record Yet : ";
			Sleep(2000);
			setColor(11);
			system("cls");
			goto val3;
		}
		else
		{
			show_record();
			system("cls");
			Sleep(300);
			goto val3;
		}
	}
	else if (op == 4)
	{
		system("cls");
		gotoxy(2, 4);
		string id;
		cout << "Which Employee data you want to Update (Enter Employee ID): ";
		cin >> id;
		if (emp_id[0] == "")
		{
			gotoxy(2, 8);
			setColor(12);
			cout << "You have not entered a record Yet : ";
			Sleep(2000);
			setColor(11);
			system("cls");
			goto val3;
		}
		else
		{
			update_record(id);
			system("cls");
			Sleep(300);
			goto val3;
		}
	}
	else if (op == 5)
	{
		system("cls");
		gotoxy(2, 4);
		string id;
		cout << "Which Employee data you want to Delete (Enter Employee ID): ";
		cin >> id;
		if (emp_id[0] == "")
		{
			gotoxy(2, 8);
			setColor(12);
			cout << "You have not entered a record Yet : ";
			Sleep(2000);
			setColor(11);
			system("cls");
			goto val3;
		}
		else
		{
			delete_record(id);
			system("cls");
			Sleep(300);
			goto val3;
		}
	}
	else if (op == 6)
	{
		system("cls");
		gotoxy(2, 4);
		string id;
		cout << "Which Employee data you want to search (Enter Employee ID): ";
		cin >> id;
		if (emp_id[0] == "")
		{
			gotoxy(2, 8);
			setColor(12);
			cout << "You have not entered a record Yet : ";
			Sleep(2000);
			setColor(11);
			system("cls");
			goto val3;
		}
		else
		{
			search_record(id);
			system("cls");
			Sleep(300);
			goto val3;
		}
	}
	else if (op == 7)
	{
		system("cls");
		if (emp_id[0] == "")
		{
			gotoxy(2, 8);
			setColor(12);
			cout << "You have not entered a record Yet : ";
			Sleep(2000);
			setColor(11);
			system("cls");
			goto val3;
		}
		else
		{
			view_payRoll();
			system("cls");
			Sleep(300);
			goto val3;
		}
	}
	else if (op == 8)
	{
		bool found = VARIANT_FALSE;
		system("cls");
		gotoxy(2, 4);
		string id;
		cout << "WHICH ACCOUT PASSWORD YOU WANT TO RESET (Enter USER ID): ";
		cin >> id;
		for (int i = 0; user_id[i] != "\0"; i++)
		{
			if (id == user_id[i])
			{
				found = true;
			}
		}
		if (!found)
		{
			gotoxy(2, 8);
			setColor(12);
			cout << "User with id " << id << "Does not hold any Account !!!  ";
			Sleep(2000);
			setColor(11);
			system("cls");
			goto val3;
		}
		else if (user_id[0] == "")
		{
			gotoxy(2, 8);
			setColor(12);
			cout << "No Account Exists: ";
			Sleep(2000);
			setColor(11);
			system("cls");
			goto val3;
		}
		else
		{
			reset_pass(id);
			system("cls");
			Sleep(300);
			goto val3;
		}
	}
	else if (op == 11)
	{
		system("cls");
		goto gotologin;
	}
	else if (op == 12)
	{
		system("cls");
		endprogram = true;
		end1++;
		exit_menu();
	}
	else if (op == 9)
	{
		system("cls");
		gotoxy(2, 4);
		string id;
		cout << "Which Employee data you want to Update (Enter Employee ID): ";
		cin >> id;
		if (emp_id[0] == "")
		{
			gotoxy(2, 8);
			setColor(12);
			cout << "You have not entered a record Yet : ";
			Sleep(2000);
			setColor(11);
			system("cls");
			goto val3;
		}
		else
		{
			PerformanceRemarks(id);
			system("cls");
			Sleep(300);
			goto val3;
		}
	}
	else if (op == 10)
	{
		system("cls");
		if (emp_id[0] == "")
		{
			gotoxy(2, 8);
			setColor(12);
			cout << "You have not entered a record Yet : ";
			Sleep(2000);
			setColor(11);
			system("cls");
			goto val3;
		}
		else
		{
			view_performance();
			system("cls");
			Sleep(300);
			goto val3;
		}
	}
	else
	{
		cout << "    INVALID  CHOICE !!!!!";
		Sleep(1000);
		system("cls");
		goto val3;
	}
	if (!endprogram)
	{
		system("cls");
	gotologin:
		return;
	}
}
void user()
{
	system("cls");
val3:
	int op = user_menu();
	if (op == 1)
	{
		system("cls");
		if (emp_id[0] == "")
		{
			gotoxy(2, 8);
			setColor(12);
			cout << "You have not entered a record Yet : ";
			Sleep(2000);
			setColor(11);
			system("cls");
			goto val3;
		}
		else
		{
			show_record();
			system("cls");
			Sleep(300);
			goto val3;
		}
	}
	else if (op == 2)
	{
		system("cls");
		gotoxy(2, 4);
		string id;
		cout << "Which Employee data you want to search (Enter Employee ID): ";
		cin >> id;
		if (emp_id[0] == "")
		{
			gotoxy(2, 8);
			setColor(12);
			cout << "You have not entered a record Yet : ";
			Sleep(2000);
			setColor(11);
			system("cls");
			goto val3;
		}
		else
		{
			search_record(id);
			system("cls");
			Sleep(300);
			goto val3;
		}
	}
	else if (op == 3)
	{
		bool found = false;
		system("cls");
		gotoxy(2, 4);
		string id;
		cout << "WHICH ACCOUT PASSWORD YOU WANT TO RESET (Enter USER ID): ";
		cin >> id;
		for (int i = 0; user_id[i] != "\0"; i++)
		{
			if (id == user_id[i])
			{
				found = true;
			}
		}
		if (!found)
		{
			gotoxy(2, 8);
			setColor(12);
			cout << "User with id " << id << "Does not hold any Account !!!  ";
			Sleep(2000);
			setColor(11);
			system("cls");
			goto val3;
		}
		else if (emp_id[0] == "")
		{
			gotoxy(2, 8);
			setColor(12);
			cout << "You have not entered a record Yet : ";
			Sleep(2000);
			setColor(11);
			system("cls");
			goto val3;
		}
		else
		{
			reset_pass(id);
			system("cls");
			Sleep(300);
			goto val3;
		}
	}
	else if (op == 4)
	{
		system("cls");
		if (emp_id[0] == "")
		{
			gotoxy(2, 8);
			setColor(12);
			cout << "You have not entered a record Yet : ";
			Sleep(2000);
			setColor(11);
			system("cls");
			goto val3;
		}
		else
		{
			view_payRoll();
			system("cls");
			Sleep(300);
			goto val3;
		}
	}
	else if (op == 6)
	{
		system("cls");
		goto gotoend;
	}
	else if (op == 7)
	{
		system("cls");
		end1++;
		exit_menu();
	}
	else if (op == 5)
	{
		system("cls");
		if (emp_id[0] == "")
		{
			gotoxy(2, 8);
			setColor(12);
			cout << "You have not entered a record Yet : ";
			Sleep(2000);
			setColor(11);
			system("cls");
			goto val3;
		}
		else
		{
			view_performance();
			system("cls");
			Sleep(300);
			goto val3;
		}
	}
	else
	{
		setColor(12);
		cout << "    INVALID  CHOICE !!!!!";
		Sleep(1000);
		setColor(11);
		system("cls");
		goto val3;
	}
gotoend:
	return;
}
void gotoxy(int X, int Y)
{
	COORD coordinates;
	coordinates.X = X;
	coordinates.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void disply_front()
{

	system("cls");
	// system("color 03");
	print_front();
	Sleep(2000);
	cout << endl
		 << endl
		 << endl
		 << endl
		 << endl;
	setColor(14);
	cout << "                                                     PRESS   ANY   KEY TO CONTINUE ";
	setColor(11);
	getch();
	system("cls");
}
bool check_user(string email, string pass)
{
	for (int i = 0; user_email[i] != "\0"; i++)
	{
		if (user_email[i] == email)
		{
			if (user_pass[i] == pass)
			{
				if (user_type[i] == "Employee")
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
	return false;
}
bool check_admin(string email, string pass)
{
	if ((email == AdminEmail[0]) && (pass == AdminPass[0]))
	{
		return true;
	}
	else if ((email == AdminEmail[1]) && (pass == AdminPass[1]))
	{
		return true;
	}
	else if (user_email[0] != "")
	{
		for (int i = 0; user_email[i] != "\0"; i++)
		{
			if (user_email[i] == email)
			{
				if (user_pass[i] == pass)
				{
					if (user_type[i] == "Admin")
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
		return false;
	}
	else
	{
		return false;
	}
}
void Login_menu()
{
value:
	string U_name, pass;
	int count = 0;
	bool found = false;
	displayLoginMenu();
	// print_header();
	// cout << endl
	// 	 << endl
	// 	 << endl;
	// cout << "                            @@@@@@@@@@@@@@@@@@@@@@@@@     LOGIN   MENU   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	print_box();
	gotoxy(20, 20);
	cout << "Enter your Email :  ";
	cin >> U_name;
	gotoxy(20, 24);
	cout << "Password :";
	cin >> pass;
	if (pass.length() != 8)
	{
		gotoxy(20, 28);
		setColor(12);
		cout << "Your Password Must be eight characters  long !!!!!!" << endl;
		Sleep(1000);
		setColor(11);
		system("cls");
		goto value;
	}
	if (check_admin(U_name, pass))
	{
		identity = "admin";
	}
	else if (check_user(U_name, pass))
	{
		identity = "user";
	}

	else
	{
		gotoxy(20, 28);
		setColor(12);
		cout << "INVALID  USER  NAME  OR  PASSWORD !!!!!!" << endl;
		Sleep(2000);
		setColor(11);
		system("cls");
		goto value;
	}
	gotoxy(20, 28);
	setColor(10);
	cout << "Loading Please Wait .....";
	Sleep(3000);
	gotoxy(20, 30);
	cout << "LOGIN  SUCCESSFUL";
	setColor(14);
	gotoxy(28, 32);

	cout << "         PRESS   ANY   KEY TO CONTINUE ";
	setColor(11);
	getch();
}
void reset_pass(string id)
{
pass:
	int idx = 0;
	int p = 0;
	bool found = false;
	bool found1 = false;
	string check_pass;
	cout << endl;
	displayresetpass();
	// 	 << endl;
	// cout << "                             @@@@@@@@@@@@@@@@@@@@@@@@@     RESET  PASSWORD      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	for (int i = 0; user_id[i] != "\0"; i++)
	{
		if (user_id[i] == id)
		{
			idx = i;
			found = true;
			break;
		}
	}

	found = true;
	if ((identity == "employee") && (user_type[idx] == "Admin"))
	{
		p += 1;
		gotoxy(20, 30);
		setColor(12);
		cout << "ACCESS  IS  DENIED !!!" << endl;
		Sleep(2000);
		setColor(11);
		system("cls");
		goto hell;
	}
	Sleep(100);
	gotoxy(20, 22);
	cout << "Enter Previous Password : ";
	cin >> check_pass;
	if (check_pass != user_pass[idx])
	{
		p += 1;
		found1 = true;
		gotoxy(20, 30);
		setColor(12);
		cout << "PASSWORD DOES NOT MATCH !!!" << endl;
		Sleep(3000);
		setColor(11);
		system("cls");
		goto hell;
	}
	else
	{
		Sleep(1000);
		gotoxy(20, 24);
		setColor(10);
		cout << "AUTHENTICATION COMPLETED ";
		Sleep(500);
		setColor(11);
		gotoxy(20, 26);
		cout << "Enter NEW Password : ";
		cin >> user_pass[idx];
		if (user_pass[idx].length() != 8)
		{
			gotoxy(20, 30);
			setColor(12);
			cout << "Your Password Must be eight characters  long !!!!!!" << endl;
			Sleep(1000);
			setColor(11);
			system("cls");
			goto pass;
		}
		gotoxy(28, 28);
		setColor(10);
		cout << "Updating Password .....";
		Sleep(2000);
		gotoxy(28, 30);
		cout << "Password Updated Successfully ";
		setColor(11);
	}
	if (!found)
	{
		gotoxy(20, 24);
		setColor(12);
		cout << "User With id " << id << " Does not exist : ";
		Sleep(1000);
		setColor(11);
	}
	if (p == 0)
	{
		gotoxy(20, 32);
		setColor(14);
		cout << "Press Any Key To Exit : ";
		setColor(11);
		getch();
	}

hell:
	return;
}
void creat_account()
{
hero:
	string Info;
	cout << endl;
	displayCreatAcc();
	// print_header();
	// cout << endl
	// 	 << endl;
	// cout << "                              @@@@@@@@@@@@@@@@@@@@@@@@@     CREATE    ACCOUNT       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	string check1 = "@employee.com";
	string check2 = "@admin.com";
	gotoxy(20, 16);
	cout << "Enter USER ID: ";
	cin >> user_id[user1];
	bool found = false;
	for (int i = 0; emp_id[i] != "\0"; i++)
	{
		Info = "";
		if (emp_id[i] == user_id[user1])
		{
			found = true;
			break;
		}
	}
	if (!found)
	{
		gotoxy(20, 28);
		setColor(12);
		cout << "Employee  with ID " << user_id[user1] << " Does not exist  !!!!!!" << endl;
		Sleep(2000);
		setColor(7);
		system("cls");
		goto end;
	}
	Info += user_id[user1] + ",";
	gotoxy(20, 18);
	cout << "Enter USER  TYPE (Employee  OR  Admin): ";
	cin >> user_type[user1];
	if ((user_type[user1] == "Admin") || ((user_type[user1] == "Employee")))
	{
		;
	}
	else
	{
		gotoxy(20, 28);
		setColor(12);
		cout << "Invalid User Type " << endl;
		Sleep(1000);
		setColor(11);
		system("cls");
		goto hero;
	}
	Info += user_type[user1] + ",";
	Sleep(100);
	gotoxy(20, 20);
	cout << "Enter USER  EMAIL  : ";
	cin >> user_email[user1];
	if (user_type[user1] == "Admin")
	{
		if (user_email[user1].length() >= check2.length() &&
			user_email[user1].substr(user_email[user1].length() - check2.length()) == check2)
		{
		}
		else
		{
			gotoxy(20, 28);
			setColor(12);
			cout << "Email does not match its User Type" << endl;
			Sleep(2000);
			setColor(11);
			system("cls");
			goto hero;
		}
	}
	if (user_type[user1] == "Employee")
	{
		if (user_email[user1].length() >= check1.length() &&
			user_email[user1].substr(user_email[user1].length() - check1.length()) == check1)
		{
		}
		else
		{
			gotoxy(20, 28);
			setColor(12);
			cout << "Email does not match its User Type" << endl;
			Sleep(1000);
			setColor(11);
			system("cls");
			goto hero;
		}
	}
	Info += user_email[user1] + ",";
	Sleep(100);
	gotoxy(20, 22);
	cout << "Enter USER  PASSWORD : ";
	cin >> user_pass[user1];
	if (user_pass[user1].length() != 8)
	{
		gotoxy(20, 28);
		setColor(12);
		cout << "Your Password Must be eight characters  long !!!!!!" << endl;
		Sleep(1000);
		setColor(11);
		system("cls");
		goto hero;
	}
	Info += user_pass[user1];
	// EnterAccountInfo(Info);
	setColor(10);
	gotoxy(20, 26);
	cout << "Creating " << user_type[user1] << " Account .....  ";
	Sleep(1000);
	gotoxy(20, 28);
	cout << "Account Created Successfully  ";
	Sleep(100);
	setColor(11);
	user1++;
	gotoxy(20, 30);
	setColor(14);
	cout << "Press Any Key To Exit : ";
	setColor(11);
	getch();
end:
	return;
}
bool is_integer(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (!isdigit(s[i]))
			return false;
	}
	return true;
}
bool is_alpha(string s)
{
	if (s.size() == 0)
		return false;
	for (int i = 0; i < s.size(); i++)
	{
		if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')))
			return false;
	}
	return true;
}
int user_menu()
{
	// print_header();
	// cout << endl
	// 	 << endl
	// 	 << endl
	// 	 << endl;
	// cout << "                                   @@@@@@@@@@@@@@@@@@@@@@@@@     User  MENU    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << endl;
	displayEmpMenu();
	int y = 20;
	int op;
	gotoxy(20, y);
	setColor(14);
	cout << "PRESS 1  TO   SHOW   RECORD :  ";
	gotoxy(20, y + 2);
	cout << "PRESS 2  TO   SEARCH  RECORD  :  ";
	gotoxy(20, y + 4);
	cout << "PRESS 3  TO   RESET  PASSWORD :  ";
	gotoxy(20, y + 6);
	cout << "PRESS 4  TO   VIEW  PAYROLL  REPORT :  ";
	gotoxy(20, y + 8);
	cout << "PRESS 5  TO   VIEW  PERFORMANCE AND REMARKS :  ";
	gotoxy(20, y + 10);
	cout << "PRESS 6  TO   LOGOUT :  " << endl;
	gotoxy(20, y + 12);
	cout << "PRESS 7  TO   EXIT :  " << endl;
	setColor(10);
	gotoxy(23, y + 15);
	cout << "YOUR CHOICE : ";
	cin >> op;
	setColor(11);
	return op;
}
int admin_menu()
{
	// print_header();
	cout << endl;
	displayAdminMenu();
	// 	 << endl
	// 	 << endl
	// 	 << endl;
	// cout << "                                   @@@@@@@@@@@@@@@@@@@@@@@@@     ADMIN  MENU    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	int op;
	string input;
	gotoxy(20, 18);
	setColor(14);
	cout << "PRESS 1  TO   ENTER  RECORD :  ";
	gotoxy(20, 20);
	cout << "PRESS 2  TO   CREATE  ACCOUNT :  ";
	gotoxy(20, 22);
	cout << "PRESS 3  TO   SHOW   RECORD :  ";
	gotoxy(20, 24);
	cout << "PRESS 4  TO   UPDATE  RECORD :  ";
	gotoxy(20, 26);
	cout << "PRESS 5  TO   DELETE  RECORD :  ";
	gotoxy(20, 28);
	cout << "PRESS 6  TO   SEARCH  RECORD :  ";
	gotoxy(80, 18);
	cout << "PRESS 7  TO   VIEW  PAY ROLL REPORT :  ";
	gotoxy(80, 20);
	cout << "PRESS 8  TO   RESET  PASSWORD   :  ";
	gotoxy(80, 22);
	cout << "PRESS 9  TO   ADD  PERFORMANCE  AND  REMARKS :  " << endl;
	gotoxy(80, 24);
	cout << "PRESS 10 TO   VIEW  PERFORMANCE  AND  REMARKS:  " << endl;
	gotoxy(80, 26);
	cout << "PRESS 11 TO   LOGOUT :  " << endl;
	gotoxy(80, 28);
	cout << "PRESS 12 TO   EXIT :  " << endl;
	setColor(10);
	gotoxy(54, 31);
	cout << "YOUR CHOICE : ";
	cin >> input;
	setColor(11);
	op = stoi(input);
	if (is_integer(input))
	{
		return op;
	}
	return 100; // false case value
}
void view_payRoll()
{
	// print_header();
	bool found = false;
	cout << endl;
	displayViewRoll();
	// 	 << endl;
	// cout << "                            @@@@@@@@@@@@@@@@@@@@@@@@@     VIEW  PAY  ROLL     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	int x = 12;
	int y = 22;
	gotoxy(x, y);
	setColor(1);
	cout << "User ID";
	gotoxy(x + 20, y);
	cout << "Basic Salery";
	gotoxy(x + 40, y);
	cout << "Bonus Amount";
	gotoxy(x + 60, y);
	cout << "Deduction Amount";
	gotoxy(x + 80, y);
	cout << "No.of Days leave";
	gotoxy(x + 100, y);
	cout << "Net Salery ";
	setColor(11);
	for (int i = 0; emp_id[i] != "\0"; i++)
	{
		if (emp_id[i] != "***")
		{
			gotoxy(x + 2, y + 2 + i);
			cout << emp_id[i];
		}
	}
	for (int k = 0; emp_salery[k] != "\0"; k++)
	{
		if (emp_salery[k] != "***")
		{
			gotoxy(x + 22, y + 2 + k);
			cout << emp_salery[k];
		}
	}
	for (int l = 0; bonus[l] != "\0"; l++)
	{
		if (bonus[l] != "***")
		{
			gotoxy(x + 42, y + 2 + l);
			cout << bonus[l];
		}
	}
	for (int m = 0; deductions[m] != "\0"; m++)
	{
		if (deductions[m] != "***")
		{
			gotoxy(x + 62, y + 2 + m);
			cout << deductions[m];
		}
	}
	for (int n = 0; leaveDays[n] != "\0"; n++)
	{
		if (leaveDays[n] != "***")
		{
			gotoxy(x + 82, y + 2 + n);
			cout << leaveDays[n];
		}
	}
	for (int o = 0; emp_salery[o] != "\0"; o++)
	{
		if (emp_salery[o] != "***")
		{
			float NetSalary = stof(emp_salery[o]) + stof(bonus[o]) - stof(deductions[o]) - (stof(leaveDays[o]) * 200);
			netSalary[o] = to_string(NetSalary);
			gotoxy(x + 102, y + 2 + o);
			cout << netSalary[o];
		}
	}
	Sleep(1000);
	gotoxy(24, 30);
	setColor(14);
	cout << "Press Any Key To Exit : ";
	setColor(10);
	getch();
}
void add_record(int size)
{
	system("cls");
	for (int i = enter; i < size; i++)
	{
		displayAddRecord();
		string record = "";
		gotoxy(20, 14);
		cout << "Enter the Record of User " << i + 1 << "  " << endl;
		Sleep(100);
		gotoxy(20, 16);
		// cin.ignore();
		cout << "Enter User's Name : ";
		// getline(cin,emp_name[i]);
		cin >> emp_name[i];
		if (!is_alpha(emp_name[i]))
		{
			gotoxy(20, 28);
			setColor(12);
			cout << "Invalid Format!!!! (User name must not contain numbers )" << endl;
			Sleep(2000);
			setColor(11);
			system("cls");
			i--;
			continue;
		}
		// record += emp_name[i] + ",";
		Sleep(100);
		gotoxy(20, 18);
		cout << "Enter User's ID : ";
		cin >> emp_id[i];
		// for (int x=0;emp_id[x] != "\0";x++)
		// {
		// 	if ((emp_id[x] == emp_id[i]) && (x != i))
		// 	{
		// 		gotoxy(20, 28);
		// 		setColor(12);
		// 		cout << "Employee With ID ("<<emp_id[i]<<") Already Exists !!!!" << endl;
		// 		Sleep(2000);
		// 		setColor(11);
		// 		system("cls");
		// 		i--;
		// 		continue;
		// 	}
		// }
		if (emp_id[i].length() != 4)
		{
			gotoxy(20, 28);
			setColor(12);
			cout << "Invalid Format!!!! (User ID Must be 4 character long )" << endl;
			Sleep(2000);
			setColor(11);
			system("cls");
			i--;
			continue;
		}
		if (emp_id[i][0] != 'E')
		{
			gotoxy(20, 28);
			setColor(12);
			cout << "Invalid Format!!!! (Correct format: E _ _ _ )" << endl;
			Sleep(2000);
			setColor(11);
			system("cls");
			i--;
			continue;
		}
		string id = "";
		for (int j = 1; j < emp_id[i].length(); j++)
		{
			id += emp_id[i][j];
		}
		if (!is_integer(id))
		{
			gotoxy(20, 28);
			setColor(12);
			cout << "Invalid Format!!!! (Correct format: E _ _ _ )" << endl;
			Sleep(2000);
			setColor(11);
			system("cls");
			i--;
			continue;
		}
		// record += emp_id[i] + ",";
		Sleep(100);
		gotoxy(20, 20);
		cout << "Enter User's Basic Salary  : ";
		cin >> emp_salery[i];
		if (!is_integer(emp_salery[i]))
		{
			gotoxy(20, 28);
			setColor(12);
			cout << "Invalid Format!!! (Salery must not contain alphabets or symbols )" << endl;
			Sleep(2000);
			setColor(11);
			system("cls");
			i--;
			continue;
		}
		record += emp_salery[i] + ",";
		Sleep(100);
		gotoxy(20, 22);
		cout << "Enter User's Bonus Amount : ";
		cin >> bonus[i];
		if (!is_integer(bonus[i]))
		{
			gotoxy(20, 28);
			setColor(12);
			cout << "Invalid Format!!! (Bonus must not contain alphabets or symbols )" << endl;
			Sleep(2000);
			setColor(11);
			system("cls");
			i--;
			continue;
		}
		// record += bonus[i] + ",";
		Sleep(100);
		gotoxy(20, 24);
		cout << "Enter User's Deduction Amount  : ";
		cin >> deductions[i];
		if (!is_integer(deductions[i]))
		{
			gotoxy(20, 28);
			setColor(12);
			cout << "Invalid Format!!! (Deduction Amount must not contain alphabets or symbols )" << endl;
			Sleep(2000);
			setColor(11);
			system("cls");
			i--;
			continue;
		}
		// record += deductions[i] + ",";
		Sleep(100);
		gotoxy(20, 26);
		cout << "Enter User's Leave Day Taken : ";
		cin >> leaveDays[i];
		cin.ignore();
		if (!is_integer(leaveDays[i]))
		{
			gotoxy(20, 28);
			setColor(12);
			cout << "Invalid Format!!! (Leave Days must not contain alphabets or symbols )" << endl;
			Sleep(2000);
			setColor(11);
			system("cls");
			i--;
			continue;
		}
		// record += leaveDays[i] + ",";
		Sleep(100);
		gotoxy(20, 28);
		cout << "Enter User Address : ";
		getline(cin, emp_address[i]);
		record += emp_address[i] + ",";
		// cin>>emp_address[i];
		Sleep(100);
		gotoxy(20, 30);
		cout << "Enter User's Contact  : ";
		cin >> emp_cell[i];
		if (!is_integer(emp_cell[i]) || (emp_cell[i].length() != 11))
		{
			gotoxy(20, 30);
			setColor(12);
			cout << "Invalid Format!!!! (Contact number must be 11 digits long )" << endl;
			Sleep(2000);
			setColor(11);
			system("cls");
			i--;
			continue;
		}
		// record += emp_cell[i]+",";
		netSalary[i] = to_string(stof(emp_salery[i]) + stof(bonus[i]) - stof(deductions[i]) - (stof(leaveDays[i]) * 200));
		// EnterRecord(record);
		enter++;
		system("cls");
	}
	gotoxy(20, 32);
	setColor(14);
	cout << "Press Any Key To Exit : ";
	setColor(10);
	getch();
}
void view_performance()
{
	displayViewperform();
	// print_header();
	// cout << endl
	// 	 << endl;
	// cout << "                            @@@@@@@@@@@@@@@@@@@@@@@@@     VIEW  PERFORMANCE  AND  REMARKS      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	int x = 12;
	int y = 22;
	gotoxy(x, y);
	setColor(9);
	cout << "User ID";
	gotoxy(x + 20, y);
	cout << "Performance Score ";
	gotoxy(x + 50, y);
	cout << "Evaluation  Remarks";
	setColor(11);
	gotoxy(x + 60, y);
	for (int i = 0; review_id[i] != "\0"; i++)
	{
		gotoxy(x + 2, y + 2 + i);
		cout << review_id[i];
	}
	for (int j = 0; performance[j] != "\0"; j++)
	{
		gotoxy(x + 22, y + 2 + j);
		cout << performance[j];
	}
	for (int k = 0; Remarks[k] != "\0"; k++)
	{
		gotoxy(x + 52, y + 2 + k);
		cout << Remarks[k];
	}
	Sleep(1000);
	gotoxy(24, 30);
	setColor(14);
	cout << "Press Any Key To Exit : ";
	setColor(11);
	getch();
}
void PerformanceRemarks(string id)
{
	bool found = false;
	cout << endl;
	displayperform();
	int y = 22;
	// 	 << endl;
	// cout << "                             @@@@@@@@@@@@@@@@@@@@@@@@@     PERFORMANCE  AND  REMARKS   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	for (int i = 0; emp_id[i] != "\0"; i++)
	{
		string report = "";
		if (emp_id[i] == id)
		{
			found = true;
			gotoxy(20, y);
			cout << "You Want to Add PERFORMANCE  AND  REMARKS of User id : " << id;
			review_id[enter1] = emp_id[i];
			report += review_id[enter1] + ",";
			gotoxy(20, y + 3);
			cout << "Enter Performance Score of " << emp_name[i] << " (Out of 100) : ";
			cin >> performance[enter1];
			report += performance[enter1] + ",";
			cin.ignore();
			int perform = stoi(performance[enter1]);
			if ((perform > 100) || (perform < 0))
			{
				gotoxy(20, 28);
				setColor(12);
				cout << "Performance Must Be in range 0 to 100 !!!" << endl;
				Sleep(2000);
				setColor(11);
				system("cls");
				i--;
				continue;
			}
			Sleep(100);
			gotoxy(20, y + 5);
			cout << "Enter Evaluation Remarks for " << emp_name[i] << " : ";
			getline(cin, Remarks[enter1]);
			report += Remarks[enter1] + ",";
			// EnterPerformance(report);
			enter1++;
		}
	}
	if (!found)
	{
		gotoxy(20, 24);
		cout << "User With id " << id << " Does not exist : ";
	}
	gotoxy(20, 32);
	setColor(14);
	cout << "Press Any Key To Exit : ";
	setColor(11);
	getch();
}
void show_record()
{
	// print_header();
	cout << endl;
	displayShowRecord();
	// 	 << endl;
	// cout << "                            @@@@@@@@@@@@@@@@@@@@@@@@@     SHOW  RECORD      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	int x = 6;
	int y = 19;
	gotoxy(x, y);
	setColor(9);
	cout << "User ID";
	gotoxy(x + 20, y);
	cout << "User Name";
	gotoxy(x + 40, y);
	cout << "Basic Salery";
	gotoxy(x + 60, y);
	cout << "Bonus Amount";
	gotoxy(x + 80, y);
	cout << "Deduction Amount";
	gotoxy(x + 100, y);
	cout << "No.of Days leave";
	gotoxy(x + 120, y);
	cout << "   Contact";
	gotoxy(x + 140, y);
	cout << " Address";
	setColor(11);
	for (int i = 0; emp_id[i] != "\0"; i++)
	{
		if (emp_id[i] != "***")
		{
			gotoxy(x + 2, y + 2 + i);
			cout << emp_id[i];
		}
	}
	for (int j = 0; emp_name[j] != "\0"; j++)
	{
		if (emp_name[j] != "***")
		{
			gotoxy(x + 22, y + 2 + j);
			cout << emp_name[j];
		}
	}
	for (int k = 0; emp_salery[k] != "\0"; k++)
	{
		if (emp_salery[k] != "***")
		{
			gotoxy(x + 42, y + 2 + k);
			cout << emp_salery[k];
		}
	}
	for (int l = 0; bonus[l] != "\0"; l++)
	{
		if (bonus[l] != "***")
		{
			gotoxy(x + 62, y + 2 + l);
			cout << bonus[l];
		}
	}
	for (int m = 0; deductions[m] != "\0"; m++)
	{
		if (deductions[m] != "***")
		{
			gotoxy(x + 82, y + 2 + m);
			cout << deductions[m];
		}
	}
	for (int n = 0; leaveDays[n] != "\0"; n++)
	{
		if (leaveDays[n] != "***")
		{
			gotoxy(x + 102, y + 2 + n);
			cout << leaveDays[n];
		}
	}
	for (int o = 0; emp_cell[o] != "\0"; o++)
	{
		if (emp_cell[o] != "***")
		{
			gotoxy(x + 122, y + 2 + o);
			cout << emp_cell[o];
		}
	}
	for (int p = 0; emp_address[p] != "\0"; p++)
	{
		if (emp_address[p] != "***")
		{
			gotoxy(x + 141, y + 2 + p);
			cout << emp_address[p];
		}
	}
	Sleep(1000);
	gotoxy(24, 30);
	setColor(14);
	cout << "Press Any Key To Exit : ";
	setColor(11);
	getch();
}
void update_record(string id)
{
	bool found = false;

	// 	 << endl;
	// cout << "                             @@@@@@@@@@@@@@@@@@@@@@@@@     UPDATE  RECORD      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << endl;
	displayUpdateRecord();
	int y = 22;
	for (int i = 0; emp_id[i] != "\0"; i++)
	{
		cout << endl;
		if (emp_id[i] == id)
		{
			found = true;
			gotoxy(20, y);
			cout << "You Want to Update the record of User id : " << emp_id[i];
			Sleep(100);
			gotoxy(20, y + 3);
			cout << "Enter User's Basic Salary  : ";
			cin >> emp_salery[i];
			if (!is_integer(emp_salery[i]))
			{
				gotoxy(20, 28);
				setColor(12);
				cout << "Invalid Format!!! (Salery must not contain alphabets or symbols )" << endl;
				Sleep(2000);
				setColor(11);
				system("cls");
				i--;
				continue;
			}
			Sleep(100);
			gotoxy(20, y + 5);
			cout << "Enter User's Bonus Amount : ";
			cin >> bonus[i];
			if (!is_integer(bonus[i]))
			{
				gotoxy(20, 28);
				setColor(12);
				cout << "Invalid Format!!! (Bonus must not contain alphabets or symbols )" << endl;
				Sleep(2000);
				setColor(11);
				system("cls");
				i--;
				continue;
			}
			Sleep(100);
			gotoxy(20, y + 7);
			cout << "Enter User's Deduction Amount  : ";
			cin >> deductions[i];
			if (!is_integer(deductions[i]))
			{
				gotoxy(20, 28);
				setColor(12);
				cout << "Invalid Format!!! (Deduction Amount must not contain alphabets or symbols )" << endl;
				Sleep(2000);
				setColor(11);
				system("cls");
				i--;
				continue;
			}
			Sleep(100);
			gotoxy(20, y + 9);
			cout << "Enter User's Leave Day Taken : ";
			cin >> leaveDays[i];
			if (!is_integer(leaveDays[i]))
			{
				gotoxy(20, 28);
				setColor(12);
				cout << "Invalid Format!!! (Leave Days must not contain alphabets or symbols )" << endl;
				Sleep(2000);
				setColor(11);
				system("cls");
				i--;
				continue;
			}
			Sleep(100);
			gotoxy(20, y + 11);
			cout << "Enter User's Contact  : ";
			cin >> emp_cell[i];
			cin.ignore();
			if (!is_integer(emp_cell[i]) || (emp_cell[i].length() != 11))
			{
				gotoxy(20, 29);
				setColor(12);
				cout << "Invalid Format!!!! (Contact number must be 11 digits long )" << endl;
				Sleep(2000);
				setColor(11);
				system("cls");
				i--;
				continue;
			}
			gotoxy(20, y + 13);
			cout << "Enter User Address : ";
			getline(cin, emp_address[i]);
			gotoxy(30, 29);
			setColor(10);
			cout << "Updating Record .....";
			Sleep(1000);
			gotoxy(30, 31);
			cout << "Record Updated Successfully ";
			setColor(11);
		}
	}
	if (!found)
	{
		gotoxy(20, 24);
		cout << "User With id " << id << " Does not exist : ";
		Sleep(2000);
		goto end;
	}
	gotoxy(24, 40);
	setColor(14);
	cout << "Press Any Key To Exit : ";
	setColor(11);
	getch();
end:
	return;
}
void delete_record(string id)
{
	// print_header();
	bool found = false;
	cout << endl;
	displayDelRecord();
	// 	 << endl;
	// cout << "                             @@@@@@@@@@@@@@@@@@@@@@@@@     DELETE  RECORD      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	for (int i = 0; emp_id[i] != "\0"; i++)
	{
		if (emp_id[i] == id)
		{
			emp_name[i] = "***";
			emp_id[i] = "***";
			emp_address[i] = "***";
			emp_cell[i] = "***";
			emp_salery[i] = "***";
			bonus[i] = "***";
			leaveDays[i] = "***";
			deductions[i] = "***";
			setColor(10);
			gotoxy(24, 20);
			cout << "Deleting Record .....";
			Sleep(1000);
			gotoxy(20, 24);
			cout << "Record Deleted Successfully ";
			Sleep(1000);
			setColor(11);
			found = true;
		}
	}
	if (!found)
	{
		gotoxy(20, 24);
		cout << "Employee With id " << id << " Does not exist : ";
	}
	gotoxy(20, 28);
	setColor(14);
	cout << "Press Any Key To Exit : ";
	setColor(11);
	getch();
}
void search_record(string id)
{
	// print_header();
	bool found = false;
	cout << endl;
	displaySearchRecord();
	// 	 << endl;
	// cout << "                                   @@@@@@@@@@@@@@@@@@@@@@@@@     SEARCH  RECORD      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	int y = 22;
	for (int i = 0; emp_id[i] != "\0"; i++)
	{
		if (emp_id[i] == id)
		{
			gotoxy(20, y);
			cout << "You Want to search the record of employee id : " << emp_id[i];
			gotoxy(20, y + 3);
			cout << "User Name : " << emp_name[i];
			gotoxy(20, y + 5);
			cout << "User ID : " << emp_id[i];
			gotoxy(20, y + 7);
			cout << "Address : " << emp_address[i];
			gotoxy(20, y + 9);
			cout << "Contact : " << emp_cell[i];
			gotoxy(20, y + 11);
			cout << "Basic Salary : " << emp_salery[i];
			gotoxy(20, y + 13);
			cout << "Bonus Amount : " << bonus[i];
			gotoxy(20, y + 15);
			cout << "Deduction Amount : " << deductions[i];
			gotoxy(20, y + 17);
			cout << "No. of leave days: " << leaveDays[i];
			Sleep(1000);
			found = true;
		}
	}
	if (found == false)
	{
		gotoxy(20, 24);
		cout << "Employee With id " << id << " Does not exist : ";
		Sleep(2000);
		goto end;
	}
	gotoxy(20, 40);
	setColor(14);
	cout << "Press Any Key To Exit : ";
	setColor(11);
	getch();
end:
	return;
}
void exit_menu()

{
	// print_header();
	// cout << endl
	// 	 << endl;
	// cout << "                                   @@@@@@@@@@@@@@@@@@@@@@@@@     EXIT  MENU     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	clearAllRecords();
	clearAllInfo();
	clearAllReport();

	CollectPerformance();
	CollectRecord();
	CollectInfo();

	cout << endl;
	displayExitMenu();
	sayThanks();
	gotoxy(2, 35);
}
void print_front()
{
	setColor(11);
	cout << endl
		 << endl
		 << endl
		 << endl
		 << endl;
	Sleep(70);
	cout << "			 _____                                                                                            _____" << endl;
	Sleep(70);
	cout << "			( ___ )                                                                                          ( ___ )" << endl;
	Sleep(70);
	cout << "			 |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   |" << endl;
	Sleep(70);
	cout << "			 |   |          _______  _______  _______  _        _______           _______  _______            |   |" << endl;
	Sleep(70);
	cout << "			 |   |         (  ____ \\(       )(  ____ )( \\      (  ___  )|\\     /|(  ____ \\(  ____ \\           |   |" << endl;
	Sleep(70);
	cout << "			 |   |         | (    \\/| () () || (    )|| (      | (   ) |( \\   / )| (    \\/| (    \\/           |   |" << endl;
	Sleep(70);
	cout << "			 |   |         | (__    | || || || (____)|| |      | |   | | \\ (_) / | (__    | (__               |   |" << endl;
	Sleep(70);
	cout << "			 |   |         |  __)   | |(_)| ||  _____)| |      | |   | |  \\   /  |  __)   |  __)              |   |" << endl;
	Sleep(70);
	cout << "			 |   |         | (      | |   | || (      | |      | |   | |   ) (   | (      | (                 |   |" << endl;
	Sleep(70);
	cout << "			 |   |         | (____/\\| )   ( || )      | (____/\\| (___) |   | |   | (____/\\| (____/\\           |   |" << endl;
	Sleep(70);
	cout << "			 |   |         (_______/|/     \\||/       (_______/(_______)   \\_/   (_______/(_______/           |   |" << endl;
	Sleep(70);
	cout << "			 |   |                                                                                            |   |" << endl;
	Sleep(70);
	cout << "			 |   |  _______  _______  _        _______  _______  _______  _______  _______  _       _________ |   |" << endl;
	Sleep(70);
	cout << "			 |   | (       )(  ___  )( (    /|(  ___  )(  ____ \\(  ____ \\(       )(  ____ \\( (    /|\\__   __/ |   |" << endl;
	Sleep(70);
	cout << "			 |   | | () () || (   ) ||  \\  ( || (   ) || (    \\/| (    \\/| () () || (    \\/|  \\  ( |   ) (    |   |" << endl;
	Sleep(70);
	cout << "			 |   | | || || || (___) ||   \\ | || (___) || |      | (__    | || || || (__    |   \\ | |   | |    |   |" << endl;
	Sleep(70);
	cout << "			 |   | | |(_)| ||  ___  || (\\ \\) ||  ___  || | ____ |  __)   | |(_)| ||  __)   | (\\ \\) |   | |    |   |" << endl;
	Sleep(70);
	cout << "			 |   | | |   | || (   ) || | \\   || (   ) || | \\_  )| (      | |   | || (      | | \\   |   | |    |   |" << endl;
	Sleep(70);
	cout << "			 |   | | )   ( || )   ( || )  \\  || )   ( || (___) || (____/\\| )   ( || (____/\\| )  \\  |   | |    |   |" << endl;
	Sleep(70);
	cout << "			 |   | |/     \\||/     \\||/    )_)|/     \\|(_______)(_______/|/     \\|(_______/|/    )_)   )_(    |   |" << endl;
	Sleep(70);
	cout << "			 |   |                                                                                            |   |" << endl;
	Sleep(70);
	cout << "			 |   |                      _______           _______ _________ _______  _______                  |   |" << endl;
	Sleep(70);
	cout << "			 |   |                     (  ____ \\|\\     /|(  ____ \\__   __/(  ____ \\ (       )                 |   |" << endl;
	Sleep(70);
	cout << "			 |   |                     | (    \\/( \\   / )| (    \\/   ) (   | (    \\/| () () |                 |   |" << endl;
	Sleep(70);
	cout << "			 |   |                     | (_____  \\ (_) / | (_____    | |   | (__    | || || |                 |   |" << endl;
	Sleep(70);
	cout << "			 |   |                     (_____  )  \\   /  (_____  )   | |   |  __)   | |(_)| |                 |   |" << endl;
	Sleep(70);
	cout << "			 |   |                           ) |   ) (         ) |   | |   | (      | |   | |                 |   |" << endl;
	Sleep(70);
	cout << "			 |   |                     /\\____) |   | |   /\\____) |   | |   | (____/\\| )   ( |                 |   |" << endl;
	Sleep(70);
	cout << "			 |   |                     \\_______)   \\_/   \\_______)   )_(   (_______/|/     \\|                 |   |" << endl;
	Sleep(70);
	cout << "			 |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___|" << endl;
	Sleep(70);
	cout << "			(_____)                                                                                          (_____)" << endl;
	setColor(11);
}
void print_box()
{
	setColor(9);
	gotoxy(15, 18);
	cout << " ------------------------------------------------------------------------------" << endl;
	gotoxy(15, 19);
	cout << " |                                                                            |" << endl;
	gotoxy(15, 20);
	cout << " |                                                                            |" << endl;
	gotoxy(15, 21);
	cout << " |                                                                            |" << endl;
	gotoxy(15, 22);
	cout << " |                                                                            |" << endl;
	gotoxy(15, 23);
	cout << " |                                                                            |" << endl;
	gotoxy(15, 24);
	cout << " |                                                                            |" << endl;
	gotoxy(15, 25);
	cout << " |                                                                            |" << endl;
	gotoxy(15, 26);
	cout << " ------------------------------------------------------------------------------" << endl;
	setColor(11);
}
void displayAddRecord()
{
	setColor(11);
	// cout <<endl;
	cout << "			 _____                                                                                     _____ " << endl;
	cout << "			( ___ )-----------------------------------------------------------------------------------( ___ )" << endl;
	cout << "			 |   |                                                                                     |   | " << endl;
	cout << "			 |   |  _______  ______   ______     _______  _______  _______  _______  _______  ______   |   | " << endl;
	cout << "			 |   | (  ___  )(  __  \\ (  __  \\   (  ____ )(  ____ \\(  ____ \\(  ___  )(  ____ )(  __  \\  |   | " << endl;
	cout << "			 |   | | (   ) || (  \\  )| (  \\  )  | (    )|| (    \\/| (    \\/| (   ) || (    )|| (  \\  ) |   | " << endl;
	cout << "			 |   | | (___) || |   ) || |   ) |  | (____)|| (__    | |      | |   | || (____)|| |   ) | |   | " << endl;
	cout << "			 |   | |  ___  || |   | || |   | |  |     __)|  __)   | |      | |   | ||     __)| |   | | |   | " << endl;
	cout << "			 |   | | (   ) || |   ) || |   ) |  | (\\ (   | (      | |      | |   | || (\\ (   | |   ) | |   | " << endl;
	cout << "			 |   | | )   ( || (__/  )| (__/  )  | ) \\ \\__| (____/\\| (____/\\| (___) || ) \\ \\__| (__/  ) |   | " << endl;
	cout << "			 |   | |/     \\|(______/ (______/   |/   \\__/(_______/(_______/(_______)|/   \\__/(______/  |   | " << endl;
	cout << "			 |___|                                                                                     |___| " << endl;
	cout << "			(_____)-----------------------------------------------------------------------------------(_____)" << endl;
	setColor(11);
}
void displayLoginMenu()
{
	setColor(11);
	cout << endl;
	cout << "			 _____                                                                                     _____ " << endl;
	cout << "			( ___ )-----------------------------------------------------------------------------------( ___ )" << endl;
	cout << "			 |   |                                                                                     |   | " << endl;
	cout << "			 |   |  _        _______  _______ _________ _          _______  _______  _                 |   | " << endl;
	cout << "			 |   | ( \\      (  ___  )(  ____ \\\\__   __/( (    /|  (       )(  ____ \\( (    /||\\     /| |   | " << endl;
	cout << "			 |   | | (      | (   ) || (    \\/   ) (   |  \\  ( |  | () () || (    \\/|  \\  ( || )   ( | |   | " << endl;
	cout << "			 |   | | |      | |   | || |         | |   |   \\ | |  | || || || (__    |   \\ | || |   | | |   | " << endl;
	cout << "			 |   | | |      | |   | || | ____    | |   | (\\ \\) |  | |(_)| ||  __)   | (\\ \\) || |   | | |   | " << endl;
	cout << "			 |   | | |      | |   | || | \\_  )   | |   | | \\   |  | |   | || (      | | \\   || |   | | |   | " << endl;
	cout << "			 |   | | (____/\\| (___) || (___) |___) (___| )  \\  |  | )   ( || (____/\\| )  \\  || (___) | |   | " << endl;
	cout << "			 |   | (_______/(_______)(_______)\\_______/|/    )_)  |/     \\|(_______/|/    )_)(_______) |   | " << endl;
	cout << "			 |___|                                                                                     |___| " << endl;
	cout << "			(_____)-----------------------------------------------------------------------------------(_____)" << endl;
	setColor(11);
}
void displayAdminMenu()
{
	setColor(11);
	cout << "			 _____                                                                                     _____ " << endl;
	cout << "			( ___ )-----------------------------------------------------------------------------------( ___ )" << endl;
	cout << "			 |   |                                                                                     |   | " << endl;
	cout << "			 |   |  _______  ______   _______ _________ _          _______  _______  _                 |   | " << endl;
	cout << "			 |   | (  ___  )(  __  \\ (       )\\__   __/( (    /|  (       )(  ____ \\( (    /||\\     /| |   | " << endl;
	cout << "			 |   | | (   ) || (  \\  )| () () |   ) (   |  \\  ( |  | () () || (    \\/|  \\  ( || )   ( | |   | " << endl;
	cout << "			 |   | | (___) || |   ) || || || |   | |   |   \\ | |  | || || || (__    |   \\ | || |   | | |   | " << endl;
	cout << "			 |   | |  ___  || |   | || |(_)| |   | |   | (\\ \\) |  | |(_)| ||  __)   | (\\ \\) || |   | | |   | " << endl;
	cout << "			 |   | | (   ) || |   ) || |   | |   | |   | | \\   |  | |   | || (      | | \\   || |   | | |   | " << endl;
	cout << "			 |   | | )   ( || (__/  )| )   ( |___) (___| )  \\  |  | )   ( || (____/\\| )  \\  || (___) | |   | " << endl;
	cout << "			 |   | |/     \\|(______/ |/     \\|\\_______/|/    )_)  |/     \\|(_______/|/    )_)(_______) |   | " << endl;
	cout << "			 |___|                                                                                     |___| " << endl;
	cout << "			(_____)-----------------------------------------------------------------------------------(_____)" << endl;
	setColor(11);
}
void displayEmpMenu()
{
	setColor(11);
	cout << "			 _____                                                                                                                _____ " << endl;
	cout << "			( ___ )--------------------------------------------------------------------------------------------------------------( ___ )" << endl;
	cout << "			 |   |                                                                                                                |   | " << endl;
	cout << "			 |   |  _______  _______  _______  _        _______           _______  _______    _______  _______  _                 |   | " << endl;
	cout << "			 |   | (  ____ \\(       )(  ____ )( \\      (  ___  )|\\     /|(  ____ \\(  ____ \\  (       )(  ____ \\( (    /||\\     /| |   | " << endl;
	cout << "			 |   | | (    \\/| () () || (    )|| (      | (   ) |( \\   / )| (    \\/| (    \\/  | () () || (    \\/|  \\  ( || )   ( | |   | " << endl;
	cout << "			 |   | | (__    | || || || (____)|| |      | |   | | \\ (_) / | (__    | (__      | || || || (__    |   \\ | || |   | | |   | " << endl;
	cout << "			 |   | |  __)   | |(_)| ||  _____)| |      | |   | |  \\   /  |  __)   |  __)     | |(_)| ||  __)   | (\\ \\) || |   | | |   | " << endl;
	cout << "			 |   | | (      | |   | || (      | |      | |   | |   ) (   | (      | (        | |   | || (      | | \\   || |   | | |   | " << endl;
	cout << "			 |   | | (____/\\| )   ( || )      | (____/\\| (___) |   | |   | (____/\\| (____/\\  | )   ( || (____/\\| )  \\  || (___) | |   | " << endl;
	cout << "			 |   | (_______/|/     \\||/       (_______/(_______)   \\_/   (_______/(_______/  |/     \\|(_______/|/    )_)(_______) |   | " << endl;
	cout << "			 |___|                                                                                                                |___| " << endl;
	cout << "			(_____)--------------------------------------------------------------------------------------------------------------(_____)" << endl;
	setColor(11);
}
void displayShowRecord()
{
	setColor(11);
	cout << "			 _____                                                                                              _____ " << endl;
	cout << "			( ___ )--------------------------------------------------------------------------------------------( ___ )" << endl;
	cout << "			 |   |                                                                                              |   | " << endl;
	cout << "			 |   |  _______           _______             _______  _______  _______  _______  _______  ______   |   | " << endl;
	cout << "			 |   | (  ____ \\|\\     /|(  ___  )|\\     /|  (  ____ )(  ____ \\(  ____ \\(  ___  )(  ____ )(  __  \\  |   | " << endl;
	cout << "			 |   | | (    \\/| )   ( || (   ) || )   ( |  | (    )|| (    \\/| (    \\/| (   ) || (    )|| (  \\  ) |   | " << endl;
	cout << "			 |   | | (_____ | (___) || |   | || | _ | |  | (____)|| (__    | |      | |   | || (____)|| |   ) | |   | " << endl;
	cout << "			 |   | (_____  )|  ___  || |   | || |( )| |  |     __)|  __)   | |      | |   | ||     __)| |   | | |   | " << endl;
	cout << "			 |   |       ) || (   ) || |   | || || || |  | (\\ (   | (      | |      | |   | || (\\ (   | |   ) | |   | " << endl;
	cout << "			 |   | /\\____) || )   ( || (___) || () () |  | ) \\ \\__| (____/\\| (____/\\| (___) || ) \\ \\__| (__/  ) |   | " << endl;
	cout << "			 |   | \\_______)|/     \\|(_______)(_______)  |/   \\__/(_______/(_______/(_______)|/   \\__/(______/  |   | " << endl;
	cout << "			 |___|                                                                                              |___| " << endl;
	cout << "			(_____)--------------------------------------------------------------------------------------------(_____)" << endl;
	setColor(11);
}
void displayUpdateRecord()
{
	setColor(11);
	cout << "			 _____                                                                                                                _____ " << endl;
	cout << "			( ___ )--------------------------------------------------------------------------------------------------------------( ___ )" << endl;
	cout << "			 |   |                                                                                                                |   | " << endl;
	cout << "			 |   |           _______  ______   _______ _________ _______    _______  _______  _______  _______  _______  ______   |   | " << endl;
	cout << "			 |   | |\\     /|(  ____ )(  __  \\ (  ___  )\\__   __/(  ____ \\  (  ____ )(  ____ \\(  ____ \\(  ___  )(  ____ )(  __  \\  |   | " << endl;
	cout << "			 |   | | )   ( || (    )|| (  \\  )| (   ) |   ) (   | (    \\/  | (    )|| (    \\/| (    \\/| (   ) || (    )|| (  \\  ) |   | " << endl;
	cout << "			 |   | | |   | || (____)|| |   ) || (___) |   | |   | (__      | (____)|| (__    | |      | |   | || (____)|| |   ) | |   | " << endl;
	cout << "			 |   | | |   | ||  _____)| |   | ||  ___  |   | |   |  __)     |     __)|  __)   | |      | |   | ||     __)| |   | | |   | " << endl;
	cout << "			 |   | | |   | || (      | |   ) || (   ) |   | |   | (        | (\\ (   | (      | |      | |   | || (\\ (   | |   ) | |   | " << endl;
	cout << "			 |   | | (___) || )      | (__/  )| )   ( |   | |   | (____/\\  | ) \\ \\__| (____/\\| (____/\\| (___) || ) \\ \\__| (__/  ) |   | " << endl;
	cout << "			 |   | (_______)|/       (______/ |/     \\|   )_(   (_______/  |/   \\__/(_______/(_______/(_______)|/   \\__/(______/  |   | " << endl;
	cout << "			 |___|                                                                                                                |___| " << endl;
	cout << "			(_____)--------------------------------------------------------------------------------------------------------------(_____)" << endl;
	setColor(11);
}
void displayDelRecord()
{
	setColor(11);
	cout << "			 _____                                                                                                                _____ " << endl;
	cout << "			( ___ )--------------------------------------------------------------------------------------------------------------( ___ )" << endl;
	cout << "			 |   |                                                                                                                |   | " << endl;
	cout << "			 |   |  ______   _______  _        _______ _________ _______    _______  _______  _______  _______  _______  ______   |   | " << endl;
	cout << "			 |   | (  __  \\ (  ____ \\( \\      (  ____ \\__   __/(  ____ \\  (  ____ )(  ____ \\(  ____ \\(  ___  )(  ____ )(  __  \\  |   | " << endl;
	cout << "			 |   | | (  \\  )| (    \\/| (      | (    \\/   ) (   | (    \\/  | (    )|| (    \\/| (    \\/| (   ) || (    )|| (  \\  ) |   | " << endl;
	cout << "			 |   | | |   ) || (__    | |      | (__       | |   | (__      | (____)|| (__    | |      | |   | || (____)|| |   ) | |   | " << endl;
	cout << "			 |   | | |   | ||  __)   | |      |  __)      | |   |  __)     |     __)|  __)   | |      | |   | ||     __)| |   | | |   | " << endl;
	cout << "			 |   | | |   ) || (      | |      | (         | |   | (        | (\\ (   | (      | |      | |   | || (\\ (   | |   ) | |   | " << endl;
	cout << "			 |   | | (__/  )| (____/\\| (____/\\| (____/\\   | |   | (____/\\  | ) \\ \\__| (____/\\| (____/\\| (___) || ) \\ \\__| (__/  ) |   | " << endl;
	cout << "			 |   | (______/ (_______/(_______/(_______/   )_(   (_______/  |/   \\__/(_______/(_______/(_______)|/   \\__/(______/  |   | " << endl;
	cout << "			 |___|                                                                                                                |___| " << endl;
	cout << "			(_____)--------------------------------------------------------------------------------------------------------------(_____)" << endl;
	setColor(11);
}
void displaySearchRecord()
{
	setColor(11);
	cout << "			 _____                                                                                                                _____ " << endl;
	cout << "			( ___ )--------------------------------------------------------------------------------------------------------------( ___ )" << endl;
	cout << "			 |   |                                                                                                                |   | " << endl;
	cout << "			 |   |  _______  _______  _______  _______  _______             _______  _______  _______  _______  _______  ______   |   | " << endl;
	cout << "			 |   | (  ____ \\(  ____ \\(  ___  )(  ____ )(  ____ \\|\\     /|  (  ____ )(  ____ \\(  ____ \\(  ___  )(  ____ )(  __  \\  |   | " << endl;
	cout << "			 |   | | (    \\/| (    \\/| (   ) || (    )|| (    \\/| )   ( |  | (    )|| (    \\/| (    \\/| (   ) || (    )|| (  \\  ) |   | " << endl;
	cout << "			 |   | | (_____ | (__    | (___) || (____)|| |      | (___) |  | (____)|| (__    | |      | |   | || (____)|| |   ) | |   | " << endl;
	cout << "			 |   | (_____  )|  __)   |  ___  ||     __)| |      |  ___  |  |     __)|  __)   | |      | |   | ||     __)| |   | | |   | " << endl;
	cout << "			 |   |       ) || (      | (   ) || (\\ (   | |      | (   ) |  | (\\ (   | (      | |      | |   | || (\\ (   | |   ) | |   | " << endl;
	cout << "			 |   | /\\____) || (____/\\| )   ( || ) \\ \\__| (____/\\| )   ( |  | ) \\ \\__| (____/\\| (____/\\| (___) || ) \\ \\__| (__/  ) |   | " << endl;
	cout << "			 |   | \\_______)(_______/|/     \\||/   \\__/(_______/|/     \\|  |/   \\__/(_______/(_______/(_______)|/   \\__/(______/  |   | " << endl;
	cout << "			 |___|                                                                                                                |___| " << endl;
	cout << "			(_____)--------------------------------------------------------------------------------------------------------------(_____)" << endl;
	setColor(11);
}
void displayresetpass()
{
	setColor(11);
	cout << "			 _____                                                                                                                         _____ " << endl;
	cout << "			( ___ )-----------------------------------------------------------------------------------------------------------------------( ___ )" << endl;
	cout << "			 |   |                                                                                                                         |   | " << endl;
	cout << "			 |   |  _______  _______  _______  _______ _________   _______  _______  _______  _______           _______  _______  ______   |   | " << endl;
	cout << "			 |   | (  ____ )(  ____ \\(  ____ \\(  ____ \\__   __/   (  ____ )(  ___  )(  ____ \\(  ____ \\|\\     /|(  ___  )(  ____ )(  __  \\  |   | " << endl;
	cout << "			 |   | | (    )|| (    \\/| (    \\/| (    \\/   ) (     | (    )|| (   ) || (    \\/| (    \\/| )   ( || (   ) || (    )|| (  \\  ) |   | " << endl;
	cout << "			 |   | | (____)|| (__    | (_____ | (__       | |     | (____)|| (___) || (_____ | (_____ | | _ | || |   | || (____)|| |   ) | |   | " << endl;
	cout << "			 |   | |     __)|  __)   (_____  )|  __)      | |     |  _____)|  ___  |(_____  )(_____  )| |( )| || |   | ||     __)| |   | | |   | " << endl;
	cout << "			 |   | | (\\ (   | (            ) || (         | |     | (      | (   ) |      ) |      ) || || || || |   | || (\\ (   | |   ) | |   | " << endl;
	cout << "			 |   | | ) \\ \\__| (____/\\/\\____) || (____/\\   | |     | )      | )   ( |/\\____) |/\\____) || () () || (___) || ) \\ \\__| (__/  ) |   | " << endl;
	cout << "			 |   | |/   \\__/(_______/\\_______)(_______/   )_(     |/       |/     \\|\\_______)\\_______)(_______)(_______)|/   \\__/(______/  |   | " << endl;
	cout << "			 |___|                                                                                                                         |___| " << endl;
	cout << "			(_____)-----------------------------------------------------------------------------------------------------------------------(_____)" << endl;
	setColor(11);
}
void displayCreatAcc()
{
	setColor(11);
	cout << "			 _____                                                                                                                         _____ " << endl;
	cout << "			( ___ )-----------------------------------------------------------------------------------------------------------------------( ___ )" << endl;
	cout << "			 |   |                                                                                                                         |   | " << endl;
	cout << "			 |   |  _______  _______  _______  _______ _________ _______    _______  _______  _______  _______           _       _________ |   | " << endl;
	cout << "			 |   | (  ____ \\(  ____ )(  ____ \\(  ___  )\\__   __/(  ____ \\  (  ___  )(  ____ \\(  ____ \\(  ___  )|\\     /|( (    /|\\__   __/ |   | " << endl;
	cout << "			 |   | | (    \\/| (    )|| (    \\/| (   ) |   ) (   | (    \\/  | (   ) || (    \\/| (    \\/| (   ) || )   ( ||  \\  ( |   ) (    |   | " << endl;
	cout << "			 |   | | |      | (____)|| (__    | (___) |   | |   | (__      | (___) || |      | |      | |   | || |   | ||   \\ | |   | |    |   | " << endl;
	cout << "			 |   | | |      |     __)|  __)   |  ___  |   | |   |  __)     |  ___  || |      | |      | |   | || |   | || (\\ \\) |   | |    |   | " << endl;
	cout << "			 |   | | |      | (\\ (   | (      | (   ) |   | |   | (        | (   ) || |      | |      | |   | || |   | || | \\   |   | |    |   | " << endl;
	cout << "			 |   | | (____/\\| ) \\ \\__| (____/\\| )   ( |   | |   | (____/\\  | )   ( || (____/\\| (____/\\| (___) || (___) || )  \\  |   | |    |   | " << endl;
	cout << "			 |   | (_______/|/   \\__/(_______/|/     \\|   )_(   (_______/  |/     \\|(_______/(_______/(_______)(_______)|/    )_)   )_(    |   | " << endl;
	cout << "			 |___|                                                                                                                         |___| " << endl;
	cout << "			(_____)-----------------------------------------------------------------------------------------------------------------------(_____)" << endl;
	setColor(11);
}
void displayPayRoll()
{
	setColor(11);
	cout << "			 _____                                                                                                                         _____ " << endl;
	cout << "			( ___ )-----------------------------------------------------------------------------------------------------------------------( ___ )" << endl;
	cout << "			 |   |                                                                                                                         |   | " << endl;
	cout << "			 |   |  _______  _______           _______  _______  _        _          _______  _______  _______  _______  _______ _________ |   | " << endl;
	cout << "			 |   | (  ____ )(  ___  )|\\     /|(  ____ )(  ___  )( \\      ( \\        (  ____ )(  ____ \\(  ____ )(  ___  )(  ____ )\\__   __/ |   | " << endl;
	cout << "			 |   | | (    )|| (   ) |( \\   / )| (    )|| (   ) || (      | (        | (    )|| (    \\/| (    )|| (   ) || (    )|   ) (    |   | " << endl;
	cout << "			 |   | | (____)|| (___) | \\ (_) / | (____)|| |   | || |      | |        | (____)|| (__    | (____)|| |   | || (____)|   | |    |   | " << endl;
	cout << "			 |   | |  _____)|  ___  |  \\   /  |     __)| |   | || |      | |        |     __)|  __)   |  _____)| |   | ||     __)   | |    |   | " << endl;
	cout << "			 |   | | (      | (   ) |   ) (   | (\\ (   | |   | || |      | |        | (\\ (   | (      | (      | |   | || (\\ (      | |    |   | " << endl;
	cout << "			 |   | | )      | )   ( |   | |   | ) \\ \\__| (___) || (____/\\| (____/\\  | ) \\ \\__| (____/\\| )      | (___) || ) \\ \\__   | |    |   | " << endl;
	cout << "			 |   | |/       |/     \\|   \\_/   |/   \\__/(_______)(_______/(_______/  |/   \\__/(_______/|/       (_______)|/   \\__/   )_(    |   | " << endl;
	cout << "			 |___|                                                                                                                         |___| " << endl;
	cout << "			(_____)-----------------------------------------------------------------------------------------------------------------------(_____)" << endl;
	setColor(11);
}
void displayViewRoll()
{
	setColor(11);
	cout << "			 _____                                                                                                       _____ " << endl;
	cout << "			( ___ )-----------------------------------------------------------------------------------------------------( ___ )" << endl;
	cout << "			 |   |                                                                                                       |   | " << endl;
	cout << "			 |   |          _________ _______             _______  _______           _______  _______  _        _        |   | " << endl;
	cout << "			 |   | |\\     /|\\__   __/(  ____ \\|\\     /|  (  ____ )(  ___  )|\\     /|(  ____ )(  ___  )( \\      ( \\       |   | " << endl;
	cout << "			 |   | | )   ( |   ) (   | (    \\/| )   ( |  | (    )|| (   ) |( \\   / )| (    )|| (   ) || (      | (       |   | " << endl;
	cout << "			 |   | | |   | |   | |   | (__    | | _ | |  | (____)|| (___) | \\ (_) / | (____)|| |   | || |      | |       |   | " << endl;
	cout << "			 |   | ( (   ) )   | |   |  __)   | |( )| |  |  _____)|  ___  |  \\   /  |     __)| |   | || |      | |       |   | " << endl;
	cout << "			 |   |  \\ \\_/ /    | |   | (      | || || |  | (      | (   ) |   ) (   | (\\ (   | |   | || |      | |       |   | " << endl;
	cout << "			 |   |   \\   /  ___) (___| (____/\\| () () |  | )      | )   ( |   | |   | ) \\ \\__| (___) || (____/\\| (____/\\ |   | " << endl;
	cout << "			 |   |    \\_/   \\_______/(_______/(_______)  |/       |/     \\|   \\_/   |/   \\__/(_______)(_______/(_______/ |   | " << endl;
	cout << "			 |___|                                                                                                       |___| " << endl;
	cout << "			(_____)-----------------------------------------------------------------------------------------------------(_____)" << endl;
	setColor(11);
}
void displayExitMenu()
{
	setColor(11);
	cout << "			 _____                                                                            _____ " << endl;
	cout << "			( ___ )--------------------------------------------------------------------------( ___ )" << endl;
	cout << "			 |   |                                                                            |   | " << endl;
	cout << "			 |   |  _______          __________________   _______  _______  _                 |   | " << endl;
	cout << "			 |   | (  ____ \\|\\     /|\\__   __/\\__   __/  (       )(  ____ \\( (    /||\\     /| |   | " << endl;
	cout << "			 |   | | (    \\/( \\   / )   ) (      ) (     | () () || (    \\/|  \\  ( || )   ( | |   | " << endl;
	cout << "			 |   | | (__     \\ (_) /    | |      | |     | || || || (__    |   \\ | || |   | | |   | " << endl;
	cout << "			 |   | |  __)     ) _ (     | |      | |     | |(_)| ||  __)   | (\\ \\) || |   | | |   | " << endl;
	cout << "			 |   | | (       / ( ) \\    | |      | |     | |   | || (      | | \\   || |   | | |   | " << endl;
	cout << "			 |   | | (____/\\( /   \\ )___) (___   | |     | )   ( || (____/\\| )  \\  || (___) | |   | " << endl;
	cout << "			 |   | (_______/|/     \\|\\_______/   )_(     |/     \\|(_______/|/    )_)(_______) |   | " << endl;
	cout << "			 |___|                                                                            |___| " << endl;
	cout << "			(_____)---------------------------------------------------------------------------(____)" << endl;
	setColor(11);
}
void displayperform()
{
	setColor(11);
	cout << "        _____                                                                                                                                  _____ " << endl;
	cout << "       ( ___ )--------------------------------------------------------------------------------------------------------------------------------( ___ )" << endl;
	cout << "        |   |                                                                                                                                  |   | " << endl;
	cout << "        |   |  _______  ______   ______     _______  _______  _______  _______  _______  _______  _______  _______  _        _______  _______  |   | " << endl;
	cout << "        |   | (  ___  )(  __  \\ (  __  \\   (  ____ )(  ____ \\(  ____ )(  ____ \\(  ___  )(  ____ )(       )(  ___  )( (    /|(  ____ \\(  ____ \\ |   | " << endl;
	cout << "        |   | | (   ) || (  \\  )| (  \\  )  | (    )|| (    \\/| (    )|| (    \\/| (   ) || (    )|| () () || (   ) ||  \\  ( || (    \\/| (    \\/ |   | " << endl;
	cout << "        |   | | (___) || |   ) || |   ) |  | (____)|| (__    | (____)|| (__    | |   | || (____)|| || || || (___) ||   \\ | || |      | (__     |   | " << endl;
	cout << "        |   | |  ___  || |   | || |   | |  |  _____)|  __)   |     __)|  __)   | |   | ||     __)| |(_)| ||  ___  || (\\ \\) || |      |  __)    |   | " << endl;
	cout << "        |   | | (   ) || |   ) || |   ) |  | (      | (      | (\\ (   | (      | |   | || (\\ (   | |   | || (   ) || | \\   || |      | (       |   | " << endl;
	cout << "        |   | | )   ( || (__/  )| (__/  )  | )      | (____/\\| ) \\ \\__| )      | (___) || ) \\ \\__| )   ( || )   ( || )  \\  || (____/\\| (____/\\ |   | " << endl;
	cout << "        |   | |/     \\|(______/ (______/   |/       (_______/|/   \\__/|/       (_______)|/   \\__/|/     \\||/     \\||/    )_)(_______/(_______/ |   | " << endl;
	cout << "        |___|                                                                                                                                  |___| " << endl;
	cout << "       (_____)--------------------------------------------------------------------------------------------------------------------------------(_____)" << endl;
	setColor(11);
}
void displayViewperform()
{
	setColor(11);
	cout << "     _____                                                                                                                                           _____ " << endl;
	cout << "    ( ___ )-----------------------------------------------------------------------------------------------------------------------------------------( ___ )" << endl;
	cout << "     |   |                                                                                                                                           |   | " << endl;
	cout << "     |   |          _________ _______             _______  _______  _______  _______  _______  _______  _______  _______  _        _______  _______  |   | " << endl;
	cout << "     |   | |\\     /|\\__   __/(  ____ \\|\\     /|  (  ____ )(  ____ \\(  ____ )(  ____ \\(  ___  )(  ____ )(       )(  ___  )( (    /|(  ____ \\(  ____ \\ |   | " << endl;
	cout << "     |   | | )   ( |   ) (   | (    \\/| )   ( |  | (    )|| (    \\/| (    )|| (    \\/| (   ) || (    )|| () () || (   ) ||  \\  ( || (    \\/| (    \\/ |   | " << endl;
	cout << "     |   | | |   | |   | |   | (__    | | _ | |  | (____)|| (__    | (____)|| (__    | |   | || (____)|| || || || (___) ||   \\ | || |      | (__     |   | " << endl;
	cout << "     |   | ( (   ) )   | |   |  __)   | |( )| |  |  _____)|  __)   |     __)|  __)   | |   | ||     __)| |(_)| ||  ___  || (\\ \\) || |      |  __)    |   | " << endl;
	cout << "     |   |  \\ \\_/ /    | |   | (      | || || |  | (      | (      | (\\ (   | (      | |   | || (\\ (   | |   | || (   ) || | \\   || |      | (       |   | " << endl;
	cout << "     |   |   \\   /  ___) (___| (____/\\| () () |  | )      | (____/\\| ) \\ \\__| )      | (___) || ) \\ \\__| )   ( || )   ( || )  \\  || (____/\\| (____/\\ |   | " << endl;
	cout << "     |   |    \\_/   \\_______/(_______/(_______)  |/       (_______/|/   \\__/|/       (_______)|/   \\__/|/     \\||/     \\||/    )_)(_______/(_______/ |   | " << endl;
	cout << "     |___|                                                                                                                                           |___| " << endl;
	cout << "    (_____)-----------------------------------------------------------------------------------------------------------------------------------------(_____)" << endl;
	setColor(11);
}
void sayThanks()
{
	cout << endl
		 << endl
		 << endl
		 << endl;
	setColor(10);
	cout << "                >>================================================================================================================<<" << endl;
	cout << "                || _____ _                 _     __   __            _____            _   _     _               _____ __  __ ____  ||" << endl;
	cout << "                |||_   _| |__   __ _ _ __ | | __ \\ \\ / /__  _   _  |  ___|__  _ __  | | | |___(_)_ __   __ _  | ____|  \\/  / ___| ||" << endl;
	cout << "                ||  | | | '_ \\ / _` | '_ \\| |/ /  \\ V / _ \\| | | | | |_ / _ \\| '__| | | | / __| | '_ \\ / _` | |  _| | |\\/| \\___ \\ ||" << endl;
	cout << "                ||  | | | | | | (_| | | | |   <    | | (_) | |_| | |  _| (_) | |    | |_| \\__ \\ | | | | (_| | | |___| |  | |___) |||" << endl;
	cout << "                ||  |_| |_| |_|\\__,_|_| |_|_|\\_\\   |_|\\___/ \\__,_| |_|  \\___/|_|     \\___/|___/_|_| |_|\\__, | |_____|_|  |_|____/ ||" << endl;
	cout << "                ||                                                                                     |___/                      ||" << endl;
	cout << "                >>================================================================================================================<<" << endl;
	setColor(11);
}