   0x5655619d <+0>:     lea    ecx,[esp+0x4]
   0x565561a1 <+4>:     and    esp,0xfffffff0
   0x565561a4 <+7>:     push   DWORD PTR [ecx-0x4]
   0x565561a7 <+10>:    push   ebp
   0x565561a8 <+11>:    mov    ebp,esp
   0x565561aa <+13>:    push   ebx
   0x565561ab <+14>:    push   ecx
   0x565561ac <+15>:    sub    esp,0x10
   0x565561af <+18>:    call   0x565561f8 <__x86.get_pc_thunk.ax>
   0x565561b4 <+23>:    add    eax,0x2e24
=> 0x565561b9 <+28>:    mov    DWORD PTR [ebp-0x14],0x5
   0x565561c0 <+35>:    mov    DWORD PTR [ebp-0x10],0x7
   0x565561c7 <+42>:    mov    ecx,DWORD PTR [ebp-0x14]
   0x565561ca <+45>:    mov    edx,DWORD PTR [ebp-0x10]
   0x565561cd <+48>:    add    edx,ecx
   0x565561cf <+50>:    mov    DWORD PTR [ebp-0xc],edx
   0x565561d2 <+53>:    sub    esp,0x8
   0x565561d5 <+56>:    push   DWORD PTR [ebp-0xc]
   0x565561d8 <+59>:    lea    edx,[eax-0x1fd0]
   0x565561de <+65>:    push   edx
   0x565561df <+66>:    mov    ebx,eax
   0x565561e1 <+68>:    call   0x56556050 <printf@plt>
   0x565561e6 <+73>:    add    esp,0x10
   0x565561e9 <+76>:    mov    eax,0x0
   0x565561ee <+81>:    lea    esp,[ebp-0x8]
   0x565561f1 <+84>:    pop    ecx
   0x565561f2 <+85>:    pop    ebx
   0x565561f3 <+86>:    pop    ebp
   0x565561f4 <+87>:    lea    esp,[ecx-0x4]
   0x565561f7 <+90>:    ret