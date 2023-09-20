#include "particleDB/io.h"

namespace particleDB {

std::string getDataPath(std::string filename) {
	std::filesystem::path path = std::filesystem::current_path();
	path += "/data/";
	path += filename;
	return path.u8string();
}

} // namespace