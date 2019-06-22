#include "FakeSteamAPI_Utilities.h"

#include <Windows.h>

#include "FakeSteamAPI_LogSys.h"

void (__stdcall *g_RtlGetCallersAddress)(void **CallersAddress, void **CallersCaller) = nullptr;

bool FakeSteamAPI_GetEIP(void *&ptr) {
	void *p1, *p2;
	if (g_RtlGetCallersAddress == nullptr)
		g_RtlGetCallersAddress = (decltype(g_RtlGetCallersAddress))GetProcAddress(GetModuleHandleA("ntdll.dll"), "RtlGetCallersAddress");
	if (g_RtlGetCallersAddress == nullptr)
		return false;
	g_RtlGetCallersAddress(&p1, &p2);
	ptr = p2;
	return true;
}

void* FakeSteamAPI_GetEIP(void) {
	void *p1, *p2;
	if (g_RtlGetCallersAddress == nullptr)
		g_RtlGetCallersAddress = (decltype(g_RtlGetCallersAddress))GetProcAddress(GetModuleHandleA("ntdll.dll"), "RtlGetCallersAddress");
	if (g_RtlGetCallersAddress == nullptr)
		return nullptr;
	g_RtlGetCallersAddress(&p1, &p2);
	//FakeSteamAPI_AppendLog(LogLevel_Debug, "p1 = 0x%08X, p2 = 0x%08X", (int)p1, (int)p2);
	return p2;
}

void* FakeSteamAPI_GetEIP0(void) {
	void *p1, *p2;
	if (g_RtlGetCallersAddress == nullptr)
		g_RtlGetCallersAddress = (decltype(g_RtlGetCallersAddress))GetProcAddress(GetModuleHandleA("ntdll.dll"), "RtlGetCallersAddress");
	if (g_RtlGetCallersAddress == nullptr)
		return nullptr;
	g_RtlGetCallersAddress(&p1, &p2);
	return p1;
}

void* FakeSteamAPI_GetEIP1(void) {
	void *p1, *p2;
	if (g_RtlGetCallersAddress == nullptr)
		g_RtlGetCallersAddress = (decltype(g_RtlGetCallersAddress))GetProcAddress(GetModuleHandleA("ntdll.dll"), "RtlGetCallersAddress");
	if (g_RtlGetCallersAddress == nullptr)
		return nullptr;
	g_RtlGetCallersAddress(&p1, &p2);
	return p2;
}