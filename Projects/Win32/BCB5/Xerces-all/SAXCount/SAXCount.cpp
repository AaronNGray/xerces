
#pragma hdrstop
#include <condefs.h>

//---------------------------------------------------------------------------
USELIB("..\..\..\..\..\Build\Win32\BCB5\XercesLib.lib");
USEUNIT("..\..\..\..\..\samples\SAXCount\SAXCountHandlers.cpp");

//---------------------------------------------------------------------------

#ifdef NEVER_COMPILE
// Dummy entry point to satisfy the BCB IDE
int main(int argc, char* argv[])
{
	return 0;
}
#endif

// The real entry point is in the Samples folder
#include <SAXCount.cpp>
