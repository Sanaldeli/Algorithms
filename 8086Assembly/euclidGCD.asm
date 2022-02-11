MYCS SEGMENT PARA 'CDSG'
    ORG 100H
    ASSUME SS:MYCS, DS:MYCS, CS:MYCS
    
    MAIN PROC NEAR
        MOV BX, NUM1
        MOV CX, NUM2
        CMP CX, 0
        JZ EXIT
        
GCDLOOP:
        XOR DX, DX
        MOV AX, BX
        DIV CX
        MOV BX, CX
        MOV CX, DX
        CMP CX, 0
        JNZ GCDLOOP
EXIT:
        MOV FOUNDGCD, BX
        
        RET
    MAIN ENDP
    
    NUM1        DW  192
    NUM2        DW  18
    FOUNDGCD    DW  0
    
MYCS ENDS
    END MAIN