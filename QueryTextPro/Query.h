#include <string>
#include <memory>
#include "QueryBase.h"
#include "QueryResult.h"
#include "TextQuery.h"

class Query
{
	//����������Ҫ����private�Ĺ��캯��������Ҫ������friend
	friend Query operator~(const Query&);
	friend Query operator&(const Query&, const Query&);
	friend Query operator|(const Query&, const Query&);
public:
	// ��string����һ���µ�WordQuery
	Query(const std::string&);
	// ����������������QueryBaseָ������̬�󶨵Ķ���Ķ�Ӧ����
	QueryResult eval(const TextQuery &tq) const
	{
		return qbPtr->eval(tq);
	}
	std::string rep() const { return qbPtr->rep(); }
private:
	// ����Ϊ˽�е���ʹһ����û����벻����㶨��QueryBase�Ķ���
	Query(std::shared_ptr<QueryBase> qbp) : qbPtr(qbp) { }
	std::shared_ptr<QueryBase> qbPtr;
};

