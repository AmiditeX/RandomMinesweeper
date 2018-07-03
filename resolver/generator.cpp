#include "generator.h"

Generator::Generator(const unsigned long long &a, const unsigned long long &c, const unsigned long long &m, const unsigned long long &seed,
                     const Type &generatorType, const unsigned long long &bitShifting)
    : a_(a), c_(c), seed_(seed), currentType_(generatorType), LCBSeed_(seed), bitShifting_(bitShifting)
{
    if(m != 0) //Input sanitization (modulo 0 gives undefined results)
    {
        m_ = m;
    }
    else //If m == 0, m is kept with default value (2)
    {
        m_ = 2;
    }

    srand(time(NULL)); //Initiate C++ generator
}

//Call the needed generator
unsigned long long Generator::generateNumber()
{
    switch(currentType_)
    {
    case Type::linearCongruentialBasic:
        return linearCongruentialBasic();

    case Type::linearCongruentialConst:
        return linearCongruentialConst();

    case Type::linearCongruentialTimestamp:
        return linearCongruentialTimestamp();

    case Type::linearCongruentialMillistamp:
        return linearCongruentialMillistamp();

    case Type::cGeneratorLinear:
        return cGenerator();

    default:
        return -1;
    }
}

//Change the generator to call
void Generator::setGenerator(Type generatorType)
{
    currentType_ = generatorType;
}

//Last generated number becomes the next seed
unsigned long long Generator::linearCongruentialBasic()
{
    unsigned long long result;
    result = ((a_ * LCBSeed_) + c_) % m_;
    LCBSeed_ = result;
    //std::cout << "Result " << std::bitset<64>(result) << std::endl;
    if(bitShifting_ != 0) //Do bitshifting to increase entropy
    {
        result = result >> bitShifting_;
    }
    //std::cout << "Result bitshifted " << std::bitset<64>(result) << std::endl;
    return result;
    //Generator has its own seed variable to avoid interfering
    //with other generator by changing the default seed
}

//Generator with a constant seed (never changes)
unsigned long long Generator::linearCongruentialConst()
{
    unsigned long long result;
    result = ((a_ * seed_) + c_) % m_;
    return result;
}

//Seed is changed every second
unsigned long long Generator::linearCongruentialTimestamp()
{
    unsigned long long result;
    QDateTime t = QDateTime::currentDateTime();
    uint timestamp = t.toTime_t();
    result = ((a_ * timestamp) + c_) % m_;
    return result;
}

//C++ initial generator
unsigned long long Generator::cGenerator()
{
    return rand();
}

//Seed is changed every millisecond
unsigned long long Generator::linearCongruentialMillistamp()
{
    unsigned long long result;
    QDateTime t = QDateTime::currentDateTime();
    uint timestamp = t.currentMSecsSinceEpoch();
    result = ((a_ * timestamp) + c_) % m_;
    return result;
}
