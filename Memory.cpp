#include <Windows.h>
#include "Memory.h"

#include "DriverIO.h"

int FuncIndex = 0;

ULONG Mem::NtReadVirtualMemoryIndex = 0,
Mem::NtUserCreateFile,
Mem::NtWriteVirtualMemoryIndex = 0, //���� �ո���TM�Ҹķɳ� ��asm��û�ˡ�����
Mem::NtProtectVirtualMemoryIndex = 0,
Mem::NtUserSendInputIndex = 0,
Mem::NtUserGetAsyncKeyStateIndex = 0,
Mem::NtUserSetWindowDisplayAffinityIndex = 0;

bool Mem::ReadMemory(__int64 ptr, void* buff, size_t size)
{
	if ((ptr > 0x1000000 - 0x8) || (ptr < 0x7FFFFFF00000 + 0x8))
	{
		/*	if (Asm_IsReadPtr((void*)ptr, size) == 0) {*/
		Asm_CopyMemory(buff, (void*)ptr, size);
		return true;
		//	}
		/*	else {
				Asm_ZeroMemory(buff, size);
			}*/
	}
	return false;
}

//bool Mem::WriteMemory(__int64 ptr, void* buff, size_t size)
//{
//	if ((ptr > 0x1000000 - 0x8) || (ptr < 0x7FFFFFF00000 + 0x8)) {
//		if (Asm_IsReadPtr((void*)ptr, sizeof(size)) == 0) {
//			Asm_CopyMemory((void*)ptr, buff, size);
//			return true;
//		}
//	}
//	return false;
//}

//���������  �ҷ�װ����  �÷���֮ǰһ��  ��������ķ����ģ�� ���� ��Ϸ�������Ա����
BOOL Mem::DriverWrite(ULONG64 BaseAddress, PVOID buffer, ULONG size)
{
	if (FIO::CheckDrvStatus()) {
		FIO::PID = GetCurrentProcessId();
		FIO::Write(BaseAddress, buffer, size);
		FIO::CloseDrv();
		return TRUE;
	}
	return FALSE;
}



BOOL Mem::NtUserSetWindowDisplayAffinity(HWND  hWnd, DWORD dwAffinity) {
	FuncIndex = NtUserSetWindowDisplayAffinityIndex;
	return (BOOL)Asm_SysCall(hWnd, dwAffinity);
}


SHORT Mem::NtUserGetAsyncKeyState(DWORD key) {
	FuncIndex = NtUserGetAsyncKeyStateIndex;
	return (SHORT)Asm_SysCall(key);
}


DWORD Mem::NtUserSendInput(UINT cInputs, LPINPUT pInputs, int cbSize) {
	FuncIndex = NtUserSendInputIndex;
	return (DWORD)Asm_SysCall(cInputs, pInputs, cbSize);
}






