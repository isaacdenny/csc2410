# CSC2710 - Assembly Lab

## Simple Sum

![GDB Session](https://github.com/isaacdenny/csc2410/blob/main/lab8/screenshots/gdb_simple.png)

### Step by step walkthrough

```
   0x5655619d <+0>:     lea    ecx,[esp+0x4]
   0x565561a1 <+4>:     and    esp,0xfffffff0
   0x565561a4 <+7>:     push   DWORD PTR [ecx-0x4]
   0x565561a7 <+10>:    push   ebp
   0x565561a8 <+11>:    mov    ebp,esp
   0x565561aa <+13>:    push   ebx
   0x565561ab <+14>:    push   ecx
   0x565561ac <+15>:    sub    esp,0x10
```
These instructions are somewhat unrelated to the C code: they primarily setup the pointers for memory allocation on the stack
1. Load the address of the local variable area (stack pointer `esp` + 4) into `ecx`
2. Align the stack pointer to 16-byte boundary for performance
3. Push the old base pointer `ebp` onto the stack
4. Push the base pointer of the previous frame onto the stack
5. Set the current base pointer to the current stack pointer
6 & 7. Save registers `ebx` and `ecx` to preserve across function calls
8. Allocate space on stack for local variables

---

```
   0x565561af <+18>:    call   0x565561f8 <__x86.get_pc_thunk.ax>
   0x565561b4 <+23>:    add    eax,0x2e24
=> 0x565561b9 <+28>:    mov    DWORD PTR [ebp-0x14],0x5
   0x565561c0 <+35>:    mov    DWORD PTR [ebp-0x10],0x7
```

This is where we initialize variables for our algorithm. The first and second lines set up the function and the program counter, wheras the third and fourth lines store values 5 and 7 in variables at specific stack offsets (`ebp-0x14` and `ebp-0x10`).

---

```
   0x565561c7 <+42>:    mov    ecx,DWORD PTR [ebp-0x14]
   0x565561ca <+45>:    mov    edx,DWORD PTR [ebp-0x10]
   0x565561cd <+48>:    add    edx,ecx
   0x565561cf <+50>:    mov    DWORD PTR [ebp-0xc],edx
```

These instructions move the values from the stack to registers `ecx` and `edx`, add them on line 3, and then store the result back on the stack.

---

```
   0x565561d2 <+53>:    sub    esp,0x8
   0x565561d5 <+56>:    push   DWORD PTR [ebp-0xc]
   0x565561d8 <+59>:    lea    edx,[eax-0x1fd0]
   0x565561de <+65>:    push   edx
   0x565561df <+66>:    mov    ebx,eax
```

Everything here relates to the printf function. Line 1 reserves space on the stack for the printf arguments, then pushes the value of `result` onto the stack as the first argument. Then on line 3 the program loads the format string into `edx`, then pushes it onto the stack as the second argument to printf. Finally we move `eax` to `ebx` to preserve register state before the call.

---

```
0x565561e1 <+68>:    call   0x56556050 <printf@plt>
```

This line calls the printf function to print the result

---

```
   0x565561e6 <+73>:    add    esp,0x10
   0x565561e9 <+76>:    mov    eax,0x0
   0x565561ee <+81>:    lea    esp,[ebp-0x8]
   0x565561f1 <+84>:    pop    ecx
   0x565561f2 <+85>:    pop    ebx
   0x565561f3 <+86>:    pop    ebp
   0x565561f4 <+87>:    lea    esp,[ecx-0x4]
   0x565561f7 <+90>:    ret
```

Finally, this bit of code cleans up the stack by adjusting the stack pointer on line 1, prepares the return value of zero on line 2, restores the stack pointer before exiting, restores the saved registers in lines 4, 5, and 6, then returns from the function.

## Loop

![GDB Session](https://github.com/isaacdenny/csc2410/blob/main/lab8/screenshots/gdb_loop.png)

```
   0x5655619d <+0>:     lea    ecx,[esp+0x4]
   0x565561a1 <+4>:     and    esp,0xfffffff0
   0x565561a4 <+7>:     push   DWORD PTR [ecx-0x4]
   0x565561a7 <+10>:    push   ebp
   0x565561a8 <+11>:    mov    ebp,esp
   0x565561aa <+13>:    push   ebx
   0x565561ab <+14>:    push   ecx
   0x565561ac <+15>:    sub    esp,0x10
```

These lines set up the stack frame similar to the previous example

---

```
   0x565561af <+18>:    call   0x565561ff <__x86.get_pc_thunk.ax>
   0x565561b4 <+23>:    add    eax,0x2e24
=> 0x565561b9 <+28>:    mov    DWORD PTR [ebp-0x10],0x0
   0x565561c0 <+35>:    mov    DWORD PTR [ebp-0xc],0x0
```

Similar to the previous example except that we initialize our variables `sum` and `i` to `0` at different stack offsets.

---

```
   0x565561c7 <+42>:    jmp    0x565561d3 <main+54>
   0x565561c9 <+44>:    mov    edx,DWORD PTR [ebp-0xc]
   0x565561cc <+47>:    add    DWORD PTR [ebp-0x10],edx
   0x565561cf <+50>:    add    DWORD PTR [ebp-0xc],0x1
   0x565561d3 <+54>:    cmp    DWORD PTR [ebp-0xc],0x4
   0x565561d7 <+58>:    jle    0x565561c9 <main+44>
```

Here is where our for-loop logic resides. Line 1 jumps (`jmp`) to the loop condition check and then loads the value of `i` into the `edx` register on line 2. We then add the current value of `i` to `sum` on line 3 (on the stack) and increment `i` on line 4. Line 5 compares (`cmp`) `i` with 4 (the loop condition) and if it is less-than-or-equal-to (the `le` part of `jle`), it jumps back to process the next iteration.

---

```
   0x565561d9 <+60>:    sub    esp,0x8
   0x565561dc <+63>:    push   DWORD PTR [ebp-0x10]
   0x565561df <+66>:    lea    edx,[eax-0x1fd0]
   0x565561e5 <+72>:    push   edx
   0x565561e6 <+73>:    mov    ebx,eax
   0x565561e8 <+75>:    call   0x56556050 <printf@plt>
```

These lines handle printf similarly to the last example but with different stack offsets (different variables of course), and call it on the last line.

---

```
   0x565561ed <+80>:    add    esp,0x10
   0x565561f0 <+83>:    mov    eax,0x0
   0x565561f5 <+88>:    lea    esp,[ebp-0x8]
   0x565561f8 <+91>:    pop    ecx
   0x565561f9 <+92>:    pop    ebx
   0x565561fa <+93>:    pop    ebp
   0x565561fb <+94>:    lea    esp,[ecx-0x4]
   0x565561fe <+97>:    ret
```

These lines are identical to the previous example, cleaning up the stack and returning from the function.

## If Statement

![GDB Session](https://github.com/isaacdenny/csc2410/blob/main/lab8/screenshots/gdb_If_statement.png)

```
   0x5655619d <+0>:     lea    ecx,[esp+0x4]
   0x565561a1 <+4>:     and    esp,0xfffffff0
   0x565561a4 <+7>:     push   DWORD PTR [ecx-0x4]
   0x565561a7 <+10>:    push   ebp
   0x565561a8 <+11>:    mov    ebp,esp
   0x565561aa <+13>:    push   ebx
   0x565561ab <+14>:    push   ecx
   0x565561ac <+15>:    sub    esp,0x10
```

Set up the stack frame just the same as other examples

---

```
   0x565561af <+18>:    call   0x5655620b <__x86.get_pc_thunk.ax>
   0x565561b4 <+23>:    add    eax,0x2e24
=> 0x565561b9 <+28>:    mov    DWORD PTR [ebp-0x10],0xa
   0x565561c0 <+35>:    mov    DWORD PTR [ebp-0xc],0x14
```

Initialize our variables `x` to `10` and `y` to `20` on lines 3 and 4

```
   0x565561c7 <+42>:    mov    edx,DWORD PTR [ebp-0x10]
   0x565561ca <+45>:    cmp    edx,DWORD PTR [ebp-0xc]
   0x565561cd <+48>:    jge    0x565561dc <main+63>
   0x565561cf <+50>:    mov    ecx,DWORD PTR [ebp-0x10]
   0x565561d2 <+53>:    mov    edx,DWORD PTR [ebp-0xc]
   0x565561d5 <+56>:    add    edx,ecx
   0x565561d7 <+58>:    mov    DWORD PTR [ebp-0x14],edx
   0x565561da <+61>:    jmp    0x565561e5 <main+72>
```

Here is where our If-Statement logic is handled. we load `x` into `edx` on line 1 and compare it with `y` on line 2. If `x >= y` we jump to the else block (`jge`), otherwise we load `x` and `y` into registers and add them, storing the result at offset `-0x14` on line 7. Finally we jump to the end to avoid the else block.

---

```
   0x565561dc <+63>:    mov    edx,DWORD PTR [ebp-0x10]
   0x565561df <+66>:    sub    edx,DWORD PTR [ebp-0xc]
   0x565561e2 <+69>:    mov    DWORD PTR [ebp-0x14],edx
```

Our else-block is handled in these lines. we load `x` into a register, compute the result of `x - y` and store that on the stack.

---

The rest of the assembly code sets up printf, calls it, and cleans up the stack and registers before returning similar to the other examples.

## Reflection

What I learned from observing if-statements and loops in assembly
