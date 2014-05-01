         .386
         .387

TEXT32   SEGMENT USE32 PUBLIC DWORD 'CODE'
         ASSUME CS:FLAT,ES:NOTHING,DS:NOTHING
         EXTERN Thunk_Func1:BYTE
         EXTERN _Call32:PROC
TEXT32   ENDS


TEXT16   SEGMENT USE16 PUBLIC PARA 'CODE'
         ASSUME CS:TEXT16
         PUBLIC FUNC1
FUNC1    PROC FAR
         mov ebx,3*4
         mov edx,offset FLAT:Thunk_Func1
         jmp far ptr FLAT:_Call32
         retf 3*4
FUNC1    ENDP


TEXT16   ENDS

END
