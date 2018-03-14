#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
#include <string>
#include <thread>
#include <chrono>
#include <ctime>

using namespace std;
/*
	
	Chapter 6 Homework
	By: Jose V.
*/
void getJudgeData(double &param);
void hospitalProgram();
void partOne();
void population();
float populationSize(double, double, double);
double inPatient(int,double, double, double);
double inPatient(double, double);
double helperFunction(double);
double calcScore(double, double, double, double, double);
double findLowest(double, double, double, double, double);
double findHighest(double, double, double, double, double);
double  * findLowestArray(double scoreOne, double scoreTwo, double scoreThree, double scoreFour, double scoreFive);
int main()
{
		partOne();
		hospitalProgram();
		population();

		//double *sol =  findLowestArray(4,2,3,9,5);
		//cout << "[ " << sol[0] << " , " << sol[1] << " ]" << endl;
	system("pause");
}

void partOne(){
	double scoreOne, scoreTwo, scoreThree, scoreFour, scoreFive, average;
	cout << "Taking in the score - calling all five judges... " << endl;
	getJudgeData(scoreOne);
	getJudgeData(scoreTwo);
	getJudgeData(scoreThree);
	getJudgeData(scoreFour);
	getJudgeData(scoreFive);
	average = calcScore(scoreOne, scoreTwo, scoreThree, scoreFour, scoreFive);
	cout << "The avergae is: " << average << endl;

}
void getJudgeData(double &param) {
	
	cout << "Enter your score? 0 - 10" << endl;
	cin >> param;
	while (param < 0 || param > 10) {
		cout << "Please! Enter your score between? 0 - 10" << endl;
		cin >> param;
	}
}
double findLowest(double scoreOne, double scoreTwo, double scoreThree, double scoreFour, double scoreFive) {
	double lowest;

	/*int scores[5] = {scoreOne, scoreTwo, scoreThree, scoreFour, scoreFive};

	for (int i : scores) {
	
	}*/
	//asume scoreOne is lowest and check from there
	lowest = scoreOne;
	if (scoreTwo < lowest) {
		lowest = scoreTwo;
	}
	if (scoreThree < lowest) {
		lowest = scoreThree;
	}
	if (scoreFour < lowest) {
		lowest = scoreFour;
	}
	if (scoreFive < lowest) {
		lowest = scoreFive;
	}
	return lowest;
}
double findHighest(double scoreOne, double scoreTwo, double scoreThree, double scoreFour, double scoreFive) {
	double highest;
	//asume scoreOne is highest and check from there
	highest = scoreOne;
	if (scoreTwo > highest) {
		highest = scoreTwo;
	}
	if (scoreThree > highest) {
		highest = scoreThree;
	}
	if (scoreFour > highest) {
		highest = scoreFour;
	}
	if (scoreFive > highest) {
		highest = scoreFive;
	}
	return highest;
}
double calcScore(double scoreOne, double scoreTwo, double scoreThree, double scoreFour, double scoreFive) {
	double sum, min_val, max_val, ave;

	sum = scoreOne + scoreTwo + scoreThree + scoreFour + scoreFive;

	min_val = findLowest(scoreOne, scoreTwo, scoreThree, scoreFour, scoreFive);
	
	max_val = findHighest(scoreOne, scoreTwo, scoreThree, scoreFour, scoreFive);

	sum = sum - (min_val + max_val);

	ave = sum / 3;
	cout << "The max score is " << max_val << endl;
	cout << "The min score is " << min_val << endl;
	cout << "The sum score withougth removing the low or high is " << sum << endl;
	
	return ave;
}

void hospitalProgram() {
	char choice;
	int numberOfDaya;
	double dailyRate, hospitalServices, medicationCharges, total;

	cout << "Welcome are you a in-patient(i) or out-patient(o)? " << endl;
	cin >> choice;

	while (choice != 'i' && choice != 'o') {
		cout << "Please enter a valied response-patient(i) or out-patient(o)? " << endl;
		cin >> choice;
	}

	cout << "Thank you for that information now we need other medical expenses." << endl;


	cout << "Please enter your hospital service chages? " << endl;
	cin >> hospitalServices;
	while (hospitalServices < 0) {
		cout << "Please enter your hospital service chages? " << endl;
		cin >> hospitalServices;
	}

	cout << "Please enter your medication, lab work, or any other chages? " << endl;
	cin >> medicationCharges;
	while (medicationCharges < 0) {
		cout << "Please enter your extra charges chages? " << endl;
		cin >> medicationCharges;
	}


	if (choice == 'i') {
		cout << "Please enter the hospital rate? " << endl;
		cin >> dailyRate;
		while (dailyRate < 0) {
			cout << "Please enter a positive rate number? " << endl;
			cin >> dailyRate;
		}
		cout << "Please enter the number of days you spend in the hospital? " << endl;
		cin >> numberOfDaya;
		while (numberOfDaya < 0) {
			cout << "Please enter a positive number of days? " << endl;
			cin >> numberOfDaya;
			//numberOfDaya = helperFunction(numberOfDaya);
		}

		total = inPatient(numberOfDaya, dailyRate, hospitalServices, medicationCharges);
		cout << "Your total expenses for being in the hospital is: $ " << total << endl;
	}
	else {
		total = inPatient(hospitalServices, medicationCharges);
		cout << "Your total expenses out of the hospital is: $ " << total << endl;
	}

}
double helperFunction(double i) {
	double newValue = 0;
	cout << i << endl;
	if (i < 0) {
		newValue = abs(i);
	}
	cout << newValue << endl;
	return newValue;
}
double inPatient(int number_of_days, double hospital_rate, double medication_charges, double hospital_charges) {
	return (number_of_days * hospital_rate) + medication_charges + hospital_charges;
}
double inPatient(double medication_charges, double hospital_charges) {
	return medication_charges + hospital_charges;
}
void population() {
	int years;
	double sizePopulation, yearAfter;
	double birthRate, deathRate;

	cout << "Enter the population size? " << endl;
	cin >> sizePopulation;
	while (sizePopulation < 2) {
		cout << "Please enter pupulation size bigger than 2? " << endl;
		cin >> sizePopulation;
	}

	cout << "Enter the number of years? " << endl;
	cin >> years;
	while (years < 1) {
		cout << "Please enter number of years bigger than 1? " << endl;
		cin >> years;
	}

	cout << "Enter the death rate? " << endl;
	cin >> deathRate;
	while (deathRate < 0) {
		cout << "Please enter a positive number ? " << endl;
		cin >> deathRate;
	}

	cout << "Enter the birth rate of years? " << endl;
	cin >> birthRate;
	while (birthRate < 0) {
		cout << "Please enter a positive number? " << endl;
		cin >> birthRate;
	}

	cout << "The start of the populationis: " << sizePopulation <<endl;
	for(int i = 1 ; i <= years; i++) {

		yearAfter = populationSize(sizePopulation, birthRate, deathRate);
		cout << "Population: " << i << yearAfter << endl;
		//set new size of pupulations
		sizePopulation = yearAfter;
	}
}
float populationSize(double param, double birth, double death) {
	//TODO: Formula N =P(1 + B)(1 -D)
	//N: New populations, P: previous population size, B: birth rate, D: death rate
	float n = 0;
	double b = birth / param;
	double d = death / param;
	n = param * (1 + b) * (1 - d);
	return n;
}
//Just testing the array to find low and high 
double * findLowestArray(double scoreOne, double scoreTwo, double scoreThree, double scoreFour, double scoreFive) {
	
	double lowest;
	double high;
	int scores[5] = { scoreOne, scoreTwo, scoreThree, scoreFour, scoreFive };
	lowest = scores[0];
	high = scores[4];
	double num[2];
	for (int i : scores) {
		if (i < lowest) {
			lowest = i;
		}
		if (i > high) {
			high = i;
		}
	}
	num[0] = lowest;
	num[1] = high;
	return num;
}