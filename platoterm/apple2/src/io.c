/**
 * PLATOTerm64 - A PLATO Terminal for the Commodore 64
 * Based on Steve Peltz's PAD
 * 
 * Author: Thomas Cherryhomes <thom.cherryhomes at gmail dot com>
 *
 * io.c - Input/output functions (serial/ethernet)
 */

#include <stdbool.h>
#include <serial.h>
#include <stdint.h>
#include <stdlib.h>
#include <peekpoke.h>
#include <stdio.h>
#include "io.h"
#include "protocol.h"
#if defined(__APPLE2__) || defined(__APPLE2ENH__)
#include <apple2.h>
#endif

#define NULL 0

static uint8_t ch=0;
static uint8_t io_res;
uint8_t recv_buffer[512];
static uint16_t recv_buffer_size=0;

/**
 * io_init() - Set-up the I/O
 */
void io_init(void)
{
}

/**
 * io_main() - The IO main loop
 */
void io_main(void)
{
}

/**
 * io_done() - Called to close I/O
 */
void io_done(void)
{
}

/**
 * io_send_byte() - Send byte to host
 */
void io_send_byte(unsigned char ch)
{
}