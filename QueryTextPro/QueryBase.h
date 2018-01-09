#include <string>
#include "QueryResult.h"
#include "TextQuery.h"

class QueryBase
{
	friend class Query;
protected:
	virtual ~QueryBase() = default;
private:
	// eval返回与TextQuery匹配的QueryResult
	virtual QueryResult eval(const TextQuery &) const = 0;
	// rep是表示查询的一个string
	virtual std::string rep() const = 0;
};

