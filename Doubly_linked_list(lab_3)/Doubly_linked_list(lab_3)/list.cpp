#include "list.h"
using�lass::using�lass(int Int, std::string String)
{
	this->Int = Int;
	this->String = String;
}

int using�lass::getInt() const
{
	return this->Int;
}

std::string using�lass::getString() const
{
	return this->String;
}

ostream& operator<<(ostream& os, const using�lass& op)
{
	os << op.getInt() << std::endl;
	os << op.getString() << std::endl;
	return os;
}
