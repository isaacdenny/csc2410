# Assembly 32vs64 Research

## 1. Registers in 32-bit vs 64-bit

### IA32 and x86-64 General-Purpose Registers
- **IA32:** 8 general-purpose registers
- **x86-64:** 16 general-purpose registers

### New Registers in x86-64
- **R8, R9, R10, R11, R12, R13, R14, R15**

### Accessing Parts of a 64-bit Register
- **Lower 32 bits:** `eax` (for `rax`)
- **Lower 16 bits:** `ax` (for `rax`)
- **Lower 8 bits:** `al` (for `rax`)

## 2. Memory Addressing limits

### Maximum Memory Addressable
- **IA32:** 4 GB
- **x86-64:** 16 EB (Exabytes)

### Stack Pointer Comparison
- **IA32 (esp):** 32-bit stack pointer, addresses 4 GB memory.
- **x86-64 (rsp):** 64-bit stack pointer, addresses significantly larger memory.

### Effect on Stack Operations
- **IA32:** Limited to 4 GB; smaller address space impacts stack size.
- **x86-64:** Supports much larger stack size; allows for deeper recursion and larger data structures.

## 3. Function Calling Conventions

### Function Argument Passing

- **IA32:**
  - Arguments are primarily passed on the stack.
  - Caller pushes arguments onto the stack before calling the function.

- **x86-64:**
  - Arguments are passed using registers for the first six arguments, with additional arguments pushed onto the stack.
  
### Registers for First Six Arguments in x86-64
1. **1st Argument:** `rdi`
2. **2nd Argument:** `rsi`
3. **3rd Argument:** `rdx`
4. **4th Argument:** `rcx`
5. **5th Argument:** `r8`
6. **6th Argument:** `r9`

## 4. Instruction Set Operations

### New Instructions and Enhancements in x86-64
- **New Instructions:** 
  - `MOVBE` (Move Data after Swapping Bytes)
  - `CMPXCHG16B` (Compare and Exchange 16 Bytes)
  - Enhanced SIMD instructions (e.g., AVX, AVX2)

- **Other Enhancements:**
  - Larger register sizes (64-bit)
  - Improved support for system-level programming and larger address spaces.

### Arithmetic Operations in x86-64 vs. IA32
- **Multiplication:**
  - **IA32:** `MUL` (unsigned), `IMUL` (signed), results in a pair of registers (e.g., EAX and EDX).
  - **x86-64:** Same instructions, but operate on 64-bit registers (e.g., RAX and RDX).

- **Division:**
  - **IA32:** `DIV` (unsigned), `IDIV` (signed) with results in EAX (quotient) and EDX (remainder).
  - **x86-64:** Same instructions, but operate on RAX and RDX for 64-bit results.

## Real World Implications

### Impact of 32-bit vs. 64-bit Architectures

- **Data Types:** Pointers and certain types increase in size, affecting data structures.
- **Memory Management:** Larger addressable space allows for more extensive data structures.
- **Performance:** 64-bit can process more data per instruction.

### Challenges in Transitioning to 64-bit

- **Portability Issues:** Fixed-size integers and pointers may break.
- **Library Compatibility:** Need 64-bit versions of third-party libraries.
- **Debugging:** New memory layouts can introduce hard-to-find bugs.
- **Alignment:** Data structure adjustments may be required.

