#ifndef COMM_H
#define COMM_H

#include <Arduino.h>
#include "pid.h"

// Union datatype for processing doubles
union float_buf { float f; byte b[4]; };

// Load the log packet into some byte buffer
void loadLogPacket(PIDLog* log, byte* buffer);
// Unload the log packet from some byte buffer
PIDLog unloadLogPacket(byte* buffer);
// Unload a float from a buffer at some offset
double unloadFloat(byte* buffer, int offset);
// Load a float into a buffer at some offset
void loadFloat(double f, byte* buffer, int offset);

#endif
