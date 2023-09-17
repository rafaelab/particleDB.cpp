#include "particleDB/io.h"

namespace particleDB {


std::string getDataPath(std::string filename) {

	static std::string dataPath;
	if (dataPath.size())
		return joinPath(dataPath, filename);

	const char* envPath = getenv("PARTICLES_DATA_PATH");
	if (envPath) {
		if (std::filesystem::is_directory(envPath)) {
			dataPath = envPath;
			return joinPath(dataPath, filename);
		}
	}

	#ifdef PARTICLES_INSTALL_PREFIX
	{
		std::string _path = PARTICLES_INSTALL_PREFIX "/share/data/particles";
		if (std::filesystem::is_directory(_path)) {
			dataPath = _path;
			return joinPath(dataPath, filename);
		}
	}
	#endif
	
	dataPath = "data";

	return joinPath(dataPath, filename);
}


std::string getInstallPrefix() {
	std::string path = "";
	#ifdef PARTICLES_INSTALL_PREFIX
		path += PARTICLES_INSTALL_PREFIX;
	#endif

  return path;
};



} // namespace