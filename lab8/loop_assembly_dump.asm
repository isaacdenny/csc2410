   0x5655619d <+0>:     lea    ecx,[esp+0x4]
   0x565561a1 <+4>:     and    esp,0xfffffff0
   0x565561a4 <+7>:     push   DWORD PTR [ecx-0x4]
   0x565561a7 <+10>:    push   ebp
   0x565561a8 <+11>:    mov    ebp,esp
   0x565561aa <+13>:    push   ebx
   0x565561ab <+14>:    push   ecx
   0x565561ac <+15>:    sub    esp,0x10
   0x565561af <+18>:    call   0x565561ff <__x86.get_pc_thunk.ax>
   0x565561b4 <+23>:    add    eax,0x2e24
=> 0x565561b9 <+28>:    mov    DWORD PTR [ebp-0x10],0x0
   0x565561c0 <+35>:    mov    DWORD PTR [ebp-0xc],0x0
   0x565561c7 <+42>:    jmp    0x565561d3 <main+54>
   0x565561c9 <+44>:    mov    edx,DWORD PTR [ebp-0xc]
   0x565561cc <+47>:    add    DWORD PTR [ebp-0x10],edx
   0x565561cf <+50>:    add    DWORD PTR [ebp-0xc],0x1
   0x565561d3 <+54>:    cmp    DWORD PTR [ebp-0xc],0x4
   0x565561d7 <+58>:    jle    0x565561c9 <main+44>
   0x565561d9 <+60>:    sub    esp,0x8
   0x565561dc <+63>:    push   DWORD PTR [ebp-0x10]
   0x565561df <+66>:    lea    edx,[eax-0x1fd0]
   0x565561e5 <+72>:    push   edx
   0x565561e6 <+73>:    mov    ebx,eax
   0x565561e8 <+75>:    call   0x56556050 <printf@plt>
   0x565561ed <+80>:    add    esp,0x10
   0x565561f0 <+83>:    mov    eax,0x0
   0x565561f5 <+88>:    lea    esp,[ebp-0x8]
   0x565561f8 <+91>:    pop    ecx
   0x565561f9 <+92>:    pop    ebx
   0x565561fa <+93>:    pop    ebp
   0x565561fb <+94>:    lea    esp,[ecx-0x4]
   0x565561fe <+97>:    ret