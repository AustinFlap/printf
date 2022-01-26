# ft_printf
Re-implementation of `printf` with the following conversions :
| Conversions       | Description |
| ------------- |:-------------:|
| `%c`  | Ascii character |
| `%s`    | String      |
| `%p` | Hexadecimal pointer void* |
| `%d` | Decimal number |
| `%i` | Integer number |
| `%u` | Unsigned decimal number |
| `%x` | Hexadecimal number with lower-cases |
| `%X` | Hexadecimal number with upper-cases |
| `%%` | '%' character |

## Use

Compile static library `libftprintf.a` using `make` then compile with your file using `gcc -o a.out libftprintf.a your_file.c`
