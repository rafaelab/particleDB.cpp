#ifndef PARTICLEDB_UTILITIES_H
#define PARTICLEDB_UTILITIES_H

#include <numeric>
#include <string>
#include <unistd.h>


namespace particleDB {

/**
 Returns the combined path taking care of all the slashes, etc.
*/
std::string joinPath(const std::string& s1, const std::string& s2);

/**
 Get the current path of where the code is being executed.
 From: https://stackoverflow.com/questions/5525668/how-to-implement-readlink-to-find-the-path
*/
std::string executablePath();


/**
 Get the indices that sort a given vector v.
 This is equivalent to NumPy's `argsort`.
*/
template <typename T>
std::vector<size_t> sortingIndices(const std::vector<T>& v, bool reverse = false) {
	std::vector<size_t> idx(v.size());
	std::iota(idx.begin(), idx.end(), 0);
	if (reverse) {
		std::stable_sort(idx.begin(), idx.end(), [&v](size_t i, size_t j) {return v[i] < v[j];});
	} else {
		std::stable_sort(idx.begin(), idx.end(), [&v](size_t i, size_t j) {return v[i] > v[j];});
	}

	return idx;
}




} // namespace

#endif