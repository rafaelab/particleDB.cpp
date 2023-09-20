#ifndef PARTICLEDB_DATABASE_H
#define PARTICLEDB_DATABASE_H

#include <algorithm>
#include <array>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "particleDB/definitions.h"
#include "particleDB/io.h"
#include "particleDB/particle.h"
#include "particleDB/utilities.h"



namespace particleDB {


/**
 @class Database
 @brief  This class is essentially a look-up table for PDG particle properties.
 It stores several particle properties taken from the Particle Data Group (2022 edition).
 A better version of it is provided by scikit-hep:
   https://github.com/scikit-hep/particle/blob/master/src/particle/data/particle2022.csv
 This is the one used here. 
 All values are converted to S.I. units.
*/
class Database {
	protected:
		std::unordered_map<int, Particle> particleMap;
		using DatabaseIterator = typename std::unordered_map<int, Particle>::const_iterator;

	public:	
		Database(bool initialiseDecays = true);
		Database(std::vector<int> particles, bool initialiseDecays = true);
		~Database();
		void initTable(std::vector<int> particles = std::vector<int>());
		void initDecayTable(std::vector<int> particles = std::vector<int>());
		Particle* getParticleFromId(const int& id) const;
		Particle* find(const int& id) const;
		bool particleExists(const int& pId) const;
		void remove(const int& id);
		std::unordered_map<int, Particle> getParticleMap() const;
		Particle operator[](const int& pId);
};



} // namespace

#endif