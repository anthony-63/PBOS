#include <stdint.h>
#include <stddef.h>
#include <std/stdio.h>
#include <stivale2.h>

static uint8_t stack[8192];

static struct stivale2_header_tag_terminal terminal_hdr_tag = {
    .tag = {
        .identifier = STIVALE2_HEADER_TAG_TERMINAL_ID,
        .next = 0,
    },
    .flags = 0,
};

static struct stivale2_header_tag_framebuffer framebuffer_hdr_tag = {
    .tag = {
        .identifier = STIVALE2_HEADER_TAG_FRAMEBUFFER_ID,
        .next = (uint64_t)&terminal_hdr_tag,
    },
    .framebuffer_width = 0,
    .framebuffer_height = 0,
    .framebuffer_bpp = 0,
};

__attribute__((section(".stivale2hdr"), used))
static struct stivale2_header stivale2_hdr = {
    .entry_point = 0,
    .stack = (uintptr_t)stack + sizeof(stack),

    .flags = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4),
    .tags = (uintptr_t)&framebuffer_hdr_tag,
};

void* stivale2_get_tag(struct stivale2_struct* stivale2_struct, uint64_t id) {
    struct stivale2_tag *ctag = (void*)stivale2_struct->tags;
    for(;;) {
        if(ctag == NULL) {
            return NULL;
        }
        if(ctag->identifier == id) {
            return ctag;
        }
        ctag = (void*)ctag->next;
    }
}



void _start(struct stivale2_struct* stivale2_struct) {
    struct stivale2_struct_tag_terminal* term_struct_tag;
    term_struct_tag = stivale2_get_tag(stivale2_struct, STIVALE2_STRUCT_TAG_TERMINAL_ID);
    if(term_struct_tag == NULL) {
        for(;;) {
            asm("hlt");
        }
    }
    stdio_init(term_struct_tag);
    printf("Bootloader brand: %s\n", stivale2_struct->bootloader_brand);
    printf("Bootloader version: %x\n", stivale2_struct->bootloader_version);
    printf("Framebuffer tag address: %x\n", &framebuffer_hdr_tag);
    printf("Stivale2 header address: %x\n", &stivale2_hdr);
    for(;;) {
        asm("hlt");
    }
}