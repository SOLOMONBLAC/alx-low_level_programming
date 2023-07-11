#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_error(const char* message) {
    fprintf(stderr, "%s\n", message);
    exit(98);
}

void print_elf_header(const Elf32_Ehdr* header) {
    int i;

    printf("Magic:   ");
    for (i = 0; i < EI_NIDENT; ++i) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");

    printf("Class:                             ");
    switch (header->e_ident[EI_CLASS]) {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("Invalid\n");
            break;
    }

    printf("Data:                              ");
    switch (header->e_ident[EI_DATA]) {
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("Invalid\n");
            break;
    }

    printf("Version:                           %d (current)\n", header->e_ident[EI_VERSION]);

    printf("OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("UNIX System V ABI\n");
            break;
        case ELFOSABI_LINUX:
            printf("Linux ABI\n");
            break;
        default:
            printf("Other\n");
            break;
    }

    printf("ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

    printf("Type:                              ");
    switch (header->e_type) {
        case ET_NONE:
            printf("No file type\n");
            break;
        case ET_REL:
            printf("Relocatable file\n");
            break;
        case ET_EXEC:
            printf("Executable file\n");
            break;
        case ET_DYN:
            printf("Shared object file\n");
            break;
        case ET_CORE:
            printf("Core file\n");
            break;
        default:
            printf("Other\n");
            break;
    }

    printf("Entry point address:               0x%lx\n", (unsigned long)header->e_entry);
}

void print_elf_header_info(const char* filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        print_error("Failed to open the file");
    }

    Elf32_Ehdr header;
    ssize_t bytes_read;

    if ((bytes_read = read(fd, &header, sizeof(header))) != sizeof(header)) {
        print_error("Failed to read the ELF header");
    }

    if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3) {
        print_error("Not an ELF file");
    }

    print_elf_header(&header);
    close(fd);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        print_error("Usage: elf_header elf_filename");
    }

    print_elf_header_info(argv[1]);

    return 0;
}

