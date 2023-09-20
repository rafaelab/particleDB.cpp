# particleDB


This small package deals with particle properties.
It includes the PDG id, masses (with uncertainties), lifetimes, decay channels, etc.

Information about individual particles are taken from [SciKit-HEP](https://github.com/scikit-hep/particle/blob/master/src/particle/data/particle2022.csv), which provides very similar functionality.
	
The underlying data is taken from the Particle Data Group (2022 edition).

The database of decays is taken from [PYTHIA 8.3](https://github.com/mortenpi/pythia8/blob/master/xmldoc/).
It is created by an external script written in Julia and written as csv file.


## Requirements

The main requirement for using *particleDB* is C++17.


## Installation

To install *particleDGB*, follow the instructions below.

1. Download the latest version of the code.
```
git clone https://github.com/rafaelab/particleDB.cpp.git
```

2. Navigate into the downloaded folder and create a folder called "build/".

3. Install the code with CMake and then make:
```
cmake ..
make
make install
```
This will make the installed software (probably) accessible from everywhere in your computer. 

Personally, I prefer to install everything locally, so from the `build/` folder I type:
```
cmake .. -DCMAKE_INSTALL_PREFIX=$PWD
```
Afterwards, to access the code anywhere in your computer, you have to export the header files.
To do this, simply input in your `.bashrc` (or `.profile` or equivalent)
```
export C_INCLUDE_PATH=$C_INCLUDE_PATH:/path/to/build/include
```
The generated library (libparticleDB.so or libparticleDB.dylib) should also be exported:
```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/path/to/build/lib
```

If the code was properly compiled, you are ready to go!


## Example

The code can be used in a straightforward way by defining a `Database`, which loads particle properties and optionally their decay channels.
```
	Database* db = new Database();
```

Individual particles can be read off this database using their PDG id:
```
	Particle p = db->particleFromId(211);
	std::cout << p << std::endl;
```

If decay data is available, which can be checked with `p.isDecayDataAvailable()`, the `i`-th decay mode can be obtained as follows:
```
	double br = p.getDecayBranchingRatioForChannel(i);
	std::vector<int> secs = p.getDecayProductsForChannel(i);
```



 
 
