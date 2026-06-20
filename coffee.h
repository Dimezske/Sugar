#ifndef COFFEE_H
#define COFFEE_H
#include <string>

class CoffeeTracker
{
private:
    float grams;
    int absCups;
public:
    CoffeeTracker();

    void addGrams(float amount);
    float getGrams() const;
    std::string getCupSize() const;
    
    float getCups() const;
    int getCupTotal() const;

    static float cupsToGrams(float cups);

    void addAbsCup(int amount = 1);
    int getAbsCupTotal() const;
};

#endif // COFFEE_H