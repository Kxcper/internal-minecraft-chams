#include <windows.h>
#include <thread> // Include this header for std::this_thread
#include "gl_scale_f.h"
static HINSTANCE g_hModule = nullptr;

auto entry_point() -> void {
	hooks::init();

	while (!GetAsyncKeyState(VK_END)) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	hooks::dispose();
	FreeLibraryAndExitThread(g_hModule, 0);
}

int __stdcall DllMain(HINSTANCE hinstDLL, unsigned long fdwReason,
	void* lpvReserved) {
	if (fdwReason != DLL_PROCESS_ATTACH)
		return false;

	g_hModule = hinstDLL;
	DisableThreadLibraryCalls(hinstDLL);
	CreateThread(0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(entry_point), 0,
		0, 0);

	return true;
}