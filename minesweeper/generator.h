#ifndef GENERATOR_H
#define GENERATOR_H

#include <QObject>
#include <QDateTime>
#include <time.h>
#include <bitset>
#include <iostream>

enum Type
{
    linearCongruentialBasic = 0,
    linearCongruentialConst = 1,
    linearCongruentialTimestamp = 2,
    linearCongruentialMillistamp = 3,
    cGeneratorLinear = 4
};

class Generator
{

public:
    Generator(const unsigned long long &a = 0, const unsigned long long &c = 0, const unsigned long long &m = 2,
              const unsigned long long &seed = 0, const Type &generatorType = Type::linearCongruentialBasic, const unsigned long long &bitShifting = 0);
    unsigned long long generateNumber(); //Call the needed generator
    void setGenerator(Type generatorType); //Change the generator to call

protected:
    unsigned long long linearCongruentialBasic(); //Last generated number becomes the next seed
    unsigned long long linearCongruentialConst(); //Generator with a constant seed (never changes)
    unsigned long long linearCongruentialTimestamp(); //Seed is changed every second
    unsigned long long linearCongruentialMillistamp(); //Seed is changed every millisecond
    unsigned long long cGenerator(); //C++ initial generator

private:
    unsigned long long a_; //A generator constant
    unsigned long long c_; //C generator constant
    unsigned long long m_; //M modulo constant
    unsigned long long seed_; //Default seed to use
    Type currentType_; //Current generator type
    unsigned long long LCBSeed_; //Basic generator own seed
    unsigned long long bitShifting_;
};

#endif // GENERATOR_H
