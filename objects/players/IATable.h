#ifndef IATABLE_H_
#define IATABLE_H_

#include "../TableBase.h"

class AITable : public TableBase{
public:

	AITable();

	AITable(TableBase &t);

	AITable(AITable &t);

};

#endif
