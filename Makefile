ASM=nasm
SRC=src
BIN=bin

$(BIN)/main_flp.img: $(BIN)/main.bin
	cp $(BIN)/main.bin $(BIN)/main_flp.img
	truncate -s 1440k $(BIN)/main_flp.img

$(BIN)/main.bin: $(SRC)/main.asm
	$(ASM) $(SRC)/main.asm -f bin -o $(BIN)/main.bin

.PHONY: run

run:
	qemu-system-i386 -fda $(BIN)/main_flp.img
