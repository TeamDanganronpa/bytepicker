#ifndef BYTEPICKER_POSITIONAL_WRITER_H
#define BYTEPICKER_POSITIONAL_WRITER_H

#include <stddef.h>

#include "bytepicker/dll_api.h"

void* BYTEPICKER_API CreatePositionalFileWriter(const char* FilePath);
void BYTEPICKER_API DestroyPositionalFileWriter(void* PositionalFileWriter);

const char* BYTEPICKER_API PositionalFileWriter_Write(void* PositionalFileWriter, void* Value, size_t ValueSize);
const char* BYTEPICKER_API PositionalFileWriter_WriteString(void* PositionalFileWriter, const char* StringBuffer);

const char* BYTEPICKER_API PositionalFileWriter_SetPosition(void* PositionalFileWriter, size_t Position);
size_t BYTEPICKER_API PositionalFileWriter_GetPosition(void* PositionalFileWriter);

#endif // BYTEPICKER_POSITIONAL_WRITER_H
