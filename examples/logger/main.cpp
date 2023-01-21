#include "wrt/acc/shared_memory.hpp"

#include <iostream>

using namespace wrt::acc;

void log(SMStatic sm_static, SMGraphics sm_graphics, SMPhysics sm_physics)
{
	std::wcout << "Shared memory version: " << sm_static()->smVersion << '\n';
	std::wcout << "Game version: " << sm_static()->accVersion << '\n';
	std::wcout << "More information: https://github.com/wilrickrt/acc/ \n\n";
	
	while (true)
	{
		if (GetAsyncKeyState('Q') & 1)
		{
			break;
		}
		if (GetAsyncKeyState('L') & 1)
		{
			std::wcout << "===[" << sm_graphics()->clock << "]===\n";
			std::wcout << "speed: " << sm_physics()->speed << '\n';
			std::wcout << "gear: " << sm_physics()->gear << '\n';
			std::wcout << "rpm: " << sm_physics()->rpm << "\n\n";
		}
	}
}

int main()
{
	auto sm_static = OpenStaticSharedMemory();
	auto sm_graphics = OpenGraphicsSharedMemory();
	auto sm_physics = OpenPhysicsSharedMemory();

	if (sm_static && sm_graphics && sm_physics)
	{
		log(*sm_static, *sm_graphics, *sm_physics);
	}
}
