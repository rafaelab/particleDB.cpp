#ifndef PARTICLEDB_IO_H
#define PARTICLEDB_IO_H

#include <filesystem>
#include <iostream>
#include <string>


#include "particleDB/utilities.h"

namespace particleDB {


std::string getDataPath(std::string filename);
std::string getInstallPrefix();



} // namespace

#endif