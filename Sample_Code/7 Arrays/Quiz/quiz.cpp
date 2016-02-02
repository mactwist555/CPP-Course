#include <iostream>
#include <string>
using namespace std;

const int QUESTION_AMOUNT = 3;
const int ANSWER_AMOUNT = 4;

void CreateQuestions( string questions[QUESTION_AMOUNT], string answers[QUESTION_AMOUNT][ANSWER_AMOUNT], int correctAnswer[QUESTION_AMOUNT] );
void Quiz( const string questions[QUESTION_AMOUNT], const string answers[QUESTION_AMOUNT][ANSWER_AMOUNT], const int correctAnswer[QUESTION_AMOUNT] );

int main()
{
    string questions[QUESTION_AMOUNT];
    string answers[QUESTION_AMOUNT][ANSWER_AMOUNT];
    int correctAnswer[QUESTION_AMOUNT];

    CreateQuestions( questions, answers, correctAnswer );

    for ( int i = 0; i < 40; i++ )
    {
        cout << endl;
    }

    Quiz( questions, answers, correctAnswer );

    return 0;
}

void CreateQuestions( string questions[QUESTION_AMOUNT], string answers[QUESTION_AMOUNT][ANSWER_AMOUNT], int correctAnswer[QUESTION_AMOUNT] )
{
    for ( int q = 0; q < QUESTION_AMOUNT; q++ )
    {
        cout << endl << "QUESTION " << (q+1) << endl;
        cout << "Enter a question: ";
        getline( cin, questions[q] );

        for ( int a = 0; a < ANSWER_AMOUNT; a++ )
        {
            cout << "Enter answer " << (a+1) << ": ";
            getline( cin, answers[q][a] );
        }

        cout << "Enter correct answer #: ";
        cin >> correctAnswer[q];
        while ( correctAnswer[q] < 1 || correctAnswer[q] > 4 )
        {
            cout << "Invalid choice. Try again." << endl;
            cout << "Enter correct answer #: ";
            cin >> correctAnswer[q];
        }
        correctAnswer[q]--;
        cin.ignore();
    }
}

void Quiz( const string questions[QUESTION_AMOUNT], const string answers[QUESTION_AMOUNT][ANSWER_AMOUNT], const int correctAnswer[QUESTION_AMOUNT] )
{
    int score = 0;

    for ( int q = 0; q < QUESTION_AMOUNT; q++ )
    {
        cout << endl;
        cout << "Your score is " << score << endl;
        cout << "QUESTION #" << (q+1) << endl;
        cout << questions[q] << endl;

        for ( int a = 0; a < 4; a++ )
        {
            cout << (a+1) << ". " << answers[q][a] << endl;
        }

        cout << "Your answer: ";
        int answer;
        cin >> answer;
        while ( answer < 1 || answer > 4 )
        {
            cout << "Invalid choice. Try again." << endl;
            cout << "Your answer: ";
            cin >> answer;
        }
        answer--;

        if ( answer == correctAnswer[q] )
        {
            cout << "CORRECT!" << endl;
            score++;
        }
        else
        {
            cout << "Wrong!" << endl;
        }
    }

    cout << endl;
    cout << "You got " << score << " out of " << QUESTION_AMOUNT << "!" << endl;
}












