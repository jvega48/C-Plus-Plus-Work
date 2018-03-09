#include <iostream>

/*
	Week Three Homework	
	By: Jose V.
*/

using namespace std;

int main() {
	double f_balance = 0;
	double interest_rate, balance, months, deposit_amount;
	double withdraw_amount, monthly_interest, interest_earn = 0;
	double number_deposits = 0, number_withdraw = 0;
	int i = 1;
	cout << "Enter anual interest rate: ";
	cin >> interest_rate;

	while (interest_rate < 0) {
		cout << "Enter a positive number: ";
		cin >> interest_rate;
	}

	cout << "Enter starting balance: ";
	cin >> balance;

	f_balance = balance;
	while (balance < 0) {
		cout << "Enter a positive number: ";
		cin >> balance;
	}

	cout << "How long have you had this account for? ";
	cin >> months;

	while (months < 0) {
		cout << "Enter a positive number: ";
		cin >> months;
	}

	while (i <= months) {
		
		cout << "Enter the deposite amount for month " << i << " ";
		cin >> deposit_amount;

		while (deposit_amount < 0) {
			cout << "Enter a positive number: ";
			cin >> deposit_amount;
		}

		if (deposit_amount >= 0) {
			number_deposits++;
		}

		balance += deposit_amount;
		deposit_amount += deposit_amount;

		cout << "Enter the widreaw amount for month " << i << " ";
		cin >> withdraw_amount;

		while (withdraw_amount < 0 || withdraw_amount > balance) {
			cout << "Enter a positive number: ";
			cin >> withdraw_amount;
		}

		if (withdraw_amount >= 0) {
			number_withdraw++;
		}

		balance -= withdraw_amount;
		withdraw_amount += withdraw_amount;

		monthly_interest = interest_rate / 12;
		interest_earn = (monthly_interest * balance) / 100;
		interest_earn += interest_earn;
		balance += interest_earn;

		if (balance < 0) {
			cout << "Account has reach zero balance it will now be close. cannot continue executing." << endl;
			break;
		}

		i++;
	}

	cout << "Initial Balance " << f_balance << endl;;
	cout << "Number of months " << months << endl;
	cout << "Number of depositis made " << number_deposits << " was a total of " << deposit_amount << endl;
	cout << "Number of widraws made " << number_withdraw << " was a total of " << withdraw_amount << endl;
	cout << "Interest Rate " << interest_rate << endl;
	cout << "Interest Earn " << interest_earn << endl;

	cout << "Ending Balance " << balance << endl;


	system("pause");

}