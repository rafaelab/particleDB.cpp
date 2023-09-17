#ifndef PARTICLES_UTILITIES_H
#define PARTICLES_UTILITIES_H

#include <string>
#include <unistd.h>


namespace particles {

std::string joinPath(const std::string& s1, const std::string& s2);

/**
 From: https://stackoverflow.com/questions/5525668/how-to-implement-readlink-to-find-the-path
*/
std::string executablePath(const std::string& s);


} // namespace

#endif