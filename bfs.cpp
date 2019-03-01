#include "bfs.h"

bfs::bfs(string file_name)
{
	infile_.open(file_name);
	string dummy_string;
	word dummy_word;
	while (infile_ >> dummy_string)
	{
		dummy_word.setValue(dummy_string);
		whole_list_.push_back(dummy_word);
	}
	//displayWhole();
}

bool bfs::loadData(string file_name)
{
	clear();
	infile_.open(file_name);
	if (!infile_.is_open())
	{
		return false;
	}

	word dummy_word;
	string dummy_string;
	while (infile_ >> dummy_string)
	{
		dummy_word.setValue(dummy_string);
		whole_list_.push_back(dummy_word);
	}

	if (whole_list_.size() != 0)
	{
		return true;
	}
	return false;
}

void bfs::displayPath()
{
	cout << "Path length is: " << path_.size() << endl;
	for (size_t i = path_.size() - 1; i > 0; i--)
	{
		cout << path_[i] << " -> ";
	}
	cout << path_[0] << endl;
}

vector<string> bfs::getPath(string current, string target)
{
	//check to make sure current and target are both in whole_list_
		//if so, make current point to null 
		//and add it to queue_
	if (!existInList(current, target))
	{
		return path_;
	}

	//create 'i' and set to 0. i will be our iterator
	//while queue_[i] != target:
		//add words to queue_ which are 
			//1 letter away from queue_[i]
			//AND
			//not already in queue_
		//each time a word is added to queue, make it's pointer component point to queue_[i]
		//iterate i: i++
	size_t i = 0;
	while (queue_[i]->getValue() != target)
	{
		addChildrenToQueue(queue_[i]);
		i++;
	}
	
	//if the while-loop-check fails, you know you've found your target!
	//create path_ptr (a word pointer), set it equal to queue_[i]
	//while path_ptr->ptr_parent != nullptr:
		//add path_ptr->value_ to path_
		//then make path_ptr = path_ptr->ptr_parent_
	word* path_ptr = queue_[i];
	while (path_ptr->getPointer() != nullptr)
	{
		path_.push_back(path_ptr->getValue());
		path_ptr = path_ptr->getPointer();
	}
	path_.push_back(path_ptr->getValue());

	return path_;
}

bool bfs::existInList(string& current, string& target)
{
	bool current_{ false }, target_{ false };

	for (int i = 0; i < whole_list_.size(); i++)
	{
		if (whole_list_[i].getValue() == current)
		{
			whole_list_[i].setPointer(nullptr);
				//once current is found, its pointer is set to null
			queue_.push_back(&whole_list_[i]);
				//and it's addresses is added to queue_

			current_ = true;
		}
		else if (whole_list_[i].getValue() == target)
		{
			target_ = true;
		}
	}

	if (current_ and target_)
	{
		return true;
	}
	return false;
}


void bfs::addChildrenToQueue(word* front_of_queue)
{
	for (size_t i = 0; i < whole_list_.size(); i++)
	{
		if ((isSimilar(whole_list_[i].getValue(), front_of_queue->getValue())) && (!alreadyQueued(whole_list_[i].getValue())))
		{
			whole_list_[i].setPointer(front_of_queue);
			queue_.push_back(&whole_list_[i]);
		}
	}
}

bool bfs::isSimilar(string& a, string& b)
{
	int similar_letters = 0;
	for (size_t i = 0; i < word_size_; i++)
	{
		if (a[i] != b[i])
		{
			similar_letters++;
		}
	}

	if (similar_letters == 1)
	{
		return true;
	}
	return false;
}

bool bfs::alreadyQueued(string& a)
{
	for (size_t i = 0; i < queue_.size(); i++)
	{
		if (queue_[i]->getValue() == a)
		{
			return true;
		}
	}
	return false;
}

void bfs::clear()
{
	whole_list_.clear();
	queue_.clear();
	path_.clear();
	infile_.clear();
}