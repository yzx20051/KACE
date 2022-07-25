#pragma once
#include <cstdint>
#include <cstdio>

#include "module_layout.h"
#include "ntoskrnl_struct.h"
#include <shlwapi.h>

#pragma comment(lib, "Shlwapi.lib")

#pragma section("fakek",read,write)

#define KERNELDATA inline __declspec(align(0x1000), allocate("fakek")) 

KERNELDATA _ETHREAD FakeKernelThread = {0};
KERNELDATA _EPROCESS FakeSystemProcess = { 0 };
KERNELDATA _KPCR FakeKPCR = { 0 };
KERNELDATA _KPRCB FakeCPU = { 0 };
KERNELDATA _DRIVER_OBJECT drvObj = { 0 };
KERNELDATA UNICODE_STRING RegistryPath = { 0 };

//extern std::unordered_map<std::string, ConstantFunctionPrototype> myConstantProvider;
extern std::unordered_map<std::string, PVOID> api_provider;

NTSTATUS h_RtlInitUnicodeString(PUNICODE_STRING DestinationString, PCWSTR SourceString);

namespace ntoskrnl_provider {
	void Initialize();
}
