#include "../include/utils.h"

/* Копирует 'count' байт данных из 'src' в 'dest'.
 * Возвращает 'dest'.
 */
void *mem_copy(void *dest, const void *src, int count) {
    const char *sp = (const char*)src;
    char *dp = (char*)dest;
    for(; count != 0; count--) *dp++ = *sp++;
    return dest;
}

/* Устанавливает 'count' байт в 'dest' из 'val'.
 * Возвращает 'dest'.
 */
void *mem_set(void *dest, unsigned char val, int count) {
    char *temp = (char*)dest;
    for( ; count != 0; count--) *temp++ = sizeof(val);
    return dest;
}

/* Тоже самое что метод выше, но тут мы работаем c 16 битным 'val'
 * и 'dest'. (16 бит - 2 байта - WORD)
 */
unsigned short *mem_setw(unsigned short *dest, unsigned short val, int count) {
    unsigned short *temp = (unsigned short *)dest;
    for( ; count != 0; count--) *temp++ = val;
    return dest;
}

/* В простых словах, возвращает количество символов строки.
 */
int strlen(unsigned char *str) {
    int retval;
    for(retval = 0; *str != '\0'; str++) retval++;
    return retval;
}

/* Считывает порт ввода/вывода.
 * Возвращает прочитанный байт.
 */
unsigned char inportb (unsigned short _port) {
    unsigned char rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

/* Записывает байт в порт ввода/вывода.
 */
void outportb (unsigned short _port, unsigned char _data) {
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}
