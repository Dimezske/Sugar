#include "sugar.h"

SugarTracker::SugarTracker()
    : grams(0.0f)
{
}

void SugarTracker::addGrams(float amount)
{
    grams += amount;
}

float SugarTracker::getGrams() const
{
    return grams;
}

float SugarTracker::getCups() const
{
    return grams / 200.0f;
}

std::string SugarTracker::getCupSize() const
{
    return "200 ml";
}

int SugarTracker::getCupCount() const
{
    return static_cast<int>((grams + 199) / 200);
}

float SugarTracker::cupsToGrams(float cups)
{
    return cups * 200.0f;
}