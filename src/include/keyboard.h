#ifndef KEYBOARD_H
#define KEYBOARD_H
#endif

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64
#define IDT_SIZE 256
#define INTERRUPT_GATE 0x8E
#define KERNEL_CODE_SEGMENT_OFFSET 0x08

#define KEY_RSHIFT 0x36;
#define KEY_LSHIFT 0x2A;

const unsigned char keymap_low[128] = {
    0,    // 0x00 - unknown
    27,   // 0x01 - Escape
    '1',  // 0x02
    '2',  // 0x03
    '3',  // 0x04
    '4',  // 0x05
    '5',  // 0x06
    '6',  // 0x07
    '7',  // 0x08
    '8',  // 0x09
    '9',  // 0x0A
    '0',  // 0x0B
    '-',  // 0x0C
    '=',  // 0x0D
    '\b', // 0x0E - Backspace
    '\t', // 0x0F - Tab
    'q',  // 0x10
    'w',  // 0x11
    'e',  // 0x12
    'r',  // 0x13
    't',  // 0x14
    'y',  // 0x15
    'u',  // 0x16
    'i',  // 0x17
    'o',  // 0x18
    'p',  // 0x19
    '[',  // 0x1A
    ']',  // 0x1B
    '\n', // 0x1C - Enter
    0,    // 0x1D - Control
    'a',  // 0x1E
    's',  // 0x1F
    'd',  // 0x20
    'f',  // 0x21
    'g',  // 0x22
    'h',  // 0x23
    'j',  // 0x24
    'k',  // 0x25
    'l',  // 0x26
    ';',  // 0x27
    '\'', // 0x28
    '`',  // 0x29
    0,    // 0x2A - Left Shift
    '\\', // 0x2B
    'z',  // 0x2C
    'x',  // 0x2D
    'c',  // 0x2E
    'v',  // 0x2F
    'b',  // 0x30
    'n',  // 0x31
    'm',  // 0x32
    ',',  // 0x33
    '.',  // 0x34
    '/',  // 0x35
    0,    // 0x36 - Right Shift
    '*',  // 0x37
    0,    // 0x38 - Alt
    ' ',  // 0x39 - Space
    0,    // 0x3A - Caps Lock
    0,    // 0x3B - F1
    0,    // 0x3C - F2
    0,    // 0x3D - F3
    0,    // 0x3E - F4
    0,    // 0x3F - F5
    0,    // 0x40 - F6
    0,    // 0x41 - F7
    0,    // 0x42 - F8
    0,    // 0x43 - F9
    0,    // 0x44 - F10
    0,    // 0x45 - Num Lock
    0,    // 0x46 - Scroll Lock
    0,    // 0x47 - Home
    0,    // 0x48 - Up Arrow
    0,    // 0x49 - Page Up
    '-',  // 0x4A
    0,    // 0x4B - Left Arrow
    0,    // 0x4C
    0,    // 0x4D - Right Arrow
    '+',  // 0x4E
    0,    // 0x4F
    0,    // 0x50 - Down Arrow
    0,    // 0x51 - Page Down
    0,    // 0x52 - Insert
    0,    // 0x53 - Delete
    0,    // 0x54
    0,    // 0x55
    0,    // 0x56
    0,    // 0x57 - F11
    0,    // 0x58 - F12
    0,    // 0x59 - unknown
};

const unsigned char keymap_high[128] = {
    0,    // 0x00 - unknown
    27,   // 0x01 - Escape
    '!',  // 0x02
    '@',  // 0x03
    '#',  // 0x04
    '$',  // 0x05
    '%',  // 0x06
    '^',  // 0x07
    '&',  // 0x08
    '*',  // 0x09
    '(',  // 0x0A
    ')',  // 0x0B
    '_',  // 0x0C
    '+',  // 0x0D
    '\b', // 0x0E - Backspace
    '\t', // 0x0F - Tab
    'Q',  // 0x10
    'W',  // 0x11
    'E',  // 0x12
    'R',  // 0x13
    'T',  // 0x14
    'Y',  // 0x15
    'U',  // 0x16
    'I',  // 0x17
    'O',  // 0x18
    'P',  // 0x19
    '{',  // 0x1A
    '}',  // 0x1B
    '\n', // 0x1C - Enter
    0,    // 0x1D - Control
    'A',  // 0x1E
    'S',  // 0x1F
    'D',  // 0x20
    'F',  // 0x21
    'G',  // 0x22
    'H',  // 0x23
    'J',  // 0x24
    'K',  // 0x25
    'L',  // 0x26
    ':',  // 0x27
    '"', // 0x28
    '~',  // 0x29
    0,    // 0x2A - Left Shift
    '|', // 0x2B
    'Z',  // 0x2C
    'X',  // 0x2D
    'C',  // 0x2E
    'V',  // 0x2F
    'B',  // 0x30
    'N',  // 0x31
    'M',  // 0x32
    '<',  // 0x33
    '>',  // 0x34
    '?',  // 0x35
    0,    // 0x36 - Right Shift
    '*',  // 0x37
    0,    // 0x38 - Alt
    ' ',  // 0x39 - Space
    0,    // 0x3A - Caps Lock
    0,    // 0x3B - F1
    0,    // 0x3C - F2
    0,    // 0x3D - F3
    0,    // 0x3E - F4
    0,    // 0x3F - F5
    0,    // 0x40 - F6
    0,    // 0x41 - F7
    0,    // 0x42 - F8
    0,    // 0x43 - F9
    0,    // 0x44 - F10
    0,    // 0x45 - Num Lock
    0,    // 0x46 - Scroll Lock
    0,    // 0x47 - Home
    0,    // 0x48 - Up Arrow
    0,    // 0x49 - Page Up
    '-',  // 0x4A
    0,    // 0x4B - Left Arrow
    0,    // 0x4C
    0,    // 0x4D - Right Arrow
    '+',  // 0x4E
    0,    // 0x4F
    0,    // 0x50 - Down Arrow
    0,    // 0x51 - Page Down
    0,    // 0x52 - Insert
    0,    // 0x53 - Delete
    0,    // 0x54
    0,    // 0x55
    0,    // 0x56
    0,    // 0x57 - F11
    0,    // 0x58 - F12
    0,    // 0x59 - unknown
};


void keyboard_install();
