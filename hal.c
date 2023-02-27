#include "hal.h"
#include "user_actions.h"
#include "main.h"
int sysTickCounter = 0;

// Specific implementation for ARM-Cortex M4 here:

void uartInit(void)
{
  // Enable FIFO:
  // LCRH <-- LCRH_FEN
  WriteToRegister(0x4000C000 + 0x2C, 0x10);

  // TODO: Calculate Baudrate
  // Todo: Settings for 115200,8,n,1

  // [9]    RXE   Receive enable
  // [8]    TXE   Transmit enable
  // [0] UARTEN   UART enable: 1-enable, 0-disable
  WriteToRegister(0x4000C000 + 0x30, 0x00000031); // Control
}

void printString(const char *text)
{

  // Loop out the Data until zero reached!
  for (int n = 0; text[n] != 0; n++)
  {
    WriteToRegister(0x4000C000 + 0x00, text[n]); // Data
  }

  // Append \r\n, which results in a new line
  WriteToRegister(0x4000C000 + 0x00, '\r'); // Data
  WriteToRegister(0x4000C000 + 0x00, '\n'); // Data
}

void printStringWithLen(const char *text, int len)
{
  // Loop out the Data
  for (int n = 0; n < len; n++)
  {
    WriteToRegister(0x4000C000 + 0x00, text[n]); // Data
  }

  // Append \r\n, which results in a new line
  WriteToRegister(0x4000C000 + 0x00, '\r'); // Data
  WriteToRegister(0x4000C000 + 0x00, '\n'); // Data
}

void printChar(char text)
{
  WriteToRegister(0x4000C000 + 0x00, text);
}
// =================================================================================

char read_input(void)
{
  uint32_t DataRegister;
  WriteToRegister(0x4000C000 + 0x00, 0000);
  // FE = "FIFO EMPTY"
  // Active wait for not Empty fifo
  while (ReadFromRegister(0x4000C000 + 0x18) & 0x10)
    ;

  // Read from UART_O_DR
  DataRegister = ReadFromRegister(0x4000C000 + 0x00);

  DataRegister = DataRegister & 0x000000FF; // sanitize

  return (char)DataRegister;
}

char read_input_with_interrupt_handling(void)
{
  uint32_t DataRegister;
  WriteToRegister(0x4000C000 + 0x00, 0000);
  // FE = "FIFO EMPTY"
  // Active wait for not Empty fifo
  while (ReadFromRegister(0x4000C000 + 0x18) & 0x10 && sysTickCounter < 6400)
    ;

  // Read from UART_O_DR
  DataRegister = ReadFromRegister(0x4000C000 + 0x00);

  DataRegister = DataRegister & 0x000000FF; // sanitize

  if (sysTickCounter < 6500 && ReadFromRegister(0x4000C000 + 0x18) & 0x10)
  {
    sysTickCounter = 0;
    return (char)DataRegister;
  }
  while(sysTickCounter < 6500);
  if (sysTickCounter >= 6500)
  {
    sysTickCounter = 0;
    char escape = 27;
    return escape;
  }
}

// =================================================================================

void WriteToRegister(uint32_t address, uint32_t value)
{
  uint32_t *pointer_to_address;

  // Assign pointer to given address:
  pointer_to_address = (uint32_t *)address;

  // Write to the End of the Pointer
  *pointer_to_address = value;
}

uint32_t ReadFromRegister(uint32_t address)
{
  uint32_t *pointer_to_address;
  uint32_t value;

  // Assign pointer to given address:
  pointer_to_address = (uint32_t *)address;

  // Read from the End of the Pointer
  value = *pointer_to_address;

  // Return the read value
  return value;
}

void SysTick_Handler()
{
  sysTickCounter++;
  if (sysTickCounter >= 1000)
  {
    // sysTickCounter = 0;
    // update_gui_from_interrupt();
  }
}