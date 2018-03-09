#include <iostream>
#include <string>

using namespace std;

/*
	Week Two Homework 
	By: Jose V.
*/
void displayChar();
void displayInt();
void displayfloat();
void displayDouble();
void candyBarSales();
int main()
{
	displayChar();
	displayInt();
	displayfloat();
	displayDouble();
	candyBarSales();
	system("pause");
}

void displayChar() {
	cout << "The value of a char is: " << sizeof(char) << " byte(s)" << endl;
}

void displayInt(){
	cout << "The value of a int is: " << sizeof(int) << " byte(s)" << endl;
}

void displayfloat(){
	cout << "The value of a float is: " << sizeof(float) << " byte(s)" << endl;
}

void displayDouble(){
	cout << "The value of a double is: " << sizeof(double) << " byte(s)" << endl;
}

void candyBarSales()
{
	int total_amount_earn = 0, total_bars_sold = 0;
	double price_per_bar = 1.75;
	cout << "Welcome to the candy bars sales!" << endl;
	cout << "How many bars would you like to buy today?" << endl;
	cin >> total_bars_sold;

	cout << "The price for each bar is $" << price_per_bar << endl;

	total_amount_earn = total_bars_sold * price_per_bar;

	cout << "The amount ear from this entire sale is $" << total_amount_earn << " by seeling " << total_bars_sold << " bars at a price of $" << price_per_bar << endl;
}


