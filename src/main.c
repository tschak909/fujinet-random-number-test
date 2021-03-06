/**
 * Test fuji random func 0xD3
 *
 * Should return random #
 */

#include <eos.h>
#include <msx.h>
#include <conio.h>
#include <stdio.h>

#define FUJI_DEV 0x0F

unsigned char response[1024];

unsigned long random_number(void)
{
  char r=0xD3;
  unsigned long *p=(unsigned long *)&response[0];
  
  eos_write_character_device(FUJI_DEV,&r,1);
  eos_read_character_device(FUJI_DEV,response,1024);

  return *p;
}

void main(void)
{
  msx_set_mode(0); // 40 col text mode
  clrscr();

  printf("\n\nRANDOM NUMBER TEST");

  for (int i=0;i<256;i++)
    printf("R: %lu\n",random_number());
}
