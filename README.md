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

## 🔨 Makefile Rules

The Makefile includes a set of rules that help streamline the project build process and testing:

---

### 📦 **`make`**: Compile the core project
Compiles the project and generates the `libftprintf.a` static library. This is the foundation for your `ft_printf` implementation.

---

### 🏆 **`make bonus`**: Enable bonus features
Compiles and links the bonus features of the project, enabling additional formatting options such as custom flags (e.g., `Min_width`, `-`, `0`, `#`, `+`, etc.). This produces a version of the library with these extended functionalities.

---

### 🧪 **`make test`**: Run basic tests
Compiles and runs a comprehensive suite of tests for basic and complex formats. The test suite ensures your `ft_printf` works as expected, comparing it against the standard `printf` implementation. Tests cover characters, strings, integers, hexadecimals, and combinations.

---

### 🧪 **`make testbonus`**: Run bonus tests
Compiles and runs tests specifically designed for the bonus features. These tests verify that flags such as `Min_width`, `-`, `0`, `#`, `+`, and space are handled correctly. Bonus functionality ensures your `ft_printf` is more flexible and robust.

---

### 🧹 **`make clean`**: Clean up object files
Removes all object files (`.o`) from the `src/` and `src_bonus/` directories, cleaning up intermediate build files to prepare for fresh compilations.

---

### 🧹 **`make fclean`**: Full cleanup
Removes both object files and the compiled static library (`libftprintf.a`). This ensures the project is entirely cleaned, removing all generated files.

---

### 🔄 **`make re`**: Rebuild everything
Performs a complete rebuild of the project from scratch by running `make fclean` followed by `make`. This is perfect when you need to ensure that all files are freshly compiled.

---

### Example Test Results

In your `main.c`, several tests are executed to check the correctness of your `ft_printf` implementation. The tests encompass a variety of formats and edge cases, ensuring comprehensive coverage. Here's an overview:

---

#### 🔠 **Basic Character and String Tests**
- **Characters**: Test for basic characters like `'A'`, null characters (`\0`), and special characters like newline (`\n`).
- **Strings**: Tests for normal strings, empty strings, and long strings to check memory handling and performance.

---

#### 🧑‍💻 **Pointer Tests**
- Tests for printing valid pointer addresses and handling `NULL` pointers.

---

#### 💯 **Integer and Number Tests**
- **Integers**: Tests for positive and negative integers, as well as boundary values like `INT_MAX` and `INT_MIN`.
- **Unsigned Integers**: Tests for unsigned integers, including edge cases like `UINT_MAX`.

---

#### 🔢 **Hexadecimal Tests**
- Verifying the correct representation of hexadecimal numbers in both lowercase (`%x`) and uppercase (`%X`).

---

#### 🔀 **Combination of Formats**
- Tests involving multiple format specifiers in a single print statement, ensuring that combinations work as expected.

---

#### 🎁 **Bonus Tests (If Defined)**
- Tests for additional flags such as `Min_width`, `-`, `0`, `#`, `+`, and space. These flags offer more control over the printed output.
- Tests with combinations of flags ensure that they work correctly when used together, e.g., `%-10.5d`, `%010d`, and `%#x`.

---

### Test Output

Each test compares the output of `ft_printf` to the standard `printf`. If the outputs match, the test **passes**; otherwise, it **fails**. At the end of the test suite, a summary will display:

- **Passed Tests**: Displayed in green.
- **Failed Tests**: Displayed in red.

---

With the **Makefile**, you can easily run tests with a single command:
- Run all tests: `make test`
- Run tests for bonus features: `make testbonus`

The **Makefile** simplifies your development workflow, making it easy to test and debug your `ft_printf` implementation.


## 🏆 Credits

Developed by **Mikel Garrido** as part of the 42 curriculum.

🔗 [GitHub: LordMikkel](https://github.com/LordMikkel)

