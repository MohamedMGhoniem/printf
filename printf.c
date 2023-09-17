/**
* printf - function to print
* @format: string
* @...: indefinte var
*
*Return: num of chars
*/
#include"main.h"
int _printf(const char *format, ...)
{
va_list print;
int i,ind = 0, ch_count=0;

if (format == '/0')
    return(-1);
va_start(print, format);
while(*format)
{
    if(*format != '%')
    {
        write(1,format,1);
        ch_count++;
    }
    else
    {
        format++;
        if(*format == '/0')
            break;
        if(*format == '%')
        {
            write(1,format,1);
            ch_count++;
        } 
        if(*format == 'c')
        {
            char c = va_arg(print, int); //he made follwing arg int instead of char idk why
            write(1, &c , 1); //why calling by ref
            ch_count++;
        }
        if(*format == 's')
        {
            char str* = va_arg(print, char*);
            int s_len = strlen(str);
            write(1,str, s_len);
            ch_count += s_len;
        }
    }
    format++;
}
va_end(print);
return (ch_count);
}

