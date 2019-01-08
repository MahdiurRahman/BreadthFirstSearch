#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bfs.h"
using namespace std;

//NOTE: ftream files must be passed by reference
//vector<string> create_list(ifstream &file)
//{
//	string word;
//	vector<string> word_list;
//	while (file >> word)
//	{
//		word_list.push_back(word);
//	}
//	return word_list;
//}

//void display_vector(vector<string> vector_object)
//{
//	for (int i = 0; i < int(vector_object.size()); i++)
//	{
//		cout << vector_object[i] << ' ';
//	}
//	cout << endl;
//}

int main()
{
	bfs word_solver("4LetterWordsReduced.dat");
	vector<word> solution = word_solver.getPath("dare", "make");
	for (int i = int(solution.size()) - 1; i < -1; i--)
	{
		cout << solution[i].getValue() << "-> ";
	}

	//PAUSE
		cout << endl << endl;
		system("pause;");
		return 0;
}