#ifndef PARTICLES_DATABASE_H
#define PARTICLES_DATABASE_H

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

#include "particles/definitions.h"
#include "particles/io.h"
#include "particles/particle.h"



namespace particles {


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

	public:	
		Database(bool initialiseDecays = true);
		~Database() = default;
		void initTable();
		void initDecayTable();
		Particle particleFromId(const int& id) const;
		Particle find(const int& id) const;
		bool particleExists(const int& pId) const;
		std::unordered_map<int, Particle> getParticleMap() const;
		Particle operator[](const int& pId);
};



} // namespace

#endif