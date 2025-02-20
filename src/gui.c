#include "gui.h"
#include "raylib.h"
#include <stdio.h>
static void error_callback(int error, const char *description) {
  fprintf(stderr, "Error : %s\n", description);
}

void init_gui(void) {
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(800, 600, "Obang");
}

void update_gui(void) {
  BeginDrawing();
  ClearBackground(RAYWHITE);
  DrawText("Hello, World!", 20, 20, 20, BLACK);
  EndDrawing();
}

void clean_gui(void) {
  CloseWindow();
}
