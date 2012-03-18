// pname 1.0
// Copyright (c) 2012 Petroules Corporation. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
// ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Resources used:
// http://msdn.microsoft.com/en-us/library/windows/desktop/ms724429.aspx
// http://msdn.microsoft.com/en-us/library/windows/desktop/ms724833.aspx

#include <windows.h>
#include <stdio.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "version.lib")

#ifndef VER_SERVER_NT
#define VER_SERVER_NT                       0x80000000
#endif
#ifndef VER_WORKSTATION_NT
#define VER_WORKSTATION_NT                  0x40000000
#endif
#ifndef VER_SUITE_SMALLBUSINESS
#define VER_SUITE_SMALLBUSINESS             0x00000001
#endif
#ifndef VER_SUITE_ENTERPRISE
#define VER_SUITE_ENTERPRISE                0x00000002
#endif
#ifndef VER_SUITE_BACKOFFICE
#define VER_SUITE_BACKOFFICE                0x00000004
#endif
#ifndef VER_SUITE_COMMUNICATIONS
#define VER_SUITE_COMMUNICATIONS            0x00000008
#endif
#ifndef VER_SUITE_TERMINAL
#define VER_SUITE_TERMINAL                  0x00000010
#endif
#ifndef VER_SUITE_SMALLBUSINESS_RESTRICTED
#define VER_SUITE_SMALLBUSINESS_RESTRICTED  0x00000020
#endif
#ifndef VER_SUITE_EMBEDDEDNT
#define VER_SUITE_EMBEDDEDNT                0x00000040
#endif
#ifndef VER_SUITE_DATACENTER
#define VER_SUITE_DATACENTER                0x00000080
#endif
#ifndef VER_SUITE_SINGLEUSERTS
#define VER_SUITE_SINGLEUSERTS              0x00000100
#endif
#ifndef VER_SUITE_PERSONAL
#define VER_SUITE_PERSONAL                  0x00000200
#endif
#ifndef VER_SUITE_BLADE
#define VER_SUITE_BLADE                     0x00000400
#endif
#ifndef VER_SUITE_EMBEDDED_RESTRICTED
#define VER_SUITE_EMBEDDED_RESTRICTED       0x00000800
#endif
#ifndef VER_SUITE_SECURITY_APPLIANCE
#define VER_SUITE_SECURITY_APPLIANCE        0x00001000
#endif
#ifndef VER_SUITE_STORAGE_SERVER
#define VER_SUITE_STORAGE_SERVER            0x00002000
#endif
#ifndef VER_SUITE_COMPUTE_SERVER
#define VER_SUITE_COMPUTE_SERVER            0x00004000
#endif
#ifndef VER_SUITE_WH_SERVER
#define VER_SUITE_WH_SERVER                 0x00008000
#endif

#ifndef PRODUCT_UNDEFINED
#define PRODUCT_UNDEFINED                           0x00000000
#endif

#ifndef PRODUCT_ULTIMATE
#define PRODUCT_ULTIMATE                            0x00000001
#endif
#ifndef PRODUCT_HOME_BASIC
#define PRODUCT_HOME_BASIC                          0x00000002
#endif
#ifndef PRODUCT_HOME_PREMIUM
#define PRODUCT_HOME_PREMIUM                        0x00000003
#endif
#ifndef PRODUCT_ENTERPRISE
#define PRODUCT_ENTERPRISE                          0x00000004
#endif
#ifndef PRODUCT_HOME_BASIC_N
#define PRODUCT_HOME_BASIC_N                        0x00000005
#endif
#ifndef PRODUCT_BUSINESS
#define PRODUCT_BUSINESS                            0x00000006
#endif
#ifndef PRODUCT_STANDARD_SERVER
#define PRODUCT_STANDARD_SERVER                     0x00000007
#endif
#ifndef PRODUCT_DATACENTER_SERVER
#define PRODUCT_DATACENTER_SERVER                   0x00000008
#endif
#ifndef PRODUCT_SMALLBUSINESS_SERVER
#define PRODUCT_SMALLBUSINESS_SERVER                0x00000009
#endif
#ifndef PRODUCT_ENTERPRISE_SERVER
#define PRODUCT_ENTERPRISE_SERVER                   0x0000000A
#endif
#ifndef PRODUCT_STARTER
#define PRODUCT_STARTER                             0x0000000B
#endif
#ifndef PRODUCT_DATACENTER_SERVER_CORE
#define PRODUCT_DATACENTER_SERVER_CORE              0x0000000C
#endif
#ifndef PRODUCT_STANDARD_SERVER_CORE
#define PRODUCT_STANDARD_SERVER_CORE                0x0000000D
#endif
#ifndef PRODUCT_ENTERPRISE_SERVER_CORE
#define PRODUCT_ENTERPRISE_SERVER_CORE              0x0000000E
#endif
#ifndef PRODUCT_ENTERPRISE_SERVER_IA
#define PRODUCT_ENTERPRISE_SERVER_IA64              0x0000000F
#endif
#ifndef PRODUCT_BUSINESS_N
#define PRODUCT_BUSINESS_N                          0x00000010
#endif
#ifndef PRODUCT_WEB_SERVER
#define PRODUCT_WEB_SERVER                          0x00000011
#endif
#ifndef PRODUCT_CLUSTER_SERVER
#define PRODUCT_CLUSTER_SERVER                      0x00000012
#endif
#ifndef PRODUCT_HOME_SERVER
#define PRODUCT_HOME_SERVER                         0x00000013
#endif
#ifndef PRODUCT_STORAGE_EXPRESS_SERVER
#define PRODUCT_STORAGE_EXPRESS_SERVER              0x00000014
#endif
#ifndef PRODUCT_STORAGE_STANDARD_SERVER
#define PRODUCT_STORAGE_STANDARD_SERVER             0x00000015
#endif
#ifndef PRODUCT_STORAGE_WORKGROUP_SERVER
#define PRODUCT_STORAGE_WORKGROUP_SERVER            0x00000016
#endif
#ifndef PRODUCT_STORAGE_ENTERPRISE_SERVER
#define PRODUCT_STORAGE_ENTERPRISE_SERVER           0x00000017
#endif
#ifndef PRODUCT_SERVER_FOR_SMALLBUSINESS
#define PRODUCT_SERVER_FOR_SMALLBUSINESS            0x00000018
#endif
#ifndef PRODUCT_SMALLBUSINESS_SERVER_PREMIUM
#define PRODUCT_SMALLBUSINESS_SERVER_PREMIUM        0x00000019
#endif
#ifndef PRODUCT_HOME_PREMIUM_N
#define PRODUCT_HOME_PREMIUM_N                      0x0000001A
#endif
#ifndef PRODUCT_ENTERPRISE_N
#define PRODUCT_ENTERPRISE_N                        0x0000001B
#endif
#ifndef PRODUCT_ULTIMATE_N
#define PRODUCT_ULTIMATE_N                          0x0000001C
#endif
#ifndef PRODUCT_WEB_SERVER_CORE
#define PRODUCT_WEB_SERVER_CORE                     0x0000001D
#endif
#ifndef PRODUCT_MEDIUMBUSINESS_SERVER_MANAGEMENT
#define PRODUCT_MEDIUMBUSINESS_SERVER_MANAGEMENT    0x0000001E
#endif
#ifndef PRODUCT_MEDIUMBUSINESS_SERVER_SECURITY
#define PRODUCT_MEDIUMBUSINESS_SERVER_SECURITY      0x0000001F
#endif
#ifndef PRODUCT_MEDIUMBUSINESS_SERVER_MESSAGING
#define PRODUCT_MEDIUMBUSINESS_SERVER_MESSAGING     0x00000020
#endif
#ifndef PRODUCT_SERVER_FOUNDATION
#define PRODUCT_SERVER_FOUNDATION                   0x00000021
#endif
#ifndef PRODUCT_HOME_PREMIUM_SERVER
#define PRODUCT_HOME_PREMIUM_SERVER                 0x00000022
#endif
#ifndef PRODUCT_SERVER_FOR_SMALLBUSINESS_V
#define PRODUCT_SERVER_FOR_SMALLBUSINESS_V          0x00000023
#endif
#ifndef PRODUCT_STANDARD_SERVER_V
#define PRODUCT_STANDARD_SERVER_V                   0x00000024
#endif
#ifndef PRODUCT_DATACENTER_SERVER_V
#define PRODUCT_DATACENTER_SERVER_V                 0x00000025
#endif
#ifndef PRODUCT_ENTERPRISE_SERVER_V
#define PRODUCT_ENTERPRISE_SERVER_V                 0x00000026
#endif
#ifndef PRODUCT_DATACENTER_SERVER_CORE_V
#define PRODUCT_DATACENTER_SERVER_CORE_V            0x00000027
#endif
#ifndef PRODUCT_STANDARD_SERVER_CORE_V
#define PRODUCT_STANDARD_SERVER_CORE_V              0x00000028
#endif
#ifndef PRODUCT_ENTERPRISE_SERVER_CORE_V
#define PRODUCT_ENTERPRISE_SERVER_CORE_V            0x00000029
#endif
#ifndef PRODUCT_HYPERV
#define PRODUCT_HYPERV                              0x0000002A
#endif
#ifndef PRODUCT_STORAGE_EXPRESS_SERVER_CORE
#define PRODUCT_STORAGE_EXPRESS_SERVER_CORE         0x0000002B
#endif
#ifndef PRODUCT_STORAGE_STANDARD_SERVER_CORE
#define PRODUCT_STORAGE_STANDARD_SERVER_CORE        0x0000002C
#endif
#ifndef PRODUCT_STORAGE_WORKGROUP_SERVER_CORE
#define PRODUCT_STORAGE_WORKGROUP_SERVER_CORE       0x0000002D
#endif
#ifndef PRODUCT_STORAGE_ENTERPRISE_SERVER_CORE
#define PRODUCT_STORAGE_ENTERPRISE_SERVER_CORE      0x0000002E
#endif
#ifndef PRODUCT_STARTER_N
#define PRODUCT_STARTER_N                           0x0000002F
#endif
#ifndef PRODUCT_PROFESSIONAL
#define PRODUCT_PROFESSIONAL                        0x00000030
#endif
#ifndef PRODUCT_PROFESSIONAL_N
#define PRODUCT_PROFESSIONAL_N                      0x00000031
#endif
#ifndef PRODUCT_SB_SOLUTION_SERVER
#define PRODUCT_SB_SOLUTION_SERVER                  0x00000032
#endif
#ifndef PRODUCT_SERVER_FOR_SB_SOLUTIONS
#define PRODUCT_SERVER_FOR_SB_SOLUTIONS             0x00000033
#endif
#ifndef PRODUCT_STANDARD_SERVER_SOLUTIONS
#define PRODUCT_STANDARD_SERVER_SOLUTIONS           0x00000034
#endif
#ifndef PRODUCT_STANDARD_SERVER_SOLUTIONS_CORE
#define PRODUCT_STANDARD_SERVER_SOLUTIONS_CORE      0x00000035
#endif
#ifndef PRODUCT_SB_SOLUTION_SERVER_EM
#define PRODUCT_SB_SOLUTION_SERVER_EM               0x00000036
#endif
#ifndef PRODUCT_SERVER_FOR_SB_SOLUTIONS_EM
#define PRODUCT_SERVER_FOR_SB_SOLUTIONS_EM          0x00000037
#endif
#ifndef PRODUCT_SOLUTION_EMBEDDEDSERVER
#define PRODUCT_SOLUTION_EMBEDDEDSERVER             0x00000038
#endif
#ifndef PRODUCT_SOLUTION_EMBEDDEDSERVER_CORE
#define PRODUCT_SOLUTION_EMBEDDEDSERVER_CORE        0x00000039
#endif
#ifndef PRODUCT_SMALLBUSINESS_SERVER_PREMIUM_CORE
#define PRODUCT_SMALLBUSINESS_SERVER_PREMIUM_CORE   0x0000003F
#endif
#ifndef PRODUCT_ESSENTIALBUSINESS_SERVER_MGMT
#define PRODUCT_ESSENTIALBUSINESS_SERVER_MGMT       0x0000003B
#endif
#ifndef PRODUCT_ESSENTIALBUSINESS_SERVER_ADDL
#define PRODUCT_ESSENTIALBUSINESS_SERVER_ADDL       0x0000003C
#endif
#ifndef PRODUCT_ESSENTIALBUSINESS_SERVER_MGMTSVC
#define PRODUCT_ESSENTIALBUSINESS_SERVER_MGMTSVC    0x0000003D
#endif
#ifndef PRODUCT_ESSENTIALBUSINESS_SERVER_ADDLSVC
#define PRODUCT_ESSENTIALBUSINESS_SERVER_ADDLSVC    0x0000003E
#endif
#ifndef PRODUCT_CLUSTER_SERVER_V
#define PRODUCT_CLUSTER_SERVER_V                    0x00000040
#endif
#ifndef PRODUCT_EMBEDDED
#define PRODUCT_EMBEDDED                            0x00000041
#endif
#ifndef PRODUCT_STARTER_E
#define PRODUCT_STARTER_E                           0x00000042
#endif
#ifndef PRODUCT_HOME_BASIC_E
#define PRODUCT_HOME_BASIC_E                        0x00000043
#endif
#ifndef PRODUCT_HOME_PREMIUM_E
#define PRODUCT_HOME_PREMIUM_E                      0x00000044
#endif
#ifndef PRODUCT_PROFESSIONAL_E
#define PRODUCT_PROFESSIONAL_E                      0x00000045
#endif
#ifndef PRODUCT_ENTERPRISE_E
#define PRODUCT_ENTERPRISE_E                        0x00000046
#endif
#ifndef PRODUCT_ULTIMATE_E
#define PRODUCT_ULTIMATE_E                          0x00000047
#endif

