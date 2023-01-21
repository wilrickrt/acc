add_library(acc shared_memory.cpp)
target_include_directories(acc
	PUBLIC
		$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
add_library(wrt::acc ALIAS acc)

install(TARGETS acc EXPORT wrt-acc-targets)
