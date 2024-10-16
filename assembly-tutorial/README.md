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

```
