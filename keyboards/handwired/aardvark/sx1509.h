#ifndef SX1509
#define SX1509

// #define USE_LUFA_TWI

#include <stdbool.h>

bool sx1509_init(void);
bool sx1509_make_ready(void);
uint16_t sx1509_read(void);

#endif // SX1509
