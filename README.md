# ft_printf
42 - Ft_Prinf with Bonus: A custom implementation of printf in C from scratch. Handling variadic arguments, format specifiers, and creating a library (libftprintf.a)

# RESUMEN FLAGS

Flag	Propósito															Ejemplo								Specifier Usos
-		Alineación a la izquierda											%-10d -> "42        "				Todos
0		Rellenar con ceros en lugar de espacios								%010d -> "0000000042"				'd', 'i'
#		Modificar la representación de números hexadecimales y octales		"%#x" -> "0x2a", "%#o" -> "052"		'x', 'X'
+		Mostrar siempre el signo, incluso para números positivos			"%+d" -> "+42", "%+d" -> "-42"		'd', 'i'
" "		Mostrar espacio antes de los números positivos						"% d" -> " 42", "% d" -> "-42"		'd', 'i'
.		Define precisión:
		- Máximo de caracteres en cadenas									%.3s con "Hello" -> "Hel"			's', 'd','i', 'u', 'x', 'X'
		- Número de decimales en flotantes									%.2f con 3.14159 -> "3.14"
		- Número mínimo de dígitos del número, sino rellena con 0			%.5d con 42 -> "00042"
																			%.3d con 123456 -> 123456
