#ifndef PARTICLES_PARTICLE_H
#define PARTICLES_PARTICLE_H

#include <array>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

#include "particles/definitions.h"


namespace particles {


/**
 @class Particle
 @brief This is essentially a container for information about a give particle.
 It includes the PDG id, masses (with uncertainties), lifetimes, etc.
*/
class Particle {
	protected:
		int id;
		double mass;
		double massErrorU;
		double massErrorL;
		double width;
		double widthErrorU;
		double widthErrorL;
		float isospin;
		uint8_t parityG;
		uint8_t parityC;
		uint8_t parityP;
		char antiparticleFlag;
		double charge;
		uint8_t rank;
		char status;
		std::string namePDG;
		std::string quarks;
		std::string nameTeX;
		double lifetime;
		double lifetimeErrorU;
		double lifetimeErrorL;
		std::vector<std::vector<int>> decayProducts;
		std::vector<double> decayBranchingRatios;
	
	public:
		Particle();
		~Particle() = default;

		void setId(int i);
		void setMass(double m);
		void setMassUncertaintyUpper(double dmu);
		void setMassUncertaintyLower(double dml);
		void setWidth(double w);
		void setWidthUncertaintyUpper(double dwu);
		void setWidthUncertaintyLower(double dwl);
		void setLifetime(double t);
		void setLifetimeUncertaintyUpper(double dtu);
		void setLifetimeUncertaintyLower(double dtl);
		void setIsospin(float i);
		void setParityG(uint8_t g);
		void setParityP(uint8_t p);
		void setParityC(uint8_t c);
		void setAntiparticleFlag(char anti);
		void setCharge(double q);
		void setRank(uint8_t c);
		void setStatus(char s);
		void setNamePDG(std::string s);
		void setNameTeX(std::string s);
		void setQuarks(std::string s);
		void setDecayBranchingRatios(std::vector<double> br);
		void setDecayProducts(std::vector<std::vector<int>>);

		int getId() const;
		double getMass() const; 
		double getMassUncertaintyUpper() const; 
		double getMassUncertaintyLower() const; 
		double getWidth() const; 
		double getWidthUncertaintyUpper() const; 
		double getWidthUncertaintyLower() const; 
		double getLifetime() const; 
		double getLifetimeUncertaintyUpper() const; 
		double getLifetimeUncertaintyLower() const; 
		double getCharge() const;
		float getIsospin() const;
		uint8_t getParityG() const;
		uint8_t getParityP() const;
		uint8_t getParityC() const;
		char getAntiparticleFlag() const;
		uint8_t getRank() const;
		char getStatus() const;
		std::string getNamePDG() const;
		std::string getNameTeX() const;
		std::string getQuarks() const;

		std::vector<double> getDecayBranchingRatios() const;
		std::vector<std::vector<int>> getDecayProducts() const;
		void addDecayChannel(const double& br, const std::vector<int>& sec);
		bool isUnstable() const;
		bool isStable() const;
		bool isDecayDataAvailable() const;
		double getDecayBranchingRatioForChannel(const size_t& i) const;
		std::vector<int> getDecayProductsForChannel(const size_t& i) const;
		unsigned int numberOfDecayChannels() const;


};

/** 
This function prints an object of type ParticleDataEntry in a nice way.
It only displays some information, not all properties.
*/
std::ostream& operator<<(std::ostream& os, const Particle& p);




} // namespace

#endif