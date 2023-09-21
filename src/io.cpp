#include "particleDB/io.h"

namespace particleDB {

std::string getDataPath(std::string filename) {
	std::filesystem::path path = std::filesystem::current_path();
	path += std::filesystem::path("/data/");
	path += std::filesystem::path(filename);
	return path;
}


// std::string getDataPath(std::string filename) {

// 	static std::string dataPath;
// 	if (dataPath.size())
// 		return joinPath(dataPath, filename);

// 	const char* envPath = getenv("PARTICLEDB_DATA_PATH");
// 	if (envPath) {
// 		if (std::filesystem::is_directory(envPath)) {
// 			dataPath = envPath;
// 			return joinPath(dataPath, filename);
// 		}
// 	}

// 	#ifdef PARTICLEDB_INSTALL_PREFIX
// 	{
// 		std::string _path = PARTICLEDB_INSTALL_PREFIX "/share/data/particleDB";
// 		if (std::filesystem::is_directory(_path)) {
// 			dataPath = _path;
// 			return joinPath(dataPath, filename);
// 		}
// 	}
// 	#endif
	
// 	dataPath = "data";

// 	return joinPath(dataPath, filename);
// }


// std::string getInstallPrefix() {
// 	std::string path = "";
// 	#ifdef PARTICLEDB_INSTALL_PREFIX
// 		path += PARTICLEDB_INSTALL_PREFIX;
// 	#endif

//   return path;
// };



} // namespace