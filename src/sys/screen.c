#include "../include/utils.h"
#include "../include/screen.h"

unsigned static int cursor_x = 0, cursor_y = 0;
static int attrib = COLOR_WHITE;
static unsigned short *textmemptr;

void scroll() {
    unsigned blank, temp;

    /* A blank is defined as a space... we need to give it
    *  backcolor too */
    blank = 0x20 | (attrib << 8);

    /* Row 25 is the end, this means we need to scroll up */
    if(cursor_y >= 25) {
        /* Move the current text chunk that makes up the screen
        *  back in the buffer by a line */
        temp = cursor_y - 25 + 1;
        mem_copy(textmemptr, textmemptr + temp * 80, (25 - temp) * 80 * 2);

        /* Finally, we set the chunk of memory that occupies
        *  the last line of text to our 'blank' character */
        mem_setw(textmemptr + (25 - temp) * 80, blank, 80);
        cursor_y = 25 - 1;
    }
}

void move_cursor(void) {
    unsigned temp;

    /* The equation for finding the index in a linear
    *  chunk of memory can be represented by:
    *  Index = [(y * width) + x] */
    temp = cursor_y * 80 + cursor_x;

    /* This sends a command to indicies 14 and 15 in the
    *  CRT Control Register of the VGA controller. These
    *  are the high and low bytes of the index that show
    *  where the hardware cursor is to be 'blinking'. To
    *  learn more, you should look up some VGA specific
    *  programming documents. A great start to graphics:
    *  http://www.brackeen.com/home/vga */
    outportb(0x3D4, 14);
    outportb(0x3D5, temp >> 8);
    outportb(0x3D4, 15);
    outportb(0x3D5, temp);
}

void clearscreen() {
    unsigned blank;
    int i;

    /* Again, we need the 'short' that will be used to
    *  represent a space with color */
    blank = 0x20 | (attrib << 8);

    /* Sets the entire screen to spaces in our current
    *  color */
    for(i = 0; i < 25; i++)
        mem_setw(textmemptr + i * 80, blank, 80);

    /* Update out virtual cursor, and then move the
    *  hardware cursor */
    cursor_x = 0;
    cursor_y = 0;
    move_cursor();
}

void printchar(unsigned char c) {
    unsigned short *where;
    unsigned att = (unsigned int) attrib << 8;

    /* Handle a backspace, by moving the cursor back one space */
    if(c == 0x08) {
        if(cursor_x != 0) {
            cursor_x--;
        } else {
            if (!(cursor_x == 0 && cursor_y == 0)) {
                if (cursor_y != 0) cursor_y--;
                cursor_x = 79;
            }
        }
        where = textmemptr + (cursor_y * 80 + cursor_x);
        *where = ' ' | att;
    }
    /* Handles a tab by incrementing the cursor's x, but only
    *  to a point that will make it divisible by 8 */
    else if(c == 0x09) {
        cursor_x = (cursor_x + 8) & ~(8 - 1);
    }
    /* Handles a 'Carriage Return', which simply brings the
    *  cursor back to the margin */
    else if(c == '\r') {
        cursor_x = 0;
    }
    /* We handle our newlines the way DOS and the BIOS do: we
    *  treat it as if a 'CR' was also there, so we bring the
    *  cursor to the margin and we increment the 'y' value */
    else if(c == '\n') {
        cursor_x = 0;
        cursor_y++;
    }
    /* Any character greater than and including a space, is a
    *  printable character. The equation for finding the index
    *  in a linear chunk of memory can be represented by:
    *  Index = [(y * width) + x] */
    else if(c >= ' ') {
        where = textmemptr + (cursor_y * 80 + cursor_x);
        *where = c | att;	/* Character AND attributes: color */
        cursor_x++;
    }

    /* If the cursor has reached the edge of the screen's width, we
    *  insert a new line in there */
    if(cursor_x >= 80) {
        cursor_x = 0;
        cursor_y++;
    }

    scroll();
    move_cursor();
}

void printstring(unsigned char *text) {
    for (int i = 0; i < strlen(text); i++) {
        printchar(text[i]);
    }
}

void settextcolor(unsigned char forecolor, unsigned char backcolor) {
    /* Top 4 bytes are the background, bottom 4 bytes
    *  are the foreground color */
    attrib = (backcolor << 4) | (forecolor & 0x0F);
}

void init_video(void) {
    textmemptr = (unsigned short*) 0xB8000;
    clearscreen();
}
