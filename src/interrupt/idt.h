#ifndef PBOS_IDT
#define PBOS_IDT

#include <stdint.h>

#define KERNEL_CS 0x28

typedef struct {
    uint16_t hfunc_addr_1;
    uint16_t selector;
    uint8_t  ist;
    // First byte:
    /*
    Bit 7: "Interrupt is present"
    Bits 6-5: Permission ring, 0: kernel-3: user
    Bit 4: Set to 0 for interrupt gates
    Bits 3-0: Bits 1110 = dec 14 = "32 bit interrupt gate"
    */
    uint8_t flags;
    uint16_t hfunc_addr_2;
    uint32_t hfunc_addr_3;

    uint32_t zero;

} __attribute__((packed)) idt_gate_t;

typedef struct {
    uint16_t size;
    uint64_t base;
} __attribute__((packed)) idtr_t;

#define IDT_ENTRIES 256

void set_idt_gate(int n, uint64_t handler);
void set_idt();

#endif