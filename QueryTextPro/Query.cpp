#include "Query.h"

std::ostream &
operator<<(std::ostream os, const Query &q)
{
	//����ֵΪstd::ostream &����
	return os << q.rep();
}