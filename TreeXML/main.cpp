#include <iostream>
#include "TreeForXML.h"

using namespace std;

int main()
{
	TreeForXML* TXML = new TreeForXML("../../../tree.xml");
	
	TXML->print();

	delete TXML;

	return 0;
}
