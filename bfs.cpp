#include "bfs.h"

bfs::bfs()
{
	return;
}

bfs::bfs(string file_name)
{
	infile.open(file_name);
	string dummy_string;
	word dummy_word;
	while (infile >> dummy_string)
	{
		dummy_word.setValue(dummy_string);
		whole_list.push_back(dummy_word);
	}
	//displayWhole();
}

bool bfs::loadData(string file_name)
{
	clear();
	infile.open(file_name);
	if (!infile.is_open())
	{
		return false;
	}

	string dummy_string;
	word dummy_word;
	while (infile >> dummy_string)
	{
		dummy_word.setValue(dummy_string);
		whole_list.push_back(dummy_word);
	}

	if (whole_list.size() != 0)
	{
		return true;
	}
	return false;
}

vector<word> bfs::getPath(string current, string target)
{
	//check if current and target are in whole_list
	if (!existsInList(current, target))
	{
		cout << "\n\n" << current << " and " << target << " don't exist in the data.";
		return path;
	}

	setPointerToWord(current);
	add_similar(current);

	//iterate through que
		//if word = target, return path
		//else if not then find similar words to current iteration, add to que
	int i = 0;
	displayQue();
	cout << endl << que_list[0].getPointer();
	cout << endl << (*que_list[0].getPointer()).getValue();
	cout << endl << (*que_list[0].getPointer()).getPointer() << endl << endl;

	while (que_list[i].getValue() != target)
	{
		cout << endl << que_list[i].getValue() << ' ' << i;
		ptr_to_parent = &que_list[i];
		cout << endl << ptr_to_parent << ' ' << i;
		cout << endl << (*ptr_to_parent).getPointer() << ' ' << i;
		add_similar(que_list[i].getValue());
		i++;
	}
	
	//generate and display path
	generate_path(que_list[i]);
	displayPath();
	return path;
}

bool bfs::existsInList(string a, string b)
{
	//cout << "\n\nfunction: existsInList(" << a << ", " << b << ")";
	int current_ = 0;
	int target_ = 0;

	for (int i = 0; i < int(whole_list.size()); i++)
	{
		if (whole_list[i].getValue() == a)
		{
			current_++;
		}
		else if (whole_list[i].getValue() == b)
		{
			target_++;
		}
	}

	if ((current_ != 0) and (target_ != 0))
	{
		//cout << "\nresult: true";
		return true;
	}
	//cout << "\nresult: false";
	return false;
}


void bfs::add_similar(string a)
{
	//cout << "\n\nfunction: add_similar(" << a << ")";
	for (int i = 0; i < int(whole_list.size()); i++)
	{
		if (is_similar(a, whole_list[i].getValue()) and (!already_qued(whole_list[i].getValue())))
		{
			que_list.push_back(whole_list[i]);
			que_list[que_list.size() - 1].setPointer(ptr_to_parent);
		}
	}
	//displayQue();
}

	void bfs::setPointerToWord(string word_)
	{
		//cout << "\n\nfunction: setPointerToWord(" << word_ << ")";
		for (int i = 0; i < int(whole_list.size()); i++)
		{
			if (whole_list[i].getValue() == word_)
			{
				ptr_to_parent = &whole_list[i];
			}
		}
	}

	bool bfs::is_similar(string a, string b)
	{
		//cout << "\n\nfunction: is_similar(" << a << ", " << b << ")";
		int x = 0;

		for (int i = 0; i < size; i++)
		{
			if (a[i] != b[i])
			{
				x++;
			}
		}

		if (x == 1)
		{
			//cout << "\nresult: true";
			return true;
		}
		//cout << "\nresult: false";
		return false;
	}

	bool bfs::already_qued(string a)
	{
		//cout << "\n\nfunction: already_qued(" << a << ")";
		for (int i = 0; i < int(que_list.size()); i++)
		{
			if (que_list[i].getValue() == a)
			{
				//cout << "\nresult: true";
				return true;
			}
		}
		//cout << "\nresult: false";
		return false;
	}


void bfs::generate_path(word target_found)
{
	cout << "\n\nfunction: generate_path(" << target_found.getValue() << ")";

	ptr_to_parent = &target_found;
	while ((*ptr_to_parent).getPointer() != nullptr)
	{
		path.push_back((*ptr_to_parent));
		cout << endl << (*ptr_to_parent).getValue();
		cout << endl << (*ptr_to_parent).getPointer();
		ptr_to_parent = (*ptr_to_parent).getPointer();
	}
}

void bfs::displayWhole()
{
	for (int i = 0; i < whole_list.size(); i++)
	{
		cout << endl << whole_list[i].getValue();
	}
	cout << endl << "\n\nWHOLE size is: " << whole_list.size();
}

void bfs::displayQue()
{
	for (int i = 0; i < que_list.size(); i++)
	{
		cout << endl << que_list[i].getValue();
	}
	cout << endl << "\n\nQUE size is: " << que_list.size();
}

void bfs::displayPath()
{
	for (int i = 0; i < int(path.size()); i++)
	{
		cout << endl << path[i].getValue();
	}
	cout << endl << "\n\nPATH size is: " << path.size();
}

void bfs::clear()
{
	whole_list.clear();
	que_list.clear();
	path.clear();
	infile.clear();
}