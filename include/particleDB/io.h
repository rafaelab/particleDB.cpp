#ifndef PARTICLES_IO_H
#define PARTICLES_IO_H

#include <filesystem>
#include <iostream>


#include "particles/utilities.h"

namespace particles {

/**
 Explicitly copied (and adjusted) from CRPropa's Common.h/.cc files.
*/
std::string getDataPath(std::string filename);
std::string getInstallPrefix();



} // namespace

#endif