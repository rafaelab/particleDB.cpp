#ifndef PARTICLEDB_IO_H
#define PARTICLEDB_IO_H

#include <filesystem>
#include <iostream>
#include <string>


#include "particleDB/utilities.h"

namespace particleDB {


/**
 * Functions to read data files.
*/
std::filesystem::path getDataPath(std::string filename);
std::filesystem::path getInstallPrefix();



} // namespace

#endif