#ifndef SUGAR_H
#define SUGAR_H
/*
    MONITOR SUGAR APP for android
*/

#include <string>

class SugarTracker
{
private:
    float grams;

public:
    SugarTracker();

    void addGrams(float amount);
    float getGrams() const;
    float getCups() const;
    std::string getCupSize() const;
    int getCupCount() const;

    static float cupsToGrams(float cups);
};

#endif // SUGAR_H