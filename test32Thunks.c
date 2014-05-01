#define INCL_BASE
#include <os2.h>

#include <inlines.h>
#include <sysos2.h>
#include <string.h>

unsigned Func1(char* f1, char* f2, unsigned f3)
{
nPrintf(1,"Func1:\r\n");
nPrintf(1,"*f1: %s\r\n",f1);
nPrintf(1,"*f2: %s\r\n",f2);
nPrintf(1,"f3 : %08lx\r\n",f3);
strncpy(f2,f1,f3);
return strlen(f2);
}

unsigned Thunk_Func1(void* args)
{
   char* f1;
   char* f2;
   unsigned f3;
   unsigned long* h= (unsigned long*)args;
   int i;
f1= (char*) SelToFlat( h[2]);
f2= (char*) SelToFlat( h[1]);
f3= h[0];
return Func1(f1,f2,f3);
}
