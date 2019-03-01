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
	bfs() : word_size_{ 4 }, ptr_to_parent_{ nullptr } {};
	bfs(string file_name);
	bool loadData(string file_name);
	vector<string> getPath(string current, string target);
	void displayPath();
	
private:
	size_t word_size_ = 4;
	word* ptr_to_parent_ = nullptr;
	ifstream infile_;
	vector<word> whole_list_;
	vector<word*> queue_;
	vector<string> path_;

	bool existInList(string& current, string & target);
	void addChildrenToQueue(word* front_of_queue);
	bool isSimilar(string& a, string& b);
	bool alreadyQueued(string& a);

	void clear();
};


#endif