#include "ui.h"
#include "sugar.h"
#include "coffee.h"

#include <sstream>
#include <iomanip>

bool DrawButton(Rectangle rect, const char* text)
{
    Vector2 mouse = GetMousePosition();
    bool hovered = CheckCollisionPointRec(mouse, rect);

    DrawRectangleRec(rect, hovered ? LIGHTGRAY : GRAY);
    DrawRectangleLinesEx(rect, 2, DARKGRAY);

    int fontSize = 20;
    int textWidth = MeasureText(text, fontSize);

    DrawText(text,
             rect.x + (rect.width - textWidth) / 2,
             rect.y + (rect.height - fontSize) / 2,
             fontSize,
             BLACK);

    return hovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}


// Renders the sugar texture at the specified screen position
bool DrawSugarImage(Texture2D texture, Vector2 position) {
    // Tint WHITE draws the texture exactly as its source file looks
    DrawTexture(texture, position.x, position.y, WHITE);
    return true; 
}

// Renders the coffee cup texture at the specified screen position
bool DrawCoffeeCupImage(Texture2D texture, Vector2 position) {
    DrawTexture(texture, position.x, position.y, WHITE);
    return true;
}


void DrawLabel(int x, int y, const char* text)
{
    DrawText(text, x, y, 20, WHITE);
}

// main implementation (full control version)
void DrawPanel(Rectangle rect, Color fillColor, Color borderColor)
{
    DrawRectangleRec(rect, Fade(fillColor, 0.5f));
    DrawRectangleLinesEx(rect, 1, borderColor);
}

// convenience overload (default version)
void DrawPanel(Rectangle rect)
{
    DrawPanel(rect, DARKGRAY, BLACK);
}

void DrawBoxWithText(Rectangle rect, const char* text)
{
    DrawRectangleRec(rect, LIGHTGRAY);
    DrawRectangleLinesEx(rect, 2, DARKGRAY);

    int fontSize = 20;
    int textWidth = MeasureText(text, fontSize);

    DrawText(text,
             rect.x + (rect.width - textWidth) / 2,
             rect.y + (rect.height - fontSize) / 2,
             fontSize,
             BLACK);
}
bool DrawMenuItem(Rectangle rect,
                  const char* text,
                  Color normalColor,
                  Color hoverColor)
{
    Vector2 mouse = GetMousePosition();
    bool hovered = CheckCollisionPointRec(mouse, rect);

    DrawPanel(rect,
              hovered ? hoverColor : normalColor,
              BLACK);

    int fontSize = 30;
    int textWidth = MeasureText(text, fontSize);

    DrawText(text,
             rect.x + (rect.width - textWidth) / 2,
             rect.y + (rect.height - fontSize) / 2,
             fontSize,
             WHITE);

    return hovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}
void DrawSugarStats(const SugarTracker& sugarTracker, Rectangle area, Color color)
{
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(2);

    ss << "Total Cup Size: " << sugarTracker.getCupSize() << "\n"
       << "------------------------\n"
       << "Total sugar today: " << sugarTracker.getGrams() << " grams\n"
       << "Equivalent cups: " << sugarTracker.getCups() << "\n"
       << "Cup count: " << sugarTracker.getCupCount();

    DrawText(
        ss.str().c_str(),
        area.x,
        area.y,
        20,
        color
    );
}

void DrawCoffeeStats(const CoffeeTracker& coffeeTracker, Rectangle area, Color color)
{
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(2);

    ss << "Total Cup Size: " << coffeeTracker.getCupSize() << "\n"
       << "------------------------\n"
       << "Total coffee today: " << coffeeTracker.getGrams() << " grams\n"
       << "Equivalent cups: " << coffeeTracker.getCups() << "\n"
       << "Cups Of Coffee: " << coffeeTracker.getCupTotal() << "\n"
       << "CUPS: " << coffeeTracker.getAbsCupTotal() << "\n";
    DrawText(
        ss.str().c_str(),
        area.x,
        area.y,
        20,
        color
    );
}
