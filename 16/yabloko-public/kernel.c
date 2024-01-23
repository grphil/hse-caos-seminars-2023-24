asm(".asciz \"kernel start\\n\"");

#include "console.h"
#include "cpu/isr.h"
#include "cpu/gdt.h"
#include "drivers/keyboard.h"
#include "drivers/vga.h"
#include "drivers/ata.h"
#include "drivers/misc.h"
#include "drivers/uart.h"
#include "drivers/pit.h"
#include "fs/fs.h"
#include "lib/string.h"
#include "proc.h"


void _start() {
    load_gdt();
    init_keyboard();
    uartinit();
    load_idt();
    init_pit();
    sti();

    vga_clear_screen();
    printk("\n\nYABLOKO\n");

    // char x = 0;
    // char y = 1;
    // char n = y / x;
    // printk(&n);

    printk("\n> ");
    while (1) {
        if (kbd_buf_size > 0 && kbd_buf[kbd_buf_size-1] == '\n') {
            if (!strncmp("halt\n", kbd_buf, kbd_buf_size)) {
                qemu_shutdown();
            } else if (!strncmp("sleep\n", kbd_buf, kbd_buf_size)) {
                for (int i = 0; i < 5; i++) {
                    msleep(1000);
                    printk(".");
                }
            } else if (!strncmp("run ", kbd_buf, 4)) {
                kbd_buf[kbd_buf_size-1] = '\0';
                const char* cmd = kbd_buf + 4;
                run_elf(cmd);
            } else {
                printk("unknown command, try: halt | run CMD");
            }
            kbd_buf_size = 0;
            printk("\n> ");
        }
        asm("hlt");
    }
}
