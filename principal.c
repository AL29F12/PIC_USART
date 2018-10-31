#include <18F4550.h>
#fuses NOWDT, NOPROTECT
#use delay(internal=8Mhz)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
#include <lcd.c>
#use standard_io(ALL)
void main()
{
   char answer;
   lcd_init();
   lcd_gotoxy(1,1);
   printf(lcd_putc, "\f");
   while(1)
   {
      printf("\nContinuar (S,N)?");
      do
      {
         if( kbhit() )
         {
            answer=getch();
            printf(lcd_putc,"\fYa hay dato");
         }
         else
         {
            printf(lcd_putc,"\fNo hay dato");
         }
      }
      while(answer!='S' && answer!='N');
      answer = '';
      printf("\nITSA uC");
      printf(lcd_putc,"\f\nITSA uC");
      delay_ms(100);
   }
}
