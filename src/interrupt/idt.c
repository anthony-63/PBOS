#include <interrupt/idt.h>
#include <std/stdio.h>


idt_gate_t idt[IDT_ENTRIES];
idtr_t idtr;

void set_idt_gate(int n, uint64_t handler){
    idt[n].hfunc_addr_1 = (uint16_t)(handler & 0xFFFF);
    idt[n].selector = KERNEL_CS;
    idt[n].ist = 0;
    idt[n].zero = 0;
    idt[n].flags = 0x8E; // Interrupt is present and it is a gate
    idt[n].hfunc_addr_2 = (uint16_t)((handler & 0xFFFF0000) >> 16);
    idt[n].hfunc_addr_3 = (uint32_t)((handler & 0xFFFFFFFF00000000) >> 32);
    printf("IDT GATE %d INFO:\n", n);
    printf("\tHandler function address %x, addr_1: %x, addr_2: %x, addr_3: %x\n", handler, idt[n].hfunc_addr_1, idt[n].hfunc_addr_2, idt[n].hfunc_addr_3);
    printf("\tSelector: %x\n", idt[n].selector);
    printf("\tZero(should be 0): %x\n", idt[n].zero);
    printf("\tFlags: %x\n", idt[n].flags);
}

void set_idt(){
    idtr.base = (uint64_t)&idt;
    idtr.size = IDT_ENTRIES * sizeof(idt_gate_t) - 1;
    __asm__ __volatile__("lidt [%0]" : : "r" (&idtr));
}