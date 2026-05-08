#include <raylib.h>
#include <stdio.h>

#define SCREEN_HEIGHT 1000
#define SCREEN_WIDTH 1000

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "IMG examples");
  SetTargetFPS(60);

  Image img1 = LoadImage("./res/img1.jpg");
  ImageCrop(&img1, (Rectangle){100, 10, 280, 380});
  ImageResize(&img1, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

  Image img2 = LoadImage("./res/img2.jpg");
  ImageResize(&img2, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

  Font font2 = LoadFont("./res/custom_jupiter_crash.png");
  ImageDrawTextEx(&img2, font2, "Font loaded from png", (Vector2){20, 20}, (float)font2.baseSize, -2, WHITE);

  Image img3 = LoadImage("./res/img3.jpg");
  ImageResize(&img3, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
  ImageFormat(&img3, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
  ImageDither(&img3, 4, 4, 4, 4); // I don't understand this function, it doesn't do anything

  Image img4 = LoadImage("./res/img4.jpg");
  ImageResize(&img4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

  Texture img1Texture = LoadTextureFromImage(img1);
  Texture img2Texture = LoadTextureFromImage(img2);
  Texture img3Texture = LoadTextureFromImage(img3);
  Texture img4Texture = LoadTextureFromImage(img4);

  while (!WindowShouldClose()) {
    BeginDrawing();

    if (IsKeyPressed(KEY_A)) {
      printf("key released\n");
      ImageRotateCCW(&img4);
      UnloadTexture(img4Texture);
      img4Texture = LoadTextureFromImage(img4);
    }

    DrawTexture(img1Texture, 0, 0, WHITE);
    DrawTexture(img2Texture, 0, SCREEN_HEIGHT / 2, WHITE);
    DrawTexture(img3Texture, SCREEN_WIDTH / 2, 0, WHITE);
    DrawTexture(img4Texture, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, WHITE);
    EndDrawing();
  }

  UnloadImage(img1);
  UnloadImage(img2);
  UnloadImage(img3);
  UnloadImage(img4);

  UnloadTexture(img1Texture);
  UnloadTexture(img2Texture);
  UnloadTexture(img3Texture);
  UnloadTexture(img4Texture);
}
