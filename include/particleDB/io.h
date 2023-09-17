#ifndef PARTICLEDB_IO_H
#define PARTICLEDB_IO_H

#include <filesystem>
#include <iostream>


#include "particleDB/utilities.h"

namespace particleDB {

/**
 Explicitly copied (and adjusted) from CRPropa's Common.h/.cc files.
*/
std::string getDataPath(std::string filename);
std::string getInstallPrefix();



} // namespace

#endif