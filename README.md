# ft\_printf

## 🖋️ A Custom `printf` Implementation

Welcome to `ft_printf`, a project developed as part of the 42 curriculum. This is a handcrafted implementation of the standard `printf` function in C, designed to deepen understanding of variadic functions, format specifiers, and low-level output formatting.

---

## 🚀 Features

✅ Handles standard format specifiers:

- **%c** → Character
- **%s** → String
- **%d / %i** → Integer
- **%u** → Unsigned Integer
- **%p** → Pointer Address
- **%x / %X** → Hexadecimal (lower/uppercase)
- **%%** → Print a literal `%`

✅ Supports essential formatting flags:

- **-** → Left-align output
- **0** → Zero-padding
- **#** → Prefix for hexadecimal (`0x`, `0X`)
- **+** → Force display of sign for numeric values
- **(space)** → Add a space before positive numbers
- **.precision** → Control string truncation & numeric precision

✅ **Bonus Implementation**:

- Extra flag handling (`#`, `+`, space)
- Extended formatting precision
- More efficient internal memory handling

⚠️ **Limitations**:

- ❌ Does **not** support floating-point numbers (`%f`, `%e`, `%g`).
- ❌ Does **not** support octal (`%o`).

---

## 📂 Project Structure

```
ft_printf
├── includes/         # Header files
├── libft/            # Custom string & memory functions
├── src/              # Core implementation of ft_printf
│   ├── ft_printf.c   # Main function
│   ├── utils/        # Helper functions for formatting
├── src_bonus/        # Extended functionality
│   ├── ft_printf_bonus.c
│   ├── utils/        # Bonus-specific utilities
├── Makefile          # Build automation
└── README.md         # You're reading it!
```

---

## 🔧 Installation & Usage

### **1️⃣ Clone the repository**

```bash
git clone git@github.com:LordMikkel/ft_printf.git
cd ft_printf
```

### **2️⃣ Compile the library**

```bash
make
```

This will generate `libftprintf.a`, a static library that can be linked to your project.

### **3️⃣ Usage Example**

```c
#include "ft_printf.h"

int main()
{
    ft_printf("Hello, %s! You have %d new messages.\n", "Mikel", 42);
    return 0;
}
```

Compile it with:

```bash
gcc main.c libftprintf.a -o test
./test
```

---

## 🔨 Makefile Rules

The Makefile includes the following rules to manage the project build process:

- **`make`**: Compiles the project and generates the `libftprintf.a` static library.

- **`make bonus`**: Compiles and links the bonus features of the project, enabling additional formatting options such as custom flags (e.g., `Min_width`, `-`, `0`, `#`, `+`, etc.). It produces a version of the library with these extended functionalities.

- **`make test`**: Compiles and runs a series of tests for basic and complex formats. The tests verify if the `ft_printf` implementation matches the standard `printf` behavior for various specifiers such as characters, strings, integers, hexadecimals, and combinations. The results will be displayed as pass/fail.

- **`make testbonus`**: Compiles and runs tests for the bonus functionalities, such as handling flags like `Min_width`, `-`, `0`, `#`, `+`, and space. It ensures that these additional format specifiers are correctly handled by `ft_printf`.

- **`make clean`**: Removes object files (`.o`) from the `src/` and `src_bonus/` directories to clean up intermediate build files.

- **`make fclean`**: Removes both object files and the compiled static library (`libftprintf.a`). This cleans the project completely, removing all generated files.

- **`make re`**: Cleans the project and rebuilds everything from scratch. This is equivalent to running `make fclean` followed by `make`, ensuring that the project is recompiled from the beginning.

---

### Example Test Results

In your `main.c`, several tests are run to check the correctness of your `ft_printf` implementation. The test cases cover:

#### Basic Character and String Tests
- `char`: Test for printing characters like `'A'`, `\0`, and special characters like `\n`.
- `string`: Test for basic strings, empty strings, and long strings.

#### Pointer Tests
- Testing pointers with valid addresses and `NULL`.

#### Integer and Number Tests
- Tests for positive and negative integers, as well as `INT_MAX` and `INT_MIN`.
- Tests for unsigned integers, including `UINT_MAX`.

#### Hexadecimal Tests
- Tests for hexadecimal representation in both lowercase and uppercase.

#### Combination of Formats
- Tests for combinations of various format specifiers.

#### Bonus Tests (If Defined)
- Tests for additional flags such as `Min_width`, `-`, `0`, `#`, `+`, and space.
- Tests with multiple flags combined, ensuring that they work correctly in various formats.

#### Test Output
The `ft_printf` function is compared against the standard `printf` function to ensure it produces identical outputs. If the outputs match, the test passes; otherwise, it fails.

The summary at the end of the tests will display:
- The number of tests passed (in green).
- The number of tests failed (in red).

The **Makefile** ensures that these tests can be easily executed by simply running `make test` or `make testbonus`.


## 🏆 Credits

Developed by **Mikel Garrido** as part of the 42 curriculum.

🔗 [GitHub: LordMikkel](https://github.com/LordMikkel)

