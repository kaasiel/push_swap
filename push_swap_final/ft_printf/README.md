*This project has been created as part of the 42 curriculum by belaindr.*

# ft_printf — Because ft_putnbr() and ft_putstr() aren't enough

## 1. Description

**ft_printf** is a 42 project that involves recoding the standard C `printf()` function from scratch. The goal is to learn how variadic functions work in C — functions that accept a variable number of arguments — by implementing a fully functional subset of `printf()`.

The resulting library (`libftprintf.a`) can later be integrated into your `libft` and reused across all future 42 projects.

**Key Goals:**
- Understand and use variadic functions (`va_start`, `va_arg`, `va_copy`, `va_end`).
- Parse a format string and dispatch to the correct output handler for each conversion specifier.
- Write clean, modular, and extensible C code.

---

## 2. Instructions

### Prerequisites

Ensure you have a C compiler `cc` and `make` installed. Designed for Unix-like environments (Linux/macOS).

### Compilation

```bash
git clone <the-repo-url>
cd ft_printf
make
```

This produces `libftprintf.a` at the root of the repository.

### Makefile Rules

| Rule | Description |
|------|-------------|
| `make`| Compiles source files and generates `libftprintf.a` |
| `make clean` | Removes all object files (`.o`) |
| `make fclean` | Removes object files and `libftprintf.a` |
| `make re` | Full `fclean` + `make` |

### Usage

Include the header in your source code:

```c
#include "ft_printf.h"
```

Link the library during compilation:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o my_program
```

### Example

```c
ft_printf("Hello, %s! You are %d years old.\n", "Alice", 30);
ft_printf("Pointer address: %p\n", ptr);
ft_printf("Hex: %x | %X\n", 255, 255);
ft_printf("Percent sign: %%\n");
```

---

## Supported Conversions

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a `void *` pointer in hexadecimal format |
| `%d` | Prints a decimal (base 10) integer |
| `%i` | Prints an integer in base 10 |
| `%u` | Prints an unsigned decimal (base 10) number |
| `%x` | Prints a number in hexadecimal (base 16) lowercase |
| `%X` | Prints a number in hexadecimal (base 16) uppercase |
| `%%` | Prints a literal percent sign |

## Algorithm & Design Choices

### Overview

The core of `ft_printf` is a **format string parser** combined with a **dispatcher pattern**. Rather than one large function handling every case, the logic is split into small, single-purpose handler functions — one per conversion type. This keeps the code modular, readable, and easy to extend.

### Step-by-step flow

1. `ft_printf` receives a format string and a variable argument list.
2. It iterates through the string character by character.
3. When a regular character is encountered, it is written directly to stdout.
4. When a `%` is encountered, the next character is read to identify the conversion specifier.
5. The specifier is passed to a dispatcher that calls the appropriate handler function.
6. Each handler retrieves the next argument using `va_arg` and outputs it in the correct format.
7. The function accumulates a total character count and returns it at the end.

### Why this approach?

A **dispatch-based design** (using a series of `if`/`else if` or a lookup approach) was chosen over a monolithic function for several reasons:

- **Separation of concerns:** Each conversion type is isolated. A bug in `%x` handling does not affect `%s` handling.
- **Extensibility:** Adding a new specifier only requires writing one new handler function and adding one branch to the dispatcher — no existing code needs to be modified.
- **Testability:** Individual handler functions can be tested independently, making debugging significantly easier.
- **Norm compliance:** Breaking logic into small static helper functions keeps each function under the 42 Norm's 25-line limit naturally.

### Variadic functions

The `<stdarg.h>` macros are used to access the variable arguments:
- `va_start` initializes the argument list after the last fixed parameter.
- `va_arg` retrieves the next argument of a given type.
- `va_end` cleans up the argument list when done.
- `va_copy` is used when the argument list needs to be traversed more than once (e.g., for computing field widths before printing).

### Return value

`ft_printf` returns the **total number of characters written**, consistent with the behavior of the original `printf()`. Each handler function returns its own character count, and these are summed up in the main function.

---

## 3. Resources

- [Linux man-pages — printf(3)](https://man7.org/linux/man-pages/man3/printf.3.html) — Authoritative specification for `printf()` behavior
- [Linux man-pages — stdarg(3)](https://man7.org/linux/man-pages/man3/stdarg.3.html) — Reference for variadic function macros
- [cppreference — printf](https://en.cppreference.com/w/c/io/fprintf) — Clear breakdown of all format specifiers and flags
- [YouTube — Boris / PrimFx](https://www.youtube.com/@PrimFx) — Video explanations used during learning

## AI Usage

AI tools (Claude) were used as a learning aid only, not to generate final code. No code was directly generated or copied from AI — all implementations were written manually.

Specifically, AI was used for:
- Clarifying the behavior of variadic function macros (`va_start`, `va_arg`, `va_end`)
- Understanding edge cases for specific conversions (e.g. `%p` with NULL, `%s` with NULL)
- Reviewing the overall design approach at a high level
- Generating and formatting this README file

AI was **not** used to write, debug, or verify the submitted C code. All code was written, tested, and debugged manually, in accordance with the project rules.