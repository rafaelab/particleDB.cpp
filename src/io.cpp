#include "particleDB/io.h"


namespace particleDB {


std::filesystem::path getDataPath(std::string filename) {
	std::filesystem::path fileName(filename);
	static std::filesystem::path dataPath;

	const char* envPath = std::getenv("PARTICLEDB_DATA_PATH");
	if (envPath) {
		if (std::filesystem::is_directory(envPath)) {
			dataPath = envPath / fileName;
			return dataPath;
		}
	}

	#ifdef PARTICLEDB_INSTALL_PREFIX
	{
		std::filesystem::path sharePath(PARTICLEDB_INSTALL_PREFIX  "/share/particleDB");
		dataPath = sharePath / fileName;
		return dataPath;
	}
	#endif

	std::filesystem::path dataDir("data/");
	dataPath = dataDir / fileName;

	return dataPath;
}


std::filesystem::path getInstallPrefix() {
	std::filesystem::path path("");
	#ifdef PARTICLEDB_INSTALL_PREFIX
		path += PARTICLEDB_INSTALL_PREFIX;
	#endif

	return path;
};



} // namespace