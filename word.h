#ifndef WORD_
#define WORD_
#include <string>
using namespace std;

class word
{
public:
	word();
	word(string a, word* ptr);
	word* getPointer();
	void setPointer(word* ptr_);
	string getValue();
	void setValue(string a_);

	~word();
	
private:
	word* ptr_parent = nullptr;
	string value = "four";
};


#endif // !WORD_