#include <iostream>
#include <Windows.h>

void PrintProcPrty(HANDLE h)
{
	/*SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo);
	int numCPU = sysinfo.dwNumberOfProcessors;*/
	DWORD prty = GetPriorityClass(h);
	std::cout << "Current Pid: " << GetCurrentProcessId() << std::endl;
	std::cout << "Max proccessors: " << _Thrd_hardware_concurrency() << std::endl;

	switch (prty)
	{
	case IDLE_PRIORITY_CLASS:
		std::cout << "-----+ priority = IDLE_PRIORITY_CLASS \n";
		break;
	case BELOW_NORMAL_PRIORITY_CLASS:
		std::cout << "-----+ priority = BELOW_NORMAL_PRIORITY_CLASS \n";
		break;
	case NORMAL_PRIORITY_CLASS:
		std::cout << "-----+ priority = NORMAL_PRIORITY_CLASS \n";
		break;
	case ABOVE_NORMAL_PRIORITY_CLASS:
		std::cout << "-----+ priority = ABOVE_NORMAL_PRIORITY_CLASS \n";
		break;
	case HIGH_PRIORITY_CLASS:
		std::cout << "-----+ priority = HIGH_PRIORITY_CLASS \n";
		break;
	case REALTIME_PRIORITY_CLASS:
		std::cout << "-----+ priority = REALTIME_PRIORITY_CLASS \n";
		break;
	default:
		break;
	}
}

void PrintThreadPrty(HANDLE h)
{
	DWORD icpu = SetThreadIdealProcessor(h, MAXIMUM_PROCESSORS);
	DWORD prty = GetThreadPriority(h);
	std::cout << "Current Thread Id: " << GetCurrentThreadId() << std::endl;
	std::cout << "-----+ Processor = " << icpu << std::endl;

	switch (prty)
	{
	case THREAD_PRIORITY_LOWEST:
		std::cout << "-----+ priority = THREAD_PRIORITY_LOWEST \n";
		break;
	case THREAD_PRIORITY_BELOW_NORMAL:
		std::cout << "-----+ priority = THREAD_PRIORITY_BELOW_NORMAL \n";
		break;
	case THREAD_PRIORITY_NORMAL:
		std::cout << "-----+ priority = THREAD_PRIORITY_NORMAL \n";
		break;
	case THREAD_PRIORITY_ABOVE_NORMAL:
		std::cout << "-----+ priority = THREAD_PRIORITY_ABOVE_NORMAL\n";
		break;
	case THREAD_PRIORITY_HIGHEST:
		std::cout << "-----+ priority = THREAD_PRIORITY_HIGHEST \n";
		break;
	case THREAD_PRIORITY_IDLE:
		std::cout << "-----+ priority = THREAD_PRIORITY_IDLE \n";
		break;
	case THREAD_PRIORITY_TIME_CRITICAL:
		std::cout << "-----+ priority = THREAD_PRIORITY_IDLE \n";
		break;
	default:
		break;
	}


}
int main()
{
	DWORD pid = GetCurrentProcessId();
	DWORD tid = GetCurrentThreadId();
	HANDLE hp = GetCurrentProcess();
	HANDLE ht = GetCurrentThread();

	try
	{
		DWORD pa = NULL, sa = NULL, icpu = -1;
		if (!GetProcessAffinityMask(hp, &pa, &sa))
			throw "GetProccessAfinityMask";
		std::string bin{};
		int val = pa;
		while (val > 0)
		{
			if (val % 2 == 0)
			{
				bin.insert(bin.begin(), '0');
			}
			else
			{
				bin.insert(bin.begin(), '1');
			}
			val >>= 1;
		}
		std::cout << "Proccess Afinity Mask in 2 base: " << std::showbase << bin << std::endl;

	}
	catch (const std::exception& ex)
	{
		std::cout << "Error: ";
	}

	PrintProcPrty(hp);
	PrintThreadPrty(ht);
}

