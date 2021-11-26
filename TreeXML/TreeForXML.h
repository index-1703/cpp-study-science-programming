#pragma once
#include "Tree.h"
#include "XMLReader.h"

class TreeForXML
	:public Tree, private XMLReader
{
public:
	TreeForXML() = default;
	TreeForXML(const char* nameFile);
	~TreeForXML() = default;

	void createTreeForXML(const char* nameFile);
};