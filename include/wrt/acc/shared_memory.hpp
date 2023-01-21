#ifndef WRT_ACC_SHARED_MEMORY_HPP
#define WRT_ACC_SHARED_MEMORY_HPP

#include <Windows.h>

#include <optional>

#include "acc.hpp"

namespace wrt::acc
{
	template<typename T>
	class SharedMemory
	{
	public:
		SharedMemory(HANDLE handle, T* memory)
			: m_handle(handle), m_memory(memory)
		{}

		SharedMemory(SharedMemory&& other) noexcept
			: SharedMemory(other.m_handle, other.m_memory)
		{
			other.m_handle = 0;
			other.m_memory = nullptr;
		}

		SharedMemory(SharedMemory& other)
			: SharedMemory(other.m_handle, other.m_memory)
		{
			other.m_handle = 0;
			other.m_memory = nullptr;
		}

		SharedMemory& operator=(const SharedMemory&& other) noexcept
		{
			if (this != &other)
			{
				Close();
				m_handle = other.m_handle;
				m_memory = other.m_memory;
				other.m_handle = 0;
				other.m_memory = nullptr;
			}
			return *this;
		}
		SharedMemory& operator=(SharedMemory& other)
		{
			if (this != &other)
			{
				Close();
				m_handle = other.m_handle;
				m_memory = other.m_memory;
				other.m_handle = 0;
				other.m_memory = nullptr;
			}
			return *this;
		}

		~SharedMemory()
		{
			Close();
		}

		/**
		 * @brief Get access to the shared memory via the ()-operator
		 */
		T* operator()() const
		{
			return m_memory;
		}

		/**
		 * @brief Get access to the memory
		 */
		T* GetMemory() const
		{
			return m_memory;
		}

	protected:
		void Close()
		{
			if (m_memory)
			{
				UnmapViewOfFile(m_memory);
			}
			if (m_handle)
			{
				CloseHandle(m_handle);
			}
		}

	private:
		HANDLE m_handle;	// Handle to shared memory
		T* m_memory;		// Pointer to the shared memory
	};

	typedef SharedMemory<SPageFileStatic> SMStatic;
	typedef SharedMemory<SPageFileGraphics> SMGraphics;
	typedef SharedMemory<SPageFilePhysics> SMPhysics;

	std::optional<SMStatic> OpenStaticSharedMemory();
	std::optional<SMGraphics> OpenGraphicsSharedMemory();
	std::optional<SMPhysics> OpenPhysicsSharedMemory();
} // namespace wrt::acc

#endif // WRT_ACC_SHARED_MEMORY_HPP
