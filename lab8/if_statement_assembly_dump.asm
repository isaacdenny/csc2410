   0x5655619d <+0>:     lea    ecx,[esp+0x4]
   0x565561a1 <+4>:     and    esp,0xfffffff0
   0x565561a4 <+7>:     push   DWORD PTR [ecx-0x4]
   0x565561a7 <+10>:    push   ebp
   0x565561a8 <+11>:    mov    ebp,esp
   0x565561aa <+13>:    push   ebx
   0x565561ab <+14>:    push   ecx
   0x565561ac <+15>:    sub    esp,0x10
   0x565561af <+18>:    call   0x5655620b <__x86.get_pc_thunk.ax>
   0x565561b4 <+23>:    add    eax,0x2e24
=> 0x565561b9 <+28>:    mov    DWORD PTR [ebp-0x10],0xa
   0x565561c0 <+35>:    mov    DWORD PTR [ebp-0xc],0x14
   0x565561c7 <+42>:    mov    edx,DWORD PTR [ebp-0x10]
   0x565561ca <+45>:    cmp    edx,DWORD PTR [ebp-0xc]
   0x565561cd <+48>:    jge    0x565561dc <main+63>
   0x565561cf <+50>:    mov    ecx,DWORD PTR [ebp-0x10]
   0x565561d2 <+53>:    mov    edx,DWORD PTR [ebp-0xc]
   0x565561d5 <+56>:    add    edx,ecx
   0x565561d7 <+58>:    mov    DWORD PTR [ebp-0x14],edx
   0x565561da <+61>:    jmp    0x565561e5 <main+72>
   0x565561dc <+63>:    mov    edx,DWORD PTR [ebp-0x10]
   0x565561df <+66>:    sub    edx,DWORD PTR [ebp-0xc]
   0x565561e2 <+69>:    mov    DWORD PTR [ebp-0x14],edx
   0x565561e5 <+72>:    sub    esp,0x8
   0x565561e8 <+75>:    push   DWORD PTR [ebp-0x14]
   0x565561eb <+78>:    lea    edx,[eax-0x1fd0]
   0x565561f1 <+84>:    push   edx
   0x565561f2 <+85>:    mov    ebx,eax
   0x565561f4 <+87>:    call   0x56556050 <printf@plt>
   0x565561f9 <+92>:    add    esp,0x10
   0x565561fc <+95>:    mov    eax,0x0
   0x56556201 <+100>:   lea    esp,[ebp-0x8]
   0x56556204 <+103>:   pop    ecx
   0x56556205 <+104>:   pop    ebx
   0x56556206 <+105>:   pop    ebp
   0x56556207 <+106>:   lea    esp,[ecx-0x4]
   0x5655620a <+109>:   ret