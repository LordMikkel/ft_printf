/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:17:44 by migarrid          #+#    #+#             */
/*   Updated: 2025/02/17 22:22:41 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include "./includes/ft_printf.h"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

int passed_tests = 0;
int failed_tests = 0;

void check_test(int expected, int actual, const char *test_name)
{
    if (expected == actual)
    {
        printf(GREEN "PASS: %s\n" RESET, test_name);
        passed_tests++;
    }
    else
    {
        printf(RED "FAIL: %s\n" RESET, test_name);
        printf("Expected return value: %d\n", expected);
        printf("Actual return value:   %d\n", actual);
        failed_tests++;
    }
    printf("\n");
}

void print_test_header(const char *header)
{
    printf("\n----------------------------------------\n");
    printf("%s\n", header);
    printf("----------------------------------------\n");
}

int main(void)
{
    char            *word;
    void            *nb;
    char            letter;
    int             entero;
    int             expected_return;
    int             actual_return;
    int             value;
    unsigned int    unsign;
    unsigned int    num;

    // ==============================================
    // Sección 1: Pruebas básicas de caracteres y cadenas
    // ==============================================
    print_test_header("1. Pruebas básicas de caracteres y cadenas");

    // Caracteres básicos
    letter = 'A';
    expected_return = printf("Carácter básico: %c\n", letter);
    actual_return = ft_printf("Carácter básico: %c\n", letter);
    check_test(expected_return, actual_return, "Carácter básico");

    // Carácter nulo
    letter = '\0';
    expected_return = printf("Carácter nulo: %c\n", letter);
    actual_return = ft_printf("Carácter nulo: %c\n", letter);
    check_test(expected_return, actual_return, "Carácter nulo");

    // Caracteres especiales
    letter = '\n';
    expected_return = printf("Carácter especial (nueva línea): %c\n", letter);
    actual_return = ft_printf("Carácter especial (nueva línea): %c\n", letter);
    check_test(expected_return, actual_return, "Carácter especial");

    // Cadenas básicas
    word = "Hola, mundo!";
    expected_return = printf("Cadena básica: %s\n", word);
    actual_return = ft_printf("Cadena básica: %s\n", word);
    check_test(expected_return, actual_return, "Cadena básica");

    // Cadena vacía
    word = "";
    expected_return = printf("Cadena vacía: %s\n", word);
    actual_return = ft_printf("Cadena vacía: %s\n", word);
    check_test(expected_return, actual_return, "Cadena vacía");

    // Cadena larga
    word = "Esta es una cadena extremadamente larga para probar el manejo de memoria y la capacidad de printf para manejar cadenas largas sin problemas.";
    expected_return = printf("Cadena larga: %s\n", word);
    actual_return = ft_printf("Cadena larga: %s\n", word);
    check_test(expected_return, actual_return, "Cadena larga");

    // ==============================================
    // Sección 2: Pruebas de punteros
    // ==============================================
    print_test_header("2. Pruebas de punteros");

    // Puntero básico
    value = 42;
    nb = &value;
    expected_return = printf("Puntero básico: %p\n", nb);
    actual_return = ft_printf("Puntero básico: %p\n", nb);
    check_test(expected_return, actual_return, "Puntero básico");

    // Puntero NULL
    expected_return = printf("Puntero NULL: %p\n", NULL);
    actual_return = ft_printf("Puntero NULL: %p\n", NULL);
    check_test(expected_return, actual_return, "Puntero NULL");

    // ==============================================
    // Sección 3: Pruebas de enteros y números
    // ==============================================
    print_test_header("3. Pruebas de enteros y números");

    // Entero positivo
    entero = 42;
    expected_return = printf("Entero positivo: %d\n", entero);
    actual_return = ft_printf("Entero positivo: %d\n", entero);
    check_test(expected_return, actual_return, "Entero positivo");

    // Entero negativo
    entero = -42;
    expected_return = printf("Entero negativo: %d\n", entero);
    actual_return = ft_printf("Entero negativo: %d\n", entero);
    check_test(expected_return, actual_return, "Entero negativo");

    // INT_MAX
    expected_return = printf("INT_MAX: %d\n", INT_MAX);
    actual_return = ft_printf("INT_MAX: %d\n", INT_MAX);
    check_test(expected_return, actual_return, "INT_MAX");

    // INT_MIN
    expected_return = printf("INT_MIN: %d\n", INT_MIN);
    actual_return = ft_printf("INT_MIN: %d\n", INT_MIN);
    check_test(expected_return, actual_return, "INT_MIN");

    // Unsigned int
    unsign = 42;
    expected_return = printf("Unsigned int: %u\n", unsign);
    actual_return = ft_printf("Unsigned int: %u\n", unsign);
    check_test(expected_return, actual_return, "Unsigned int");

    // UINT_MAX
    expected_return = printf("UINT_MAX: %u\n", UINT_MAX);
    actual_return = ft_printf("UINT_MAX: %u\n", UINT_MAX);
    check_test(expected_return, actual_return, "UINT_MAX");

    // ==============================================
    // Sección 4: Pruebas de hexadecimales
    // ==============================================
    print_test_header("4. Pruebas de hexadecimales");

    // Hexadecimal en minúsculas
    num = 255;
    expected_return = printf("Hexadecimal (minúsculas): %x\n", num);
    actual_return = ft_printf("Hexadecimal (minúsculas): %x\n", num);
    check_test(expected_return, actual_return, "Hexadecimal (minúsculas)");

    // Hexadecimal en mayúsculas
    expected_return = printf("Hexadecimal (mayúsculas): %X\n", num);
    actual_return = ft_printf("Hexadecimal (mayúsculas): %X\n", num);
    check_test(expected_return, actual_return, "Hexadecimal (mayúsculas)");

    // Hexadecimal con 0
    expected_return = printf("Hexadecimal con 0: %x\n", 0);
    actual_return = ft_printf("Hexadecimal con 0: %x\n", 0);
    check_test(expected_return, actual_return, "Hexadecimal con 0");

    // ==============================================
    // Sección 5: Pruebas de combinaciones complejas
    // ==============================================
    print_test_header("5. Pruebas de combinaciones complejas");

    // Combinación de varios tipos
    expected_return = printf("Combinación: %d, %s, %x, %X, %u\n", 42, "Hola", 255, 255, 123);
    actual_return = ft_printf("Combinación: %d, %s, %x, %X, %u\n", 42, "Hola", 255, 255, 123);
    check_test(expected_return, actual_return, "Combinación compleja");

#ifdef BONUS

    // ==============================================
    // Sección 6: Pruebas de bonus (flags adicionales)
    // ==============================================
    print_test_header("6. Pruebas de bonus (flags adicionales)");

    // Flag 'Min_width'
    expected_return = printf("Flag 'Min_width': '%10d'\n", 42);
    actual_return = ft_printf("Flag 'Min_width': '%10d'\n", 42);
    check_test(expected_return, actual_return, "Flag 'Min_width'");

    expected_return = printf("Flag 'Min_width': '%1d'\n", 42);
    actual_return = ft_printf("Flag 'Min_width': '%1d'\n", 42);
    check_test(expected_return, actual_return, "Flag 'Min_width'");

    // Flag '-'
    expected_return = printf("Flag '-': '%-10d'\n", 42);
    actual_return = ft_printf("Flag '-': '%-10d'\n", 42);
    check_test(expected_return, actual_return, "Flag '-'");

    // Flag '0'
    expected_return = printf("Flag '0': %010d\n", 42);
    actual_return = ft_printf("Flag '0': %010d\n", 42);
    check_test(expected_return, actual_return, "Flag '0'");

    // Flag '#'
    expected_return = printf("Flag '#': %#x\n", 42);
    actual_return = ft_printf("Flag '#': %#x\n", 42);
    check_test(expected_return, actual_return, "Flag '#'");

    // Flag '+'
    expected_return = printf("Flag '+': %+d\n", 42);
    actual_return = ft_printf("Flag '+': %+d\n", 42);
    check_test(expected_return, actual_return, "Flag '+'");

    expected_return = printf("Flag '+': %+d\n", -42);
    actual_return = ft_printf("Flag '+': %+d\n", -42);
    check_test(expected_return, actual_return, "Flag '+'");

    // Flag ' ' (espacio)
    expected_return = printf("Flag ' ': % d\n", 42);
    actual_return = ft_printf("Flag ' ': % d\n", 42);
    check_test(expected_return, actual_return, "Flag ' '");

    expected_return = printf("Flag ' ': % d\n", -42);
    actual_return = ft_printf("Flag ' ': % d\n", -42);
    check_test(expected_return, actual_return, "Flag ' '");

    // Flag '.' (precisión)
    expected_return = printf("Flag '.': %.5d\n", 42);
    actual_return = ft_printf("Flag '.': %.5d\n", 42);
    check_test(expected_return, actual_return, "Flag '.'");

    expected_return = printf("Flag '.': %.1d\n", 42);
    actual_return = ft_printf("Flag '.': %.1d\n", 42);
    check_test(expected_return, actual_return, "Flag '.'");

    // ==============================================
    // Sección 7: Pruebas con múltiples flags combinados
    // ==============================================
    print_test_header("7. Pruebas con múltiples flags combinados");

    // Combinación de flags: '-', '0', y precisión
    expected_return = printf("Combinación de flags (1): %-10.5d\n", 42);
    actual_return = ft_printf("Combinación de flags (1): %-10.5d\n", 42);
    check_test(expected_return, actual_return, "Flags combinados (1)");

    // Combinación de flags: '+', '0', y ancho
    expected_return = printf("Combinación de flags (2): %+010d\n", 42);
    actual_return = ft_printf("Combinación de flags (2): %+010d\n", 42);
    check_test(expected_return, actual_return, "Flags combinados (2)");

    // Combinación de flags: '0', y ancho
    expected_return = printf("Combinación de flags (3): %010x\n", 42);
    actual_return = ft_printf("Combinación de flags (3): %010x\n", 42);
    check_test(expected_return, actual_return, "Flags combinados (3)");

    // Combinación de flags: '-', ' ', y precisión
    expected_return = printf("Combinación de flags (4): %- 10.5d\n", 42);
    actual_return = ft_printf("Combinación de flags (4): %- 10.5d\n", 42);
    check_test(expected_return, actual_return, "Flags combinados (4)");

    // Combinación de flags: #', y ancho
    expected_return = printf("Combinación de flags (5): %#10x\n", 42);
    actual_return = ft_printf("Combinación de flags (5): %#10x\n", 42);
    check_test(expected_return, actual_return, "Flags combinados (5)");

#endif

    // ==============================================
    // Resumen de resultados
    // ==============================================
    print_test_header("Resumen de resultados");
    printf(GREEN "Pruebas pasadas: %d\n" RESET, passed_tests);
    printf(RED "Pruebas fallidas: %d\n" RESET, failed_tests);

    return (0);
}