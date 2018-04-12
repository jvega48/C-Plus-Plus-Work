#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;

struct MonthlyBudget
{
	float Housing,
		Utilities,
		HouseholdExpenses,
		Transportation,
		Food,
		Medical,
		Insurance,
		Entertainment,
		Clothing,
		Miscellaneous;

};
struct CorpData
{
	string name;
	double firstQ,
		secondQ,
		thirdQ,
		fourthQ,
		totalQ, 
		AverageQ;
	CorpData();
	CorpData(string, double, double, double, double);
};
CorpData::CorpData() {
}
CorpData::CorpData(string s, double f, double sd, double t, double ft) {
	this->name = s;
	this->firstQ = f;
	this->secondQ = sd;
	this->thirdQ = t;
	this->fourthQ = ft;
	totalQ;
	AverageQ;
}

void corpdata();
void placeCursor(HANDLE, int, int);

void monthlyBudget();
void displayInformation(HANDLE, MonthlyBudget);
void getUserData(HANDLE, MonthlyBudget& b);
void displayReport(HANDLE, MonthlyBudget, MonthlyBudget);
void calculations(CorpData &data);
int main() {
	corpdata();
	monthlyBudget();
	system("pause");
}
void corpdata() {
	CorpData east(" East Devision ", 123, 23, 21, 21);
	CorpData west(" West Devision ", 123, 25, 22, 211);
	CorpData north(" North Devision ", 43, 13, 55, 99);
	CorpData south(" South Devision ", 67, 277, 21.43, 21.43);
	calculations(east);
	cout << " " << endl;
	calculations(west);
	cout << " " << endl;
	calculations(north);
	cout << " " << endl;
	calculations(south);
	cout << " " << endl;
}
void placeCursor(HANDLE screen, int row, int col)
{
	COORD position;
	position.X = row;
	position.Y = col;
	SetConsoleCursorPosition(screen, position);
}
void monthlyBudget() {
	MonthlyBudget budgetPrefield = { 500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 150.00, 75.00,  50.00 };
	MonthlyBudget budget;
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	displayInformation(screen, budgetPrefield);
	getUserData(screen, budget);
	displayReport(screen, budgetPrefield, budget);
}
void displayInformation(HANDLE screen, MonthlyBudget b) {
	placeCursor(screen, 10, 0);
	cout << "******Inputing Student Data Of Amounth Spent******\n";
	placeCursor(screen, 5, 1);
	cout << "Housing Budget - " << b.Housing << "	| Expenses: " <<endl;
	placeCursor(screen, 5, 2);
	cout << "Utilities Budget - " << b.Utilities << "	| Expenses: " << endl;
	placeCursor(screen, 5, 3);
	cout << "Household Budget - " << b.HouseholdExpenses << "	| Expenses: " << endl;
	placeCursor(screen, 5, 4);
	cout << "Transportation Budget - " << b.Transportation << "	| Expenses: " << endl;
	placeCursor(screen, 5, 5);
	cout << "Food Budget - " << b.Food << "		| Expenses: " << endl;
	placeCursor(screen, 5, 6);
	cout << "Medical Budget - " << b.Medical << "	| Expenses: " << endl;
	placeCursor(screen, 5, 7);
	cout << "Insurance Budget - " << b.Insurance << "	| Expenses: "<< endl;
	placeCursor(screen, 5, 8);
	cout << "Entertainment Budget - " << b.Entertainment << "	| Expenses: " << endl;
	placeCursor(screen, 5, 9);
	cout << "Clothing Budget - " << b.Clothing << "	| Expenses: " << endl;
	placeCursor(screen, 5, 10);
	cout << "Mescellaneous Budget - " << b.Miscellaneous << "	| Expenses: " << endl;
}
void getUserData(HANDLE screen, MonthlyBudget &b)
{
	placeCursor(screen, 45, 1);
	cin >> b.Housing;
	placeCursor(screen, 45, 2);
	cin >> b.Utilities;
	placeCursor(screen, 45, 3);
	cin >> b.HouseholdExpenses;
	placeCursor(screen, 45, 4);
	cin >>b.Transportation;
	placeCursor(screen, 45, 5);
	cin >> b.Food;
	placeCursor(screen, 45, 6);
	cin >> b.Medical;
	placeCursor(screen, 45, 7);
	cin >> b.Insurance;
	placeCursor(screen, 45, 8);
	cin >> b.Entertainment;
	placeCursor(screen, 45, 9);
	cin >> b.Clothing;
	placeCursor(screen, 45, 10);
	cin >> b.Miscellaneous;
}
void displayReport(HANDLE screen, MonthlyBudget b, MonthlyBudget i) {
	float totalmb, totalb;
	placeCursor(screen, 13, 12);
	cout << "******Monthly Budget Report******" << endl;
	if (i.Housing > b.Housing) {
		placeCursor(screen, 5, 13);
		cout << "Housing Expenses is OVER Budget by:	$" << i.Housing - b.Housing <<endl;
	}
	else{
		placeCursor(screen, 5, 13);
		cout << "Housing Expenses is UNDER Budget:		$" << b.Housing - i.Housing << endl;
	}

	if (i.Utilities > b.Utilities) {
		placeCursor(screen, 5, 14);
		cout << "Utilities Expenses is OVER Budget:		$" << i.Utilities - b.Utilities << endl;
	}
	else {
		placeCursor(screen, 5, 14);
		cout << "Utilities Expenses is UNDER Budget:	$" << b.Utilities - i.Utilities << endl;
	}

	if (i.HouseholdExpenses > b.HouseholdExpenses) {
		placeCursor(screen, 5, 15);
		cout << "Household Expenses is OVER Budget:		$" << i.HouseholdExpenses - b.HouseholdExpenses << endl;
	}
	else {
		placeCursor(screen, 5, 15);
		cout << "Household Expenses is UNDER Budget:	$" << b.HouseholdExpenses - i.HouseholdExpenses << endl;
	}
	if (i.Transportation > b.Transportation) {
		placeCursor(screen, 5, 16);
		cout << "Tranportation Expenses is OVER Budget:	$" << i.Transportation - b.Transportation << endl;
	}
	else {
		placeCursor(screen, 5, 16);
		cout << "Transportation Expenses is UNDER Budget:	$" << b.Transportation - i.Transportation << endl;
	}

	if (i.Food > b.Food) {
		placeCursor(screen, 5, 17);
		cout << "Food Expenses is OVER Budget:		$" << i.Food - b.Food << endl;
	}
	else {
		placeCursor(screen, 5, 17);
		cout << "Food Expenses is UNDER Budget:		$" << b.Food - i.Food << endl;
	}

	if (i.Medical > b.Medical) {
		placeCursor(screen, 5, 18);
		cout << "Medical Expenses is OVER Budget:		$" << i.Medical - b.Medical << endl;
	}
	else {
		placeCursor(screen, 5, 18);
		cout << "Medical Expenses is UNDER Budget:		$" << b.Medical - i.Medical << endl;
	}

	if (i.Insurance > b.Insurance) {
		placeCursor(screen, 5, 19);
		cout << "Insurance Expenses is OVER Budget:		$" << i.Insurance - b.Insurance << endl;
	}
	else {
		placeCursor(screen, 5, 19);
		cout << "Insurance Expenses is UNDER Budget:	$" << b.Insurance - i.Insurance << endl;
	}

	if (i.Entertainment > b.Entertainment) {
		placeCursor(screen, 5, 20);
		cout << "Entertainment Expenses is OVER Budget:	$" << i.Entertainment - b.Entertainment << endl;
	}
	else {
		placeCursor(screen, 5, 20);
		cout << "Utilities Expenses is UNDER Budget:	$" << b.Entertainment - i.Entertainment << endl;
	}
	if (i.Clothing > b.Clothing) {
		placeCursor(screen, 5, 21);
		cout << "Clothing Expenses is OVER Budget:		$" << i.Clothing - b.Clothing << endl;
	}
	else {
		placeCursor(screen, 5, 21);
		cout << "Clothing Expenses is UNDER Budget:		$" << b.Clothing - i.Clothing << endl;
	}
	if (i.Miscellaneous > b.Miscellaneous) {
		placeCursor(screen, 5, 22);
		cout << "Miscellaneous Expenses is OVER Budget:	$" << i.Miscellaneous - b.Miscellaneous << endl;
	}
	else {
		placeCursor(screen, 5, 22);
		cout << "Miscellaneous Expenses is UNDER Budget:	$" << b.Miscellaneous - i.Miscellaneous << endl;
	}
	totalmb = b.Clothing + b.Entertainment + b.Food + b.HouseholdExpenses + b.Housing + b.Insurance + b.Medical
		+ b.Miscellaneous + b.Transportation + b.Utilities;

	totalb = i.Clothing + i.Entertainment + i.Food + i.HouseholdExpenses + i.Housing + i.Insurance
		+ i.Medical + i.Miscellaneous + i.Transportation + i.Utilities;

	if (totalb > totalmb) {
		placeCursor(screen, 5, 23);
		cout << "Monthly Expenses is OVER Budget by:	$" << totalb - totalmb << endl;
	}
	else {
		placeCursor(screen, 5, 23);
		cout << "Monthly Expenses is UNDER Budget by:	$"<< totalmb - totalb << endl;
	}
}
void calculations(CorpData &data)
{
	data.totalQ = data.firstQ + data.secondQ + data.thirdQ + data.fourthQ;
	cout << "The total sale for the 4 quates for the " << data.name << " is " << data.totalQ << endl;
	
	data.AverageQ = data.totalQ / 4;

	cout <<"The average for this devision is " << data.AverageQ << endl;
	
}