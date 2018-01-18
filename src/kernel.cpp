extern "C" {
    #include "include/screen.h"
    #include "include/keyboard.h"
    #include "include/system.h"
}

void init() {
    gdt_install();
    idt_install();
    irq_install();
    isrs_install();
    init_video();
    keyboard_install();
    __asm__ __volatile__ ("sti");
}

extern "C" void kmain(void);
__attribute__((noreturn)) void kmain() {
    init();

    settextcolor(COLOR_LIGHT_CYAN, COLOR_BLACK);
    printstring((unsigned char*) "RKerneL 0.1 'Baltika'");
    while (1);
}