#ifndef PRODUCT_UNLICENSED
#define PRODUCT_UNLICENSED                          0xABCDABCD
#endif

typedef void (WINAPI *PGNSI)(LPSYSTEM_INFO);
typedef BOOL (WINAPI *PGPI)(DWORD, DWORD, DWORD, DWORD, PDWORD);

typedef struct
{
	// Windows base version numbers (ex: 6.1.7601)
	DWORD MajorVersion;
	DWORD MinorVersion;
	DWORD BuildNumber;
	
	// Service pack version numbers
	WORD ServicePackMajorVersion;
	WORD ServicePackMinorVersion;
	
	// Simple conditionals
	BOOL IsServer;
	BOOL IsNT;
	
	// Flags for determining other things
	DWORD ProductType; // Product type identifier for Windows NT 6+ only
	WORD SuiteMask;
	
	WORD ProcessorArchitecture;
} SystemInformationEx;

char* GetVersionName(SystemInformationEx *info)
{
	if (info->MajorVersion == 6)
	{
		switch (info->MinorVersion)
		{
		case 2:
			return info->IsServer ? "Server 8" : "8";
		case 1:
			return info->IsServer ? "Server 2008 R2" : "7";
		case 0:
			return info->IsServer ? "Server 2008" : "Vista";
		default:
			return "Unknown";
		}
	}
	else if (info->MajorVersion == 5)
	{
		switch (info->MinorVersion)
		{
		case 2:
			if (GetSystemMetrics(SM_SERVERR2))
				return "Server 2003 R2";
			else if (info->SuiteMask & VER_SUITE_STORAGE_SERVER)
				return "Storage Server 2003";
			else if (info->SuiteMask & VER_SUITE_WH_SERVER)
				return "Home Server";
			else if (!info->IsServer && info->ProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
				return "XP";
			else
				return "Server 2003";
		case 1:
			return "XP";
		case 0:
			return "2000";
		default:
			return "Unknown";
		}
	}
	
	return "Unknown";
}

char* GetEditionName(SystemInformationEx *info)
{
	if (info->MajorVersion == 6)
	{
		// NT6+ uses this value from the GetProductInfo function
		switch (info->ProductType)
		{
		case PRODUCT_ULTIMATE:
			return "Ultimate";
		case PRODUCT_ULTIMATE_E:
			return "Ultimate E";
		case PRODUCT_ULTIMATE_N:
			return "Ultimate N";
		case PRODUCT_PROFESSIONAL:
			return "Professional";
		case PRODUCT_PROFESSIONAL_E:
			return "Professional E";
		case PRODUCT_PROFESSIONAL_N:
			return "Professional N";
		case PRODUCT_HOME_PREMIUM:
			return "Home Premium";
		case PRODUCT_HOME_PREMIUM_E:
			return "Home Premium E";
		case PRODUCT_HOME_PREMIUM_N:
			return "Home Premium N";
		case PRODUCT_HOME_PREMIUM_SERVER:
			return "Home Server 2011";
		case PRODUCT_HOME_SERVER:
			return "Storage Server Essentials";
		case PRODUCT_HOME_BASIC:
			return "Home Basic";
		case PRODUCT_HOME_BASIC_E:
			return "Home Basic E";
		case PRODUCT_HOME_BASIC_N:
			return "Home Basic N";
		case PRODUCT_ENTERPRISE:
			return "Enterprise";
		case PRODUCT_ENTERPRISE_E:
			return "Enterprise E";
		case PRODUCT_ENTERPRISE_N:
			return "Enterprise N";
		case PRODUCT_BUSINESS:
			return "Business";
		case PRODUCT_BUSINESS_N:
			return "Business N";
		case PRODUCT_STARTER:
			return "Starter";
		case PRODUCT_STARTER_E:
			return "Starter E";
		case PRODUCT_STARTER_N:
			return "Starter N";
		case PRODUCT_CLUSTER_SERVER:
			return "HPC";
		case PRODUCT_DATACENTER_SERVER:
			return "Datacenter";
		case PRODUCT_DATACENTER_SERVER_V:
			return "Datacenter V";
		case PRODUCT_DATACENTER_SERVER_CORE:
			return "Datacenter Core";
		case PRODUCT_DATACENTER_SERVER_CORE_V:
			return "Datacenter Core V";
		case PRODUCT_ENTERPRISE_SERVER:
			return "Enterprise";
		case PRODUCT_ENTERPRISE_SERVER_V:
			return "Enterprise V";
		case PRODUCT_ENTERPRISE_SERVER_CORE:
			return "Enterprise Core";
		case PRODUCT_ENTERPRISE_SERVER_CORE_V:
			return "Enterprise Core V";
		case PRODUCT_ENTERPRISE_SERVER_IA64:
			return "Enterprise for Itanium-based Systems";
		case PRODUCT_SMALLBUSINESS_SERVER:
			return "Small Business Server";
		case PRODUCT_SMALLBUSINESS_SERVER_PREMIUM:
			return "Small Business Server Premium";
		case PRODUCT_STANDARD_SERVER:
			return "Standard";
		case PRODUCT_STANDARD_SERVER_V:
			return "Standard V";
		case PRODUCT_STANDARD_SERVER_CORE:
			return "Standard Core";
		case PRODUCT_STANDARD_SERVER_CORE_V:
			return "Standard Core V";
		case PRODUCT_WEB_SERVER:
			return "Web Server";
		case PRODUCT_WEB_SERVER_CORE:
			return "Web Server Core";
		case PRODUCT_HYPERV:
			return "Hyper-V Server";
		case PRODUCT_MEDIUMBUSINESS_SERVER_MANAGEMENT:
			return "Essential Business Server Management Server";
		case PRODUCT_MEDIUMBUSINESS_SERVER_MESSAGING:
			return "Essential Business Server Messaging Server";
		case PRODUCT_MEDIUMBUSINESS_SERVER_SECURITY:
			return "Essential Business Server Security Server";
		case PRODUCT_SERVER_FOR_SMALLBUSINESS:
			return "Essential Server Solutions";
		case PRODUCT_SERVER_FOR_SMALLBUSINESS_V:
			return "Essential Server Solutions V";
		case PRODUCT_SERVER_FOUNDATION:
			return "Server Foundation";
		case PRODUCT_SB_SOLUTION_SERVER:
			return "Small Business Server 2011 Essentials";
		case PRODUCT_SOLUTION_EMBEDDEDSERVER:
			return "MultiPoint Server";
		case PRODUCT_STORAGE_ENTERPRISE_SERVER:
			return "Storage Server Enterprise";
		case PRODUCT_STORAGE_EXPRESS_SERVER:
			return "Storage Server Express";
		case PRODUCT_STORAGE_STANDARD_SERVER:
			return "Storage Server Standard";
		case PRODUCT_STORAGE_WORKGROUP_SERVER:
			return "Storage Server Workgroup";
		case PRODUCT_UNDEFINED:
		default:
			return "Unknown";
		}
	}
	else if (info->MajorVersion == 5)
	{
		switch (info->MinorVersion)
		{
		case 2:
			if (info->IsServer)
			{
				if (info->ProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64)
				{
					if (info->SuiteMask & VER_SUITE_DATACENTER)
						return "Datacenter Edition for Itanium-based Systems";
					else if (info->SuiteMask & VER_SUITE_ENTERPRISE)
						return "Enterprise Edition for Itanium-based Systems";
				}
				else if (info->ProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
				{
					if (info->SuiteMask & VER_SUITE_DATACENTER)
						return "Datacenter x64 Edition";
					else if (info->SuiteMask & VER_SUITE_ENTERPRISE)
						return "Enterprise x64 Edition";
					else
						return "Standard x64 Edition";
				}
				else
				{
					if (info->SuiteMask & VER_SUITE_COMPUTE_SERVER)
						return "Compute Cluster Edition";
					else if (info->SuiteMask & VER_SUITE_DATACENTER)
						return "Datacenter Edition";
					else if (info->SuiteMask & VER_SUITE_ENTERPRISE)
						return "Enterprise Edition";
					else if (info->SuiteMask & VER_SUITE_BLADE)
						return "Web Edition";
					else
						return "Standard Edition";
				}
			}
			else if (info->ProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
				return "Professional x64 Edition";
			else
				return "Unknown";
		case 1:
			if (GetSystemMetrics(SM_MEDIACENTER))
				return "Media Center";
			else if (GetSystemMetrics(SM_STARTER))
				return "Starter";
			else if (GetSystemMetrics(SM_TABLETPC))
				return "Tablet PC";
			else if (info->SuiteMask & VER_SUITE_PERSONAL)
				return "Home";
			else
				return "Professional";
		case 0:
			if (info->IsServer)
			{
				if (info->SuiteMask & VER_SUITE_DATACENTER)
					return "Datacenter Server";
				else if (info->SuiteMask & VER_SUITE_ENTERPRISE)
					return "Advanced Server";
				else
					return "Server";
			}
			else
				return "Professional";
		default:
			return "Unknown";
		}
	}
	
	return "Unknown";
}

HRESULT InitializeSystemInformation(SystemInformationEx *info)
{
	// Pointers to functions we must call dynamically since they may not be available on the OS we're running
	PGNSI GetNativeSystemInfo = (PGNSI)GetProcAddress(GetModuleHandleA("kernel32.dll"), "GetNativeSystemInfo");
	PGPI GetProductInfo = (PGPI)GetProcAddress(GetModuleHandleA("kernel32.dll"), "GetProductInfo");
	
	OSVERSIONINFOEX vi;
	SYSTEM_INFO si;
	ZeroMemory(info, sizeof(SystemInformationEx));
	ZeroMemory(&vi, sizeof(OSVERSIONINFOEX));
	ZeroMemory(&si, sizeof(SYSTEM_INFO));
	vi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	
	// Get operating system version information
	if (!GetVersionEx((OSVERSIONINFO*)&vi))
		return 1;
		
	// Non-NT versions or versions below NT5 (Windows 2000) are not supported
	if (vi.dwPlatformId != VER_PLATFORM_WIN32_NT || vi.dwMajorVersion < 5)
		return 2;
		
	if (!GetProductInfo || !GetProductInfo(vi.dwMajorVersion, vi.dwMinorVersion, vi.wServicePackMajor, vi.wServicePackMinor, &info->ProductType))
		return 1;

	if (GetNativeSystemInfo)
		GetNativeSystemInfo(&si);
	else
		GetSystemInfo(&si);

	// Set basic version information
	info->MajorVersion = vi.dwMajorVersion;
	info->MinorVersion = vi.dwMinorVersion;
	info->BuildNumber = vi.dwBuildNumber;
	
	info->ServicePackMajorVersion = vi.wServicePackMajor;
	info->ServicePackMinorVersion = vi.wServicePackMinor;
	
	info->IsServer = vi.wProductType != VER_NT_WORKSTATION;
	info->IsNT = vi.dwPlatformId == VER_PLATFORM_WIN32_NT;
	
	info->SuiteMask = vi.wSuiteMask;
	
	info->ProcessorArchitecture = si.wProcessorArchitecture;
	
	return S_OK;
}

#define OPT_S 0x1
#define OPT_O 0x2
#define OPT_M 0x4
#define OPT_P 0x8
#define OPT_I 0x10
#define OPT_V 0x20
#define OPT_R 0x40
#define OPT_N 0x400

#define OPT_KERNEL OPT_S
#define OPT_KERNEL_VERSION OPT_R
#define OPT_OS OPT_O
#define OPT_OS_VERSION 0x80
#define OPT_OS_VERSION_NAME 0x100
#define OPT_OS_EDITION 0x200
#define OPT_OS_ARCH OPT_M
#define OPT_OS_SP 0x800

#define OPT_A OPT_KERNEL | OPT_N | OPT_OS | OPT_OS_VERSION | OPT_OS_VERSION_NAME | OPT_OS_EDITION | OPT_OS_ARCH | OPT_OS_SP | OPT_P | OPT_I | OPT_KERNEL_VERSION | OPT_R

void PrintDocumentation()
{
	printf("Usage: pname [OPTION]...\n");
	printf("Print certain system information. With no OPTION, same as -s.\n\n");
	
	printf("  -a, --all\t\t\t\tprint all information, in the following order, except omit -p and -i if unknown:\n\n");
	
	printf("  -s, --kernel-name\t\t\tprint the kernel name\n");
	printf("  -n, --nodename\t\t\tprint the network node hostname\n");
	printf("  -r, --kernel-release\t\t\tprint the kernel release\n");
	printf("  -v, --kernel-version\t\t\tprint the kernel version\n");
	printf("  -m, --machine\t\t\t\tprint the machine hardware name\n"); // Architecture
	printf("  -p, --processor\t\t\tprint the processor type or \"unknown\"\n");
	printf("  -i, --hardware-platform\t\tprint the hardware platform or \"unknown\"\n");
	printf("  -o, --operating-system\t\tprint the operating system\n");
	printf("      --operating-system-version\tprint the operating system version\n");
	printf("      --operating-system-version-name\tprint the operating system version name\n");
	printf("      --operating-system-edition\tprint the operating system edition\n");
	printf("      --operating-system-service-pack\tprint the operating system service pack level\n");
	
	printf("\n");
	
	printf("      --help\tdisplay this help and exit\n");
	printf("      --version\toutput version information and exit\n\n");
	
	printf("Report pname bugs to bugs@petroules.com\n");
	printf("General help using Petroules software: <http://www.petroules.com/help>\n");
}

BOOL GetVersionInfo(char *fileName, short aVersion[])
{
	UINT len = 0;
	VS_FIXEDFILEINFO *vsfi = NULL;
	
	DWORD handle = 0;
	DWORD size = GetFileVersionInfoSize(fileName, &handle);
	BYTE* versionInfo = (BYTE*)calloc(size, sizeof(BYTE));
	if (!GetFileVersionInfoA(fileName, handle, size, versionInfo))
	{
		free(versionInfo);
		return 1;
	}
	
	// we have version information
	VerQueryValue(versionInfo, "\\", (void**)&vsfi, &len);
	aVersion[0] = HIWORD(vsfi->dwFileVersionMS);
	aVersion[1] = LOWORD(vsfi->dwFileVersionMS);
	aVersion[2] = HIWORD(vsfi->dwFileVersionLS);
	aVersion[3] = LOWORD(vsfi->dwFileVersionLS);
	free(versionInfo);
	
	return TRUE;
}

BOOL GetOSBuildDate(char *date)
{
	HANDLE file;
	FILETIME modDate;
	SYSTEMTIME t;
	char buf[MAX_PATH];
	GetSystemDirectory(buf, MAX_PATH);
	sprintf(buf + strlen(buf), "\\kernel32.dll");
	file = CreateFileA(buf, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, 0);
	if (file == INVALID_HANDLE_VALUE)
		return FALSE;
	
	if (!GetFileTime(file, 0, 0, &modDate))
		return FALSE;
		
	if (!FileTimeToSystemTime(&modDate, &t))
		return FALSE;
		
	sprintf(date, "%d/%d/%d %d:%d:%d", t.wMonth, t.wDay, t.wYear, t.wHour, t.wMinute, t.wSecond);
	
	CloseHandle(file);
	return TRUE;
}

BOOL StringsEqual(char *string1, char *string2)
{
	return strcmp(string1, string2) == 0;
}

int main(int argc, char *argv[])
{
	BOOL all = FALSE;
	int options = 0;
	const DWORD strSize = 100;
	DWORD strSize2 = strSize;
	char **outputs = (char**)calloc(strSize, sizeof(char));
	size_t argSize = 0;
	int i = 0;
	int j = 0;
	short aVersion[4];
	char buildDate[100];
	
	SystemInformationEx systemInfo;
	if (FAILED(InitializeSystemInformation(&systemInfo)))
	{
		printf("Failed to retrieve system information");
		return 1;
	}
	
	if (!GetVersionInfo("kernel32.dll", aVersion))
		return 1;
		
	if (!GetOSBuildDate(buildDate))
		return 1;
	
	// Initialize sloppy C pointer to pointer
	for (i = 0; i < strSize; i++)
	{
		outputs[i] = (char*)calloc(strSize, sizeof(char) * strSize);
	}
	
	i = 0;
	
	if (argc > 1)
	{
		char *args = argv[1];
		argSize = strlen(args);
		
		if (argSize > 1 && args[0] == '-' && args[1] != '-')
		{
			for (i = 1; i < argSize; i++)
			{
				switch (args[i])
				{
					case 'a':
						all = TRUE;
						break;
					case 's':
						options |= OPT_S;
						break;
					case 'n':
						options |= OPT_N;
						break;
					case 'o':
						options |= OPT_O;
						break;
					case 'm':
						options |= OPT_M;
						break;
					case 'p':
						options |= OPT_P;
						break;
					case 'i':
					case 'M':
						options |= OPT_I;
						break;
					case 'v':
						options |= OPT_V;
						break;
					case 'r':
						options |= OPT_R;
						break;
					default:
						PrintDocumentation();
						return 1;
				}
			}
		}
		else
		{
			for (i = 1; i < argc; i++)
			{
				if (StringsEqual(argv[i], "--all"))
				{
					all = TRUE;
					break;
				}
				else if (StringsEqual(argv[i], "--kernel-name"))
					options |= OPT_KERNEL;
				else if (StringsEqual(argv[i], "--nodename"))
					options |= OPT_N;
				else if (StringsEqual(argv[i], "--operating-system") || StringsEqual(argv[i], "--os"))
					options |= OPT_OS;
				else if (StringsEqual(argv[i], "--operating-system-version") || StringsEqual(argv[i], "--os-version"))
					options |= OPT_OS_VERSION;
				else if (StringsEqual(argv[i], "--operating-system-version-name") || StringsEqual(argv[i], "--os-version-name"))
					options |= OPT_OS_VERSION_NAME;
				else if (StringsEqual(argv[i], "--operating-system-edition") || StringsEqual(argv[i], "--os-edition"))
					options |= OPT_OS_EDITION;
				else if (StringsEqual(argv[i], "--operating-system-architecture") ||
						StringsEqual(argv[i], "--operating-system-arch") ||
						StringsEqual(argv[i], "--os-architecture") ||
						StringsEqual(argv[i], "--os-arch"))
					options |= OPT_OS_ARCH;
				else if (StringsEqual(argv[i], "--operating-system-service-pack") ||
						StringsEqual(argv[i], "--operating-system-sp") ||
						StringsEqual(argv[i], "--os-service-pack") ||
						StringsEqual(argv[i], "--os-sp"))
					options |= OPT_OS_SP;
				// continue... P I R
				else if (StringsEqual(argv[i], "--kernel-version"))
					options |= OPT_KERNEL_VERSION;
				else
				{
					PrintDocumentation();
					return 1;
				}
			}
		}
	}
	else
	{
		options |= OPT_S;
	}
	
	// Start buffering data for output
	i = 0;
	
	if (all)
	{
		options = OPT_A;
	}
	
	if (options & OPT_KERNEL)
	{
		outputs[i++] = "NT";
	}
	
	if (options & OPT_N)
	{
		GetComputerNameA(outputs[i++], &strSize2);
	}
	
	if (options & OPT_OS)
	{
		outputs[i++] = "Windows";
	}
	
	if (options & OPT_OS_VERSION)
	{
		sprintf(outputs[i++], "%d.%d.%d", systemInfo.MajorVersion, systemInfo.MinorVersion, systemInfo.BuildNumber);
	}
	
	if (options & OPT_OS_VERSION_NAME)
	{
		strcpy(outputs[i++], GetVersionName(&systemInfo));
	}
	
	if (options & OPT_OS_EDITION)
	{
		strcpy(outputs[i++], GetEditionName(&systemInfo));
	}
	
	if (options & OPT_OS_SP)
	{
		char *out = outputs[i++];
		if (all)
		{
			sprintf(out, "Service Pack ");
		}
		
		sprintf(out + strlen(out), "%d.%d", systemInfo.ServicePackMajorVersion, systemInfo.ServicePackMinorVersion);
	}
	
	if (options & OPT_OS_ARCH)
	{
		switch (systemInfo.ProcessorArchitecture)
		{
		case PROCESSOR_ARCHITECTURE_AMD64:
			outputs[i++] = "x86_64";
			break;
		case PROCESSOR_ARCHITECTURE_IA64:
			outputs[i++] = "IA64";
			break;
		case PROCESSOR_ARCHITECTURE_INTEL:
			outputs[i++] = "i686";
			break;
		case PROCESSOR_ARCHITECTURE_UNKNOWN:
		default:
			outputs[i++] = "unknown";
			break;
		}
	}
	
	if (options & OPT_P)
	{
		if (!all)
			outputs[i++] = "unknown";
	}
	
	if (options & OPT_I)
	{
		if (!all)
			outputs[i++] = "unknown";
	}
	
	if (options & OPT_KERNEL_VERSION)
	{
		sprintf(outputs[i++], "%d.%d.%d.%d", systemInfo.MajorVersion, systemInfo.MinorVersion, systemInfo.BuildNumber, aVersion[3]);
	}
	
	if (options & OPT_V)
	{
		sprintf(outputs[i++], "%s %d.%d.%d.%d %s", "NT", aVersion[0], aVersion[1], aVersion[2], aVersion[3], buildDate);
	}
	
	// Print all output
	for (j = 0; j < i; j++)
	{
		if (j > 0)
		{
			printf(" ");
		}
		
		printf(outputs[j]);
	}
	
	printf("\n");	
}