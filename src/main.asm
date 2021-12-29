org 0x7c00
bits 16

start:
	; set up the data segs
	mov ax, 0
	mov ds, ax
	mov es, ax

	mov ss, ax
	mov sp, 0x7c00

	; classic hello world!
	mov si, hello_world
	call puts

	hlt

	.halt:
		jmp .halt
; prints a string
; args:
;		ds:si - points to a string
puts:
	; save regs to modify
	push si
	push ax
.ploop:
	lodsb ; loads next char in al
	or al, al ; check if next char is null
	jz .pdone ; if so then jump to done label
	mov ah, 0x0e
	int 0x10
	jmp .ploop

.pdone:
		; restore regs modified
	pop ax
	pop si
	ret

hello_world: db 'Hello world!', 0x0D, 0x0A, 0

times 510-($-$$) db 0
dw 0x0AA55
