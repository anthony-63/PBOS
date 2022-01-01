OUTPUT_FORMAT(elf64-x86-64)
OUTPUT_ARCH(i386:x86-64)

ENTRY(_start)

PHDRS {
    null   PT_NULL FLAGS(0); /* null segment */
    text   PT_LOAD FLAGS((1 << 0) | (1 << 2)); /* Execute + read perms */
    rodata PT_LOAD FLAGS((1 << 2)); /* Read only perms */
    data   PT_LOAD FLAGS((1 << 1) | (1 << 2)); /* Write + read perms  */
}

SECTIONS {
    /* stivale2 spec mandates that the os is loaded into the topmost 2gb */
    . = 0xffffffff80000000;
    .text : {
        *(.text .text.*)
    } :text


    /* move to the next mem page for rodata */
    . += CONSTANT(MAXPAGESIZE);

    /* place stivale2hdr in its own seciton */
    .stivale2hdr : {
        KEEP(*(.stivale2hdr))
    } :rodata

    .rodata : {
        *(.rodata .rodata.*)
    } :rodata
 
    /* move to the next mem page for data */
    . += CONSTANT(MAXPAGESIZE);
 
    .data : {
        *(.data .data.*)
    } :data
 
    .bss : {
        *(COMMON)
        *(.bss .bss.*)
    } :data
}