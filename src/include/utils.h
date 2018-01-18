#ifndef UTILS_H
#define UTILS_H

#endif // UTILS_H

void *mem_copy(void *dest, const void *src, int count);
void *mem_set(void *dest, unsigned char val, int count);
unsigned short *mem_setw(unsigned short *dest, unsigned short val, int count);
int strlen(unsigned char *str);
unsigned char inportb (unsigned short _port);
void outportb (unsigned short _port, unsigned char _data);
void irq_install_handler(int irq, void (*handler)(struct regs *r));
