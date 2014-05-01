#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <os2thunk.h>

#if defined (__IBMC__)
extern unsigned long _Far16 _Pascal FUNC1
   (char * _Seg16 f1, char * _Seg16 f2, unsigned long f3);
#endif
#if defined (__WATCOMC__)
extern unsigned long _far _pascal FUNC1
   (char far* f1, char far* f2, unsigned long f3);
#endif

#if defined (__GNUC__)

unsigned long
_THUNK_PASCAL_FUNCTION (FUNC1) (char* f1, char* f2,unsigned long f3);

/*
  build an interface between the calling programm and the thunk function
*/

unsigned long _FUNC1(char* f1, char* f2 ,unsigned long f3)
{
   return((unsigned long)
      (_THUNK_PASCAL_PROLOG(3*sizeof(unsigned long));
       _THUNK_PASCAL_FLAT(f1);
       _THUNK_PASCAL_FLAT(f2);
       _THUNK_PASCAL_LONG(f3);
       _THUNK_PASCAL_CALL(FUNC1)));
}

#endif


int main()
{
   int x;
   char f1[256];
   char f2[256];
strcpy(f1,"Das ist ein Test");
f2[0]=0;
#if !defined (__GNUC__)
printf("Result from FUNC1: %08lx\n",FUNC1(f1,f2,256));
#else
printf("Result from FUNC1: %08lx\n",_FUNC1(f1,f2,256));
#endif
printf("f2: %s\n",f2);
return 0;
}

