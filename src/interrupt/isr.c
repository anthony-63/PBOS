#include <interrupt/isr.h>
#include <std/stdio.h>
#include <interrupt/idt.h>
#include <std/stdlib.h>
#define ISR_COMMON_STUB \
    __asm__(\
        "isr_common_stub:\n" \
        "push rax\n" \
        "push rcx\n" \
        "push rdx\n" \
        "push rbx\n" \
        "push rbp\n" \
        "push rsi\n" \
        "push rdi\n" \
        "mov ax, ds\n" \
        "push rax\n" \
        "mov ax, 0x10\n" \
        "mov ds, ax\n" \
        "mov es, ax\n" \
        "mov fs, ax\n" \
        "mov gs, ax\n" \
        "call %P0\n" : : "i" (isr_handler)); \
        __asm__( \
        "pop rax\n" \
        "mov ds, ax\n" \
        "mov es, ax\n" \
        "mov fs, ax\n" \
        "mov gs, ax\n" \
        "pop rax\n" \
        "pop rcx\n" \
        "pop rdx\n" \
        "pop rbx\n" \
        "pop rbp\n" \
        "pop rsi\n" \
        "pop rdi\n" \
        "add esp, 8\n" \
        "sti\n" \
        "iret\n" \
    )

void isr0(){
    ISR_COMMON_STUB;
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 0"
        "\njmp isr_common_stub"
    );
}
void isr1(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 1"
        "\njmp isr_common_stub"
    );
}
void isr2(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 2"
        "\njmp isr_common_stub"
    );
}
void isr3(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 3"
        "\njmp isr_common_stub"
    );
}
void isr4(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 4"
        "\njmp isr_common_stub"
    );
}
void isr5(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 5"
        "\njmp isr_common_stub"
    );
}
void isr6(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 6"
        "\njmp isr_common_stub"
    );
}
void isr7(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 7"
        "\njmp isr_common_stub"
    );
}
void isr8(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 8"
        "\njmp isr_common_stub"
    );
}
void isr9(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 9"
        "\njmp isr_common_stub"
    );
}
void isr10(){
    __asm__(
        "cli\n"
        "\npush 10"
        "\njmp isr_common_stub"
    );
}
void isr11(){
    __asm__(
        "cli\n"
        "\npush 11"
        "\njmp isr_common_stub"
    );
}
void isr12(){
    __asm__(
        "cli\n"
        "\npush 12"
        "\njmp isr_common_stub"
    );
}
void isr13(){
    __asm__(
        "cli\n"
        "\npush 13"
        "\njmp isr_common_stub"
    );
}
void isr14(){
    __asm__(
        "cli\n"
        "\npush 14"
        "\njmp isr_common_stub"
    );
}
void isr15(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 15"
        "\njmp isr_common_stub"
    );
}
void isr16(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 16"
        "\njmp isr_common_stub"
    );
}
void isr17(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 17"
        "\njmp isr_common_stub"
    );
}
void isr18(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 18"
        "\njmp isr_common_stub"
    );
}
void isr19(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 19"
        "\njmp isr_common_stub"
    );
}
void isr20(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 20"
        "\njmp isr_common_stub"
    );
}
void isr21(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 21"
        "\njmp isr_common_stub"
    );
}
void isr22(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 22"
        "\njmp isr_common_stub"
    );
}
void isr23(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 23"
        "\njmp isr_common_stub"
    );
}
void isr24(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 24"
        "\njmp isr_common_stub"
    );
}
void isr25(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 25"
        "\njmp isr_common_stub"
    );
}
void isr26(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 26"
        "\njmp isr_common_stub"
    );
}
void isr27(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 27"
        "\njmp isr_common_stub"
    );
}
void isr28(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 28"
        "\njmp isr_common_stub"
    );
}
void isr29(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 29"
        "\njmp isr_common_stub"
    );
}
void isr30(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 30"
        "\njmp isr_common_stub"
    );
}
void isr31(){
    __asm__(
        "cli\n"
        "\npush 0"
        "\npush 31"
        "\njmp isr_common_stub"
    );
}

void isr_install() {
    set_idt_gate(0, (uint64_t)isr0);
    set_idt_gate(1, (uint64_t)isr1);
    set_idt_gate(2, (uint64_t)isr2);
    set_idt_gate(3, (uint64_t)isr3);
    set_idt_gate(4, (uint64_t)isr4);
    set_idt_gate(5, (uint64_t)isr5);
    set_idt_gate(6, (uint64_t)isr6);
    set_idt_gate(7, (uint64_t)isr7);
    set_idt_gate(8, (uint64_t)isr8);
    set_idt_gate(9, (uint64_t)isr9);
    set_idt_gate(10, (uint64_t)isr10);
    set_idt_gate(11, (uint64_t)isr11);
    set_idt_gate(12, (uint64_t)isr12);
    set_idt_gate(13, (uint64_t)isr13);
    set_idt_gate(14, (uint64_t)isr14);
    set_idt_gate(15, (uint64_t)isr15);
    set_idt_gate(16, (uint64_t)isr16);
    set_idt_gate(17, (uint64_t)isr17);
    set_idt_gate(18, (uint64_t)isr18);
    set_idt_gate(19, (uint64_t)isr19);
    set_idt_gate(20, (uint64_t)isr20);
    set_idt_gate(21, (uint64_t)isr21);
    set_idt_gate(22, (uint64_t)isr22);
    set_idt_gate(23, (uint64_t)isr23);
    set_idt_gate(24, (uint64_t)isr24);
    set_idt_gate(25, (uint64_t)isr25);
    set_idt_gate(26, (uint64_t)isr26);
    set_idt_gate(27, (uint64_t)isr27);
    set_idt_gate(28, (uint64_t)isr28);
    set_idt_gate(29, (uint64_t)isr29);
    set_idt_gate(30, (uint64_t)isr30);
    set_idt_gate(31, (uint64_t)isr31);
    set_idt();
}

char *exception_messages[] = {
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",

    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",

    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",

    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

void isr_handler(registers_t r) {
    printf("Received interrupt: 0x%x\n", r.int_no);
    printf("Type of interrupt: %s\n", exception_messages[r.int_no]);
}