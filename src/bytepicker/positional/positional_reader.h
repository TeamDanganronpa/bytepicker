#ifndef BYTEPICKER_POSITIONAL_READER_H
#define BYTEPICKER_POSITIONAL_READER_H

#include <stddef.h>

void* CreatePositionalFileReader(const char* FilePath);
void DestroyPositionalFileReader(void* PositionalFileReader);

const char* PositionalFileReader_Read(void* PositionalFileReader, void* Buffer, size_t BufferSize);
const char* PositionalFileReader_ReadString(void* PositionalFileReader, char* StringBuffer, size_t StringSizeWithoutNullTerminator);

const char* PositionalFileReader_SetPosition(void* PositionalFileReader, size_t NewPosition);

#endif // BYTEPICKER_POSITIONAL_READER_H
