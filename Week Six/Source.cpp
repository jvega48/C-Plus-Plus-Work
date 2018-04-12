#include <iostream>
#include <fstream>
using namespace std;

class Payroll
{
public:
	Payroll();
	Payroll(double r, double h);
	double getHourlyPay();
	double getPayRate();
	void setHourlyPay(double);
	void setPayRate(double);
	double grossPay();

private:
	double EmployeeHourlyPay;
	double PayRate;
};

Payroll::Payroll()
{
	EmployeeHourlyPay = 0;
	PayRate = 0;
}
Payroll::Payroll(double r, double h) {
	setHourlyPay(r);
	setPayRate(h);
}
double Payroll::getHourlyPay()
{
	return EmployeeHourlyPay;
}

double Payroll::getPayRate()
{
	return PayRate;
}

void Payroll::setHourlyPay(double h)
{
	if (h > 0)
		this->EmployeeHourlyPay = h;
	else
		EmployeeHourlyPay = 0;
}

void Payroll::setPayRate(double p)
{
	if (p > 0)
		this->PayRate = p;
	else
		PayRate = 0;
}

double Payroll::grossPay()
{
	double pay_total = 0;
	if (EmployeeHourlyPay <= 40)
		pay_total = EmployeeHourlyPay * PayRate;
	else
		pay_total = 40 * PayRate + (EmployeeHourlyPay - 40) * PayRate * 1.5;
	
	return pay_total;
}


int main() {
	
	Payroll employee [7]; 
	double payRate, hoursWorked;
	int indexElemtent = 0;
	ifstream infile("payroll.dat");

	if (!infile) {
		cout << "Unbalve to open file" << endl;
		system("pause");
	}

	while (!infile.eof()) {

		infile >> hoursWorked >> payRate;

		employee[indexElemtent].setPayRate(payRate);
		employee[indexElemtent].setHourlyPay(hoursWorked);

		indexElemtent++;
		if (indexElemtent == 7)
			break;
	}
	infile.close();

	cout << "Employe infor for seven." << endl;
	for (int i = 0; i < indexElemtent; i++) {
		cout << "Employe " << i << " worked " << employee[i].getHourlyPay() << " hours." << endl;
		cout << "Employe " << " gets payed " << employee[i].getPayRate() << " per hours." << endl;
		cout << "Employe " << " grows pay is " << employee[i].grossPay() << "  ." << endl;
		cout << " " << endl;

	}
	system("pause");
}