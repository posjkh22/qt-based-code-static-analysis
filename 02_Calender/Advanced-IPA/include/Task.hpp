
#ifndef IPATASK
#define IPATASK

#include <list>
#include "wFunction.hpp"
#include "wBasicBlock.hpp"
#include "PathImpl.hpp"
#include "Path.hpp"

class wFunction;
class wBasicBlock;
class PathImpl;
class Path;

namespace IPA
{

typedef std::list<wFunction* > FunctionListTy;
typedef std::list<wFunction* > NonRetrantFunctionListTy;
typedef wFunction EntryFunctionTy;
typedef std::list<llvm::Value* > SemaphoreValueListTy;


typedef std::list<Path *> PathListTy;


class Task
{

private:
	IPA::SymbolManager* p_symbolManager;

public:
	Task(EntryFunctionTy*, SymbolManager* );

	bool Process();

private:
	EntryFunctionTy* m_entryFunction;

public:
	bool SetEntryFunction(EntryFunctionTy* );
	EntryFunctionTy* GetEntryFunction();

public:
	std::string getTaskName();

private:
	PathListTy* m_pathList;

public:
	bool GeneratePathList();
	PathListTy* getPathList();



private:
	FunctionListTy m_FunctionList;
	NonRetrantFunctionListTy m_NonRFL;
	SemaphoreValueListTy m_DSVL;
	SemaphoreValueListTy m_LSVL;
	SemaphoreValueListTy m_USVL;

public:
	bool DetermineFunctionList();
	bool DetermineNonRFL();
	bool DetermineSemaphoreVariableList();
	bool ShowFunctionList();
	bool ShowNonRFL();
	bool ShowNonRFL(const char*);


};

/*
class TaskCreator
{

public:
	TaskCreator(Task* , EntryFunctionTy* );
	~TaskCreator();

};
*/
};

#endif