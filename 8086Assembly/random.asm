MYCS SEGMENT PARA 'CDSG'
    ORG 100H
    ASSUME SS:MYCS, DS:MYCS, CS:MYCS
    MAIN PROC NEAR
        MOV CX, 32
        XOR SI, SI
        MOV AX, 0F0E2H
L1:
        PUSH AX
        CALL RANDOM
        MOV NUMBER[SI], DX
        ADD SI, 2
        LOOP L1
        RET
    MAIN ENDP
    
    X       DW  0
    NUMBER  DW  32 DUP (?)
    
    RANDOM PROC NEAR
        ;   yığındaki tek parametre seed'i belirler
        ;   döndürdüğü BX değeri seed'e göre bir random sayı
        PUSH BP
        MOV BP, SP
        PUSH AX
        PUSH BX
        
        MOV AX, X
        ADD AX, 0A3H
        MOV X, AX
        XOR DX, DX
        MOV BX, [BP + 4]
        DIV BX
        
        POP BX
        POP AX
        POP BP
        RET 2
    RANDOM ENDP
MYCS ENDS
    END MAIN