[org 0x7c00]
KERNEL_OFFSET equ 0x1000

mov [BOOT_DRIVE], dl
mov bp, 0x9000
mov sp, bp

mov bx, KERNEL_OFFSET
mov dh, 15
mov dl, [BOOT_DRIVE]
call disk_load

call switch_to_pm
jmp $

BOOT_DRIVE db 0

times 510-($-$$) db 0
dw 0xaa55
