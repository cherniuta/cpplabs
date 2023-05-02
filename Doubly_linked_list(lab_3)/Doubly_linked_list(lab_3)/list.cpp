#include "list.h"
usingÑlass::usingÑlass(int Int, std::string String)
{
	this->Int = Int;
	this->String = String;
}

int usingÑlass::getInt() const
{
	return this->Int;
}

std::string usingÑlass::getString() const
{
	return this->String;
}

ostream& operator<<(ostream& os, const usingÑlass& op)
{
	os << op.getInt() << std::endl;
	os << op.getString() << std::endl;
	return os;
}
