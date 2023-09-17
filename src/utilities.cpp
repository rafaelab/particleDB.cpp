#include "particles/utilities.h"

namespace particles {


std::string joinPath(const std::string& s1, const std::string& s2) {
	char end = *s1.rbegin();
	if (end == '\\' || end == '/')
		return s1 + s2;
	else
		return s1 + '/' + s2;
}



std::string executablePath() {
	char buffer[1024];
	size_t size = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);

	for (size_t i = 1; i < size; i++) {
		if (buffer[size - 1] == '/')
			break;
		else
			size--;
	}

	return std::string(buffer, size);
}


} // namespace