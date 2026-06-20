#include <iostream>
#include "raylib.h"
#include "sugar.h"
#include "coffee.h"
#include "ui.h"

// Path to the background image. Update this to point at your own file.
static const char* BACKGROUND_IMAGE_PATH = "assets/image3.jpg";
//images
static const char* SUGAR_IMAGE_PATH = "assets/icons/sugar.png";
static const char* COFFEE_IMAGE_PATH = "assets/icons/coffee.png";
int main()
{
    InitWindow(1200, 800, "UI Example");
    SetTargetFPS(60);

    SugarTracker sugarTracker;
    CoffeeTracker coffeeTracker;
    //sugarTracker.addGrams(0.2f);    // black coffee
    //sugarTracker.addGrams(25.0f);   // soft drink
    //sugarTracker.addGrams(12.0f);   // coffee

    Texture2D backgroundTexture = LoadTexture(BACKGROUND_IMAGE_PATH);
    Texture2D sugarTexture = LoadTexture(SUGAR_IMAGE_PATH);
    Texture2D coffeeTexture = LoadTexture(COFFEE_IMAGE_PATH );

    bool hasBackground = backgroundTexture.id != 0;

    if (!hasBackground)
        std::cerr << "Failed to load background image: " << BACKGROUND_IMAGE_PATH << std::endl;

    Vector2 sugarPos = { 300, 200 };
    Vector2 coffeePos = { 300, 400 };

     bool itemsVisible = false;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        if (hasBackground)
        {
            // Stretch the loaded image to fill the window.
            Rectangle src = { 0, 0, (float)backgroundTexture.width, (float)backgroundTexture.height };
            Rectangle dst = { 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() };
            DrawTexturePro(backgroundTexture, src, dst, { 0, 0 }, 0.0f, WHITE);
        }
        else
        {
            ClearBackground(RAYWHITE);
        }

        DrawPanel({40, 60, 380, 450});
        DrawPanel({500, 60, 680, 250}, GREEN, BLACK);

        DrawLabel(60, 60, "Sugar Tracker UI");
        DrawBoxWithText({400, 60, 400, 600}, "Menu List");
        
        
        DrawSugarImage(sugarTexture, sugarPos);
        DrawCoffeeCupImage(coffeeTexture, coffeePos);

                
        if (DrawMenuItem(
                {420, 100, 360, 80},
                "COFFEE",
                GREEN,
                LIME))
        {
            TraceLog(LOG_INFO, "Coffee selected");
            itemsVisible = !itemsVisible;
        }
        // 3. Conditional rendering using your structural functions
        if (itemsVisible) {
               if (DrawButton({90, 640, 200, 40}, "CUPS OF COFFEE"))
               {
                   // Open coffee page
                   //coffeeTracker.addGrams(3.0f);
                   coffeeTracker.addAbsCup();
                    DrawLabel(60, 60, TextFormat("%d", coffeeTracker.getAbsCupTotal()));
               }     
        }
        //DrawSugarStats(sugarTracker);
        DrawSugarStats(sugarTracker, {60, 100, 300, 200}, BEIGE);
        DrawCoffeeStats(coffeeTracker, {60, 290, 300, 200}, BEIGE);
        /*if (DrawButton({60, 120, 200, 40}, "Add Sugar"))
        {
            // handle click
        }
        */

        if (DrawButton({90, 240, 200, 40}, "Add Sugar"))
        {
            sugarTracker.addGrams(3.0f);
        }
        if (DrawButton({90, 480, 200, 40}, "Add Coffee"))
        {
            coffeeTracker.addGrams(3.0f);
        }
        
        EndDrawing();
    }

    if (hasBackground)
        UnloadTexture(backgroundTexture);
    
    UnloadTexture(sugarTexture);
    UnloadTexture(coffeeTexture);
    
    CloseWindow();
    return 0;
}