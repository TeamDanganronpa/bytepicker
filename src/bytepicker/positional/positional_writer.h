#ifndef BYTEPICKER_POSITIONAL_WRITER_H
#define BYTEPICKER_POSITIONAL_WRITER_H

#include <stddef.h>

void* CreatePositionalFileWriter(const char* FilePath);
void DestroyPositionalFileWriter(void* PositionalFileWriter);

const char* PositionalFileWriter_Write(void* PositionalFileWriter, void* Value, size_t ValueSize);
const char* PositionalFileWriter_WriteString(void* PositionalFileWriter, const char* StringBuffer);

const char* PositionalFileWriter_SetPosition(void* PositionalFileWriter, size_t Position);

#endif // BYTEPICKER_POSITIONAL_WRITER_H
