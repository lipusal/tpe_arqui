#ifndef MODULES_H
#define MODULES_H

#include <stdint.h>

#define CODE_MODULE_ADDR ((void *)0x400000)
#define DATA_MODULE_ADDR ((void *)0x500000)

int32_t runCodeModule();

char * readDataModule();

#endif