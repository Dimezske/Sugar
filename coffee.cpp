#include "coffee.h"
#include <sstream>
#include <iomanip>
 
CoffeeTracker::CoffeeTracker()
    : grams(0.0f), absCups(0)
{
}

void CoffeeTracker::addGrams(float amount)
{
    int oldCupTotal = getCupTotal();
    grams += amount;
    int newCupTotal = getCupTotal();

    if (newCupTotal > oldCupTotal)
    {
        absCups += (newCupTotal - oldCupTotal);
    }
}

float CoffeeTracker::getGrams() const
{
    return grams;
}

std::string CoffeeTracker::getCupSize() const
{
    return "200 ml";
}

int CoffeeTracker::getCupTotal() const
{
    return static_cast<int>((grams + 199) / 200);
}

float CoffeeTracker::getCups() const
{
    return grams / 200.0f;
}

float CoffeeTracker::cupsToGrams(float cups)
{
    return cups * 200.0f;
}

void CoffeeTracker::addAbsCup(int amount)
{
    absCups += amount;
}

int CoffeeTracker::getAbsCupTotal() const
{
    return absCups;
}