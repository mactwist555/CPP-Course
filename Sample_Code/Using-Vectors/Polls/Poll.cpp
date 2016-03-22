#include "Poll.hpp"

string Poll::GetQuestion()
{
	return question;
}

void Poll::SetQuestion(string val)
{
	question = val;
}

void Poll::SetAnswers(string a, string b, string c, string d)
{
	answers[0] = a;
	answers[1] = b;
	answers[2] = c;
	answers[3] = d;

	votes[0] = 0;
	votes[1] = 0;
	votes[2] = 0;
	votes[3] = 0;

	totalVotes = 0;
}

void Poll::DisplayPoll()
{
	cout << "QUESTION" << endl;
	cout << question << endl << endl;
	cout << "VOTE" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << i << ". " << answers[i] << endl;
	}
}

void Poll::Vote(int index)
{
	votes[index]++;
	totalVotes++;
}

void Poll::DisplayResults()
{
	cout << "QUESTION" << endl;
	cout << question << endl << endl;
	cout << "RESULTS" << endl;
	for (int i = 0; i < 4; i++)
	{
		float t = totalVotes;
		float v = votes[i];
		float ratio = v / t;
		float percent = ratio * 100;

		cout << i << ". " 
			<< answers[i] 
			<< "\tVOTES: " << votes[i]
			<< "\t%" << percent
			<< endl;
	}
}
