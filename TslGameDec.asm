EXTERN  Aimbot_sw : DQ; �����ⲿ����
EXTERN  Aimbot_x : DQ; �����ⲿ����
EXTERN  Aimbot_y : DQ; �����ⲿ���� 
EXTERN  Aimbot_z : DQ; �����ⲿ���� 
EXTERN  HookSilenceAimBotReturn : DQ; �����ⲿ����
EXTERN  HookTurnBulletReturn : DQ; �����ⲿ����

EXTERN  HookAtanfReturn : DQ; �����ⲿ����
EXTERN  JmpAtanfAddress : DQ; �����ⲿ����





.CODE



Dec_PUBG PROC
push rbx
push rsi
push rdi
push r10
push r11
push r12
push r13
push r14
push r15
call qword ptr [r8]
pop r15
pop r14
pop r13
pop r12
pop r11
pop r10
pop rdi
pop rsi
pop rbx
ret
Dec_PUBG ENDP
END

