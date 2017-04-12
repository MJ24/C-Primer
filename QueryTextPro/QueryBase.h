#include <string>
#include "QueryResult.h"
#include "TextQuery.h"

class QueryBase
{
	friend class Query;
protected:
	virtual ~QueryBase() = default;
private:
	// eval������TextQueryƥ���QueryResult
	virtual QueryResult eval(const TextQuery &) const = 0;
	// rep�Ǳ�ʾ��ѯ��һ��string
	virtual std::string rep() const = 0;
};

