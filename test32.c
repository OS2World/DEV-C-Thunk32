#define INCL_BASE
#include <os2.h>
#include <call32.h>

unsigned long _DLL_InitTerm(unsigned long hModule, unsigned long reason)
{
switch (reason) {
   case 0:
      break;
   case 1:
      break;
   default:
      return 0;
}
return 1;
}

