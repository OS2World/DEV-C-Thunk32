CC= gcc -Zomf
DEB= -g
CFLAGS= $(DEB) #-O3 -m486
LD= $(CC)
LDFLAGS= $(DEB) -Zlinker "/MAP:FULL" -Zmap -Zno-rte -Zdll -lsyslib -lcall32

.c.obj:
        $(CC) $(CFLAGS) -c $<

.asm.obj:
        alp -Fl+ -M:STA $<

all: test16.exe call32.lib test32.dll 


ASM32OBJ= \
call1632.obj 

call32.lib: $(ASM32OBJ)
        emxomfar r $@ $(ASM32OBJ)

DLL= \
test32.obj \
test32Thunks.obj \
test16Thunks.obj 

test32.def:
	echo LIBRARY TEST32 INITINSTANCE TERMINSTANCE >$@
	echo PROTMODE >>$@
	echo DATA MULTIPLE >>$@
	echo EXPORTS >>$@
	echo   FUNC1 >>$@
	echo   _16_FUNC1 = FUNC1 >>$@
	

test32.dll: call32.lib  $(DLL) test32.def
	$(LD) $(LDFLAGS) -Zmap $(DLL) test32.def -o $@
	emximp -o test32.lib test32.def


test16.exe: test16.c test32.dll
#	icc /Ti test32.lib test16.c 
#	wcl /I%%WATCOM%%\h /bt=os2 test16.c test32.lib /k8000
	gcc -Zomf -Zsys -g test16.c -ltest32 -o $@


clean:
	-del *.lst *.obj *.map *.exe *.dll *.lib