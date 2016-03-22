#include <iostream>
#include <vector>
using namespace std;

#include "Poll.hpp"

int main()
{
	vector<Poll> pollList;

	while (true)
	{
		Poll newPoll;
		string question;
		string answers[4];

		cout << "POLL #" << pollList.size() << endl;
		cout << "Enter poll question: ";
		cin.ignore();
		getline(cin, question);

		for (int i = 0; i < 4; i++)
		{
			cout << "Enter answer " << i << ": ";
			getline(cin, answers[i]);
		}
		
		newPoll.SetQuestion(question);
		newPoll.SetAnswers(answers[0], answers[1], answers[2], answers[3]);

		pollList.push_back(newPoll);

		cout << "Create another? (y/n): ";
		string choice;
		cin >> choice;

		cout << endl << endl;

		if (choice == "n")
		{
			// Leave loop
			break;
		}
	}

	for (int i = 0; i < pollList.size(); i++)
	{
		cout << endl << endl;
		pollList[i].DisplayPoll();

		cout << "VOTE: ";
		int choice;
		cin >> choice;

		pollList[i].Vote(choice);
		pollList[i].DisplayResults();

		cout << "Continue? (y/n): ";
		string continueChoice;
		cin >> continueChoice;
		if (continueChoice == "n")
		{
			break;
		}
	}

	return 0;
}
