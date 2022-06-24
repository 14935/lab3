#ifndef MY_CLASS2_H 
#define MY_CLASS2_H
#include <iostream>
#include <string>
#include <sstream>
#include <complex>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "bintree.h"
template<typename T>
class Set
{
private:
	BinaryTree<T>* set;
public:
	Set()
	{
		this->set = new BinaryTree<T>();
	}
	~Set()
	{
		delete this->set;
	}
	void Push(T data)
	{
		this->set->push(data);
	}
	bool Search(T data)
	{
		return this->set->Search(data);
	}
	void Delete(T data)
	{
		this->set->DeleteElem(data);
	}
	Set* Map(T(*mapFunc)(T))
	{
		Set<T>* newSet = new Set<T>();
		delete newSet->set;
		newSet->set = this->set->Map(mapFunc);
		return newSet;
	}
	Set* Where(bool (*whereFunc)(T))
	{
		Set<T>* newSet = new Set<T>();
		delete newSet->set;
		newSet->set = this->set->Where(whereFunc);
		return newSet;
	}
	T Reduce(T(*reduceFunc)(T, T), T initval)
	{
		return this->set->Reduce(reduceFunc, initval);
	}
	Set* Merge(Set<T>* onemoreSet)
	{
		Set<T>* newSet = new Set<T>();
		delete newSet->set;
		newSet->set = this->set->Merge(onemoreSet->set);
		return newSet;
	}
	Set* Cross(Set<T>* onemoreSet)
	{
		Set<T>* newSet = new Set<T>();
		delete newSet->set;
		newSet->set = this->set->Cross(onemoreSet->set);
		return newSet;
	}
	Set* Subtr(Set<T>* onemoreSet)
	{
		Set<T>* newSet = new Set<T>();
		delete newSet->set;
		newSet->set = this->set->Subtr(onemoreSet->set);
		return newSet;
	}
	string Out()
	{
		return this->set->TreeToString("LKP");
	}
	bool IsSetEq(Set<T>* onemoreSet)
	{
		return this->set->IsTreeEq(onemoreSet->set);
	}
	bool IsSetSub(Set<T>* onemoreSet)
	{
		return this->set->IsSetOfTreeSub(onemoreSet->set);
	}
};
#endif