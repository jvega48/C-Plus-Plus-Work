#include<iostream>
#include<iomanip>
using namespace std;

/*
	Week Two
	By: Jose V.
	TODO: Need to fix minor bug
*/

int main()
{
	const int SIZE = 12;
	char name1[SIZE];
	char name2[SIZE];
	char name3[SIZE];
	int time1, time2, time3;

	cout << "Input your name and the time you finished the race ";
	cin >> setw(SIZE) >> name1 >> time1;
	cout << "Input your name and the time you finished the race ";
	cin >> setw(SIZE) >> name2 >> time2;
	cout << "Input your name and the time you finished the race ";
	cin >> setw(SIZE) >> name3 >> time3;

	if (time1 < 0)
	{
		cout << "That is an invalid time. " << name1 << " enter a positive time you finished the race";
		cin >> time1;
	}
	if (time2 < 0)
	{
		cout << "That is an invalid time. " << name2 << " enter a positive time you finished the race";
		cin >> time2;
	}
	if (time3 < 0)
	{
		cout << "That is an invalid time. " << name3 << " enter a positive time you finished the race";
		cin >> time3;
	}
	if (time1 < time2) {
		if (time2 < time3) {
			cout << "The person that got frist place was " << name1 << " with the time of " << time1 << endl;
			cout << "The person that got second place was " << name2 << " with the time of " << time2 << endl;
			cout << "The person that got thrid place was " << name3 << " with the time of " << time3 << endl;
		}
	}
	if (time1 < time2) {	
		if (time3 < time2) {
			cout << "The person that got frist place was " << name3 << " with the time of " << time3 << endl;
			cout << "The person that got second place was " << name1 << " with the time of " << time1 << endl;
			cout << "The person that got thrid place was " << name2 << " with the time of " << time2 << endl;
		}
	}
	if (time2 < time1) {	
		if (time1 < time3) {
			cout << "The person that got frist place was " << name2 << " with the time of " << time2 << endl;
			cout << "The person that got second place was " << name1 << " with the time of " << time1 << endl;
			cout << "The person that got thrid place was " << name3 << " with the time of " << time3 << endl;
		}
	}

	if (time2 < time1) {	
		if (time2 < time3) {
			cout << "The person that got frist place was " << name2 << " with the time of " << time2 << endl;
			cout << "The person that got second place was " << name3 << " with the time of " << time3 << endl;
			cout << "The person that got thrid place was " << name1 << " with the time of " << time1 << endl;
		}
	}
	if (time3 < time2) {
		if (time2 < time1) {
			cout << "The person that got frist place was " << name3 << " with the time of " << time3 << endl;
			cout << "The person that got second place was " << name2 << " with the time of " << time2 << endl;
			cout << "The person that got thrid place was " << name1 << " with the time of " << time1 << endl;
		}
	}
	system("pause");
}