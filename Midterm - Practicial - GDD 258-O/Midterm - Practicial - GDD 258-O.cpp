// Midterm - Practicial - GDD 258-O.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int NextRandom(int min, int max);
void EmptyInput();
void Reset();
void ReadLine(const char prompt[]);

int Guess;
int Total;
char Input[200] = "";

class Question
{
private:
    string Query;
    int CorrectAnswer = 0;
    string Answers[4] = { "", "", "", "" };

public:
	Question() {}
	Question(string q, string a1, string a2, string a3, string a4, int correct) {
		Query = q;
		Answers[0] = a1;
		Answers[1] = a2;
		Answers[2] = a3;
		Answers[3] = a4;
		CorrectAnswer = correct;
	}

    int askQuestion() {
		cout << Query;
		cout << "a. " << Answers[0] << "\n";
		cout << "b. " << Answers[1] << "\n";
		cout << "c. " << Answers[2] << "\n";
		cout << "d. " << Answers[3] << "\n";
		ReadLine("");
		int guess = -1;
		switch (Input[0]) {
		case 'a': guess = 0; break;
		case 'b': guess = 1; break;
		case 'c': guess = 2; break;
		case 'd': guess = 3; break;
		}
		return guess == CorrectAnswer ? 1 : 0;
    }

};

bool NextRandomSeedSet = false;
int NextRandom(int min, int max) {
	if (NextRandomSeedSet == false) {
		srand((unsigned)time(NULL));
		NextRandomSeedSet = true;
	}
	return (rand() % (max - min)) + min;
}

void EmptyInput() {
	for (int i = 0; i < sizeof(Input); i++) {
		Input[i] = '\0';
	}
}

void Reset() {
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}

void ReadLine(string prompt) {
	EmptyInput();
	cout << prompt;
	cin.get(Input, sizeof(Input));
	Reset();
}

void ReadLine(const char prompt[]) {
	EmptyInput();
	cout << prompt;
	cin.get(Input, sizeof(Input));
	Reset();
}

int main()
{
	ReadLine("Press enter to start the test...");
	Question queries[4];
	queries[0] = Question("What color do blue and red make when mixed? \n", "Aqua", "Purple", "Yellow", "Green", 1);
	queries[1] = Question("Who won the 2022 RBC Canadian Open? \n", "John Daly", "Arnold Pamler", "Rory MclLroy", "Tiger Woods", 2);
	queries[2] = Question("What time did Cinderella have to be home? \n", "Noon", "Midnight", "Dusk", "Dawn", 1);
	queries[3] = Question("Who won the 2022 NCAA Men's Basketball Championship? \n", "Full Sail University", "Michigan University", "Arkansas University", "Kansas University", 3);
	int q = NextRandom(0, 4);
	int score= queries[q].askQuestion();
	if (score == 1) {
		ReadLine("That is correct");
	}
	else {
		ReadLine("That is incorrect.");
	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
