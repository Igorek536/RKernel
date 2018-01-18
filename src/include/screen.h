#ifndef SCREEN_H
#define SCREEN_H
#endif

#define COLOR_BLACK 0x00         // 0 - Black
#define COLOR_BLUE 0x01          // 1 - Blue
#define COLOR_GREEN 0x02         // 2 - Green
#define COLOR_CYAN 0x03          // 3 - Cyan
#define COLOR_RED 0x04           // 4 - Red
#define COLOR_MAGENTA 0x05       // 5 - Magenta
#define COLOR_BROWN 0x06         // 6 - Brown
#define COLOR_LIGHT_GREY 0x07    // 7 - Light Grey
#define COLOR_DARK_GREY 0x08     // 8 - Dark Grey
#define COLOR_LIGHT_BLUE 0x09    // 9 - Light Blue
#define COLOR_LIGHT_GREEN 0x0A   // 10/a - Light Green
#define COLOR_LIGHT_CYAN 0x0B    // 11/b - Light Cyan
#define COLOR_LIGHT_RED 0x0C     // 12/c - Light Red
#define COLOR_LIGHT_MAGENTA 0x0D // 13/d - Light Magenta
#define COLOR_LIGHT_BROWN 0x0E   // 14/e - Light Brown
#define COLOR_WHITE 0x0F         // 15/f – White

void clearscreen();
void printchar(unsigned char c);
void printstring(unsigned char *text);
void settextcolor(unsigned char forecolor, unsigned char backcolor);
void init_video(void);
