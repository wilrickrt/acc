#include "wrt/acc/shared_memory.hpp"

#include <string>

namespace wrt::acc
{
	std::optional<std::pair<HANDLE, void*>> OpenSharedMemory(const std::string& name, size_t size)
	{
		const auto handle = CreateFileMappingA(
			INVALID_HANDLE_VALUE,
			NULL,
			PAGE_READONLY,
			0,
			size,
			name.c_str());
		if (handle == INVALID_HANDLE_VALUE)
		{
			return {};
		}

		const auto memory = MapViewOfFile(handle, FILE_MAP_READ, 0, 0, size);
		if (memory == nullptr)
		{
			return {};
		}

		return std::pair<HANDLE, void*>{ handle, memory };
	}

	std::optional<SMStatic> OpenStaticSharedMemory()
	{
		if (const auto result = OpenSharedMemory("Local\\acpmf_static", sizeof(SPageFileStatic)))
		{
			return SMStatic{ result->first, (SPageFileStatic*)result->second };
		}
		return {};
	}

	std::optional<SMGraphics> OpenGraphicsSharedMemory()
	{
		if (const auto result = OpenSharedMemory("Local\\acpmf_graphics", sizeof(SPageFileGraphics)))
		{
			return SMGraphics{ result->first, (SPageFileGraphics*)result->second };
		}
		return {};
	}

	std::optional<SMPhysics> OpenPhysicsSharedMemory()
	{
		if (const auto result = OpenSharedMemory("Local\\acpmf_physics", sizeof(SPageFilePhysics)))
		{
			return SMPhysics{ result->first, (SPageFilePhysics*)result->second };
		}
		return {};
	}
} // namespace wrt::acc
