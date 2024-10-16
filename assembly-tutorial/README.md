# Assembly Tutorial - Classwork

## 1 - Basic Instruction Tracing

```
mov eax, 5
mov ebx, 3
add eax, ebx
```

Final value in eax is `8`

---

## 2 - Conditional Branching

```
mov eax, 10
cmp eax, 5
jg greater_label
mov eax, 1
jmp end_label

greater_label:
mov eax, 0

end_label:

```

The CPU will jump to greater_label because the value of eax is 10 which is greater than 5. The final value of eax will be 0 due to the line `mov eax, 0`

## 3 - Loop Tracing with Conditional Check

```
mov ecx, 5
mov eax, 0

loop_start: <5, 4, 3, 2, 1, 0, jump>
add eax, 1
cmp ecx, 0
je end_loop
sub ecx, 1
jmp loop_start

end_loop:

```

The loop_start block will execute 6 times (5 to decrement, the 6th one fails the check). The final value stored in eax is 6 (starts at 0 runs 6 times).

## 4 - Understanding Flags

```
mov eax, 3
sub eax, 3
cmp eax, 0 <equal>
je zero_label

zero_label

```

The CPU will jump to the zero_label because the value in eax is zero. The Zero Flag (ZF) determines whether the jump occurs. If the instruction were changed to `sub eax, 2`, the jump would not occur

## 5 - Memory Addressing

```
mov eax, [0x1000]
mov [ebx], 5

```

Eax will have the value 10 after the first line. The value 5 will be stored at 0x2000

## 6 - Data Types

```
mov al, 0xFF
mov ah, 0x00

```

The full value will be 0x00FF. If the instruction `mov eax, 0xFFFFFFFF` was added next, the value in eax would be `0xFFFFFFFF`.

## 7 - Realistic Endianness Example

The value will be laid out in memory like so:

```
0x2000 CD
0x2001 AB
0x2002 34
0x2003 12
```

## 8 - Conditional Logic II

```
mov eax, 8
cmp eax, 10
jle less_or_equal_label
mov eax, 15
jmp end_label

less_or_equal_label:
mov eax, 5

end_label:
```

The value of eax after the code executes will be 5, because 8 < 10, so the program jumps to the less_or_equal_label

## 9 - Disassembly of a Function

```
0x08049060 <+0>:    mov    eax,0x0          
0x08049065 <+5>:    mov    ebx,0x14         
0x0804906a <+10>:   and    eax,0x1          
0x0804906d <+13>:   jne    0x08049075       
0x0804906f <+15>:   call   print_eax        
0x08049075 <+20>:   inc    eax              
0x08049078 <+23>:   cmp    eax,ebx          
0x0804907b <+26>:   jle    0x0804906a       
0x08049080 <+31>:   call   exit_program
```

eax is given `0x0` to start, then anded in line 3 with `0x1`, resulting in `0x0`, then the program jumps to another part of the code, skipping the print_eax call. We then increment eax and compare it to the loop condition (`eax <= 0x14`). If eax is still lower than 20 (`0x14`), then we continue back to the 3rd line to `and` `0x1` with the incremented value. This essentially checks if the value is even or odd. If the value is even then we skip the print statement; so this program prints all of the odd values between 0 and 20.


