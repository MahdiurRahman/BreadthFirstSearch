#ifndef WORDLADDER_
#define WORDLADDER_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "word.h"
using namespace std;

//bfs stands for breadth first search

class bfs
{
public:
	bfs();
	bfs(string file_name);
	bool loadData(string file_name);
	vector<word> getPath(string current, string target);
	
private:
	int size = 4;
	word* ptr_to_parent = nullptr;
	ifstream infile;
	vector<word> whole_list;
	vector<word> que_list;
	vector<word> path;

	bool existsInList(string a, string b);
	void add_similar(string a);
	void setPointerToWord(string word_);
	bool is_similar(string a, string b);
	bool already_qued(string a);
	void generate_path(word target_found);
	void displayWhole();
	void displayQue();
	void displayPath();

	void clear();
};


#endif