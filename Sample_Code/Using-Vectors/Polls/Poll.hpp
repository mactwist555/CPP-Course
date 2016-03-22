#ifndef _POLL
#define _POLL

#include <iostream>
#include <string>
using namespace std;

class Poll
{
private:
	string question;
	string answers[4];
	int votes[4];
	int totalVotes;

public:
	string GetQuestion();
	void SetQuestion(string val);

	void SetAnswers(string a, string b, string c, string d);
	void DisplayPoll();
	void Vote(int index);
	void DisplayResults();
};

#endif
