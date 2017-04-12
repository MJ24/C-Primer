#include "Query.h"

std::ostream &
operator<<(std::ostream os, const Query &q)
{
	//返回值为std::ostream &类型
	return os << q.rep();
}