#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bfs.h"
using namespace std;

int main()
{
	bfs word_solver("4LetterWordsReduced.dat");
	vector<string> solution = word_solver.getPath("dare", "make");
	word_solver.displayPath();

	//PAUSE
	cout << endl << endl;
	system("pause;");
	return 0;
}