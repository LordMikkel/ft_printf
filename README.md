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
gcc main.c libftprintf.a -o my_printf
./my_printf
```

---

## 🏆 Credits

Developed by **Mikel Garrido** as part of the 42 curriculum.

🔗 [GitHub: LordMikkel](https://github.com/LordMikkel)

