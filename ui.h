#ifndef UI_H
#define UI_H

#include "raylib.h"

class SugarTracker;
class CoffeeTracker;

bool DrawButton(Rectangle rect, const char* text);
bool DrawSugarImage(Texture2D texture, Vector2 position);
bool DrawCoffeeCupImage(Texture2D texture, Vector2 position);

void DrawLabel(int x, int y, const char* text);
void DrawPanel(Rectangle rect);
void DrawPanel(Rectangle rect, Color fillColor, Color borderColor);
void DrawBoxWithText(Rectangle rect, const char* text);
bool DrawMenuItem(Rectangle rect, const char* text, Color normalColor, Color hoverColor);

void DrawSugarStats(const SugarTracker& sugarTracker, Rectangle area, Color color);
void DrawCoffeeStats(const CoffeeTracker& coffeeTracker, Rectangle area, Color color);

#endif
