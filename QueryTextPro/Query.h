#include <string>
#include <memory>
#include "QueryBase.h"
#include "QueryResult.h"
#include "TextQuery.h"

class Query
{
	//这三个函数要调用private的构造函数，所以要声明成friend
	friend Query operator~(const Query&);
	friend Query operator&(const Query&, const Query&);
	friend Query operator|(const Query&, const Query&);
public:
	// 从string创建一个新的WordQuery
	Query(const std::string&);
	// 下面两个函数调用QueryBase指针所动态绑定的对象的对应函数
	QueryResult eval(const TextQuery &tq) const
	{
		return qbPtr->eval(tq);
	}
	std::string rep() const { return qbPtr->rep(); }
private:
	// 声明为私有的以使一般的用户代码不能随便定义QueryBase的对象
	Query(std::shared_ptr<QueryBase> qbp) : qbPtr(qbp) { }
	std::shared_ptr<QueryBase> qbPtr;
};

