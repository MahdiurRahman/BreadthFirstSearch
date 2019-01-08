#include "word.h"

word::word()
{
	ptr_parent = nullptr;
	value = "four";
}

word::word(string a, word* ptr)
{
	ptr_parent = ptr;
	value = a;
}

word* word::getPointer()
{
	return ptr_parent;
}

void word::setPointer(word* ptr_)
{
	ptr_parent = ptr_;
}

string word::getValue()
{
	return value;
}

void word::setValue(string a_)
{
	value = a_;
}

word::~word()
{

}