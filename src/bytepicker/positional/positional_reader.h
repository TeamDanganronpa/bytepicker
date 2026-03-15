#ifndef BYTEPICKER_POSITIONAL_READER_H
#define BYTEPICKER_POSITIONAL_READER_H

#include <stddef.h>

#include "bytepicker/dll_api.h"

void* BYTEPICKER_API CreatePositionalFileReader(const char* FilePath);
void BYTEPICKER_API DestroyPositionalFileReader(void* PositionalFileReader);

const char* BYTEPICKER_API PositionalFileReader_Read(void* PositionalFileReader, void* Buffer, size_t BufferSize);
const char* BYTEPICKER_API PositionalFileReader_ReadString(void* PositionalFileReader, char* StringBuffer, size_t StringSizeWithoutNullTerminator);

const char* BYTEPICKER_API PositionalFileReader_SetPosition(void* PositionalFileReader, size_t NewPosition);
size_t BYTEPICKER_API PositionalFileReader_GetPosition(void* PositionalFileReader);

#endif // BYTEPICKER_POSITIONAL_READER_H
