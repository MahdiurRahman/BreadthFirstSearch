#ifndef WORD_
#define WORD_
#include <string>
using namespace std;

class word
{
public:
	word() : value_{ "four" }, ptr_parent_{ nullptr } {};
	word(string a, word* ptr) : value_{ a }, ptr_parent_{ ptr } {};

	word* getPointer() { return ptr_parent_; };
	string& getValue() { return value_; };

	void setPointer(word* ptr_) { ptr_parent_ = ptr_; };
	void setValue(string a_) { value_ = a_; };

	~word() {};
	
private:
	word* ptr_parent_ = nullptr;
	string value_ = "four";
};


#endif // !WORD_