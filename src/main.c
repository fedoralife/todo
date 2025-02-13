#include "db.h"
#include "sqlite3.h"
#include "test.h"
#include <raylib.h>
#include <stdio.h>
// The necessary Location for the database
#define DB "../../database/database.db"
#define RADIUS 20
void init(void) {
  sqlite3 *db;
  int opt = 0;
  int rc = sqlite3_open(DB, &db);
  char *err_msg = 0;
  databaseInit(db, rc, err_msg);
  printf("Enter option\n");
  printf("1. Insert\n");
  printf("2. Delete\n");
  scanf("%d", &opt);
  if (opt == 1) {
    insertTest(db, rc, err_msg);
  } else if (opt == 2) {
    deleteTest(db, rc, err_msg);
  } else {
    printf("No input specified\n");
  }
  sqlite3_close(db);
}
void _drawinit(void) {
  InitWindow(800, 800, "Obang");
  SetTargetFPS(60);
}

void _update(void) {
  while (!WindowShouldClose()) {
    Vector2 mousept = GetMousePosition();
    Color color = WHITE;
    int width = GetScreenWidth();
    int height = GetScreenHeight();
    Vector2 a = {width, height};
    if (CheckCollisionPointCircle(mousept, a, RADIUS)) {
      if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        color = BLACK;
        ClearBackground(color);
        DrawCircle(width - 50, height - 700, RADIUS, WHITE);
      }
    }
    BeginDrawing();
    ClearBackground(color);
    ShowCursor();
    DrawCircle(width - 50, height - 700, RADIUS, DARKGRAY);
    EndDrawing();
  }
}
int main(void) {
  // init();
  _drawinit();
  _update();
  CloseWindow();
  return 0;
}
