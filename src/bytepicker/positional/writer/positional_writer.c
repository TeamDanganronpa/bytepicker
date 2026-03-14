#include "bytepicker/positional/positional_writer.h"

#include <stdio.h>
#include <string.h>

#include "bytepicker/error.h"

void* CreatePositionalFileWriter(const char* FilePath) {
	return fopen(FilePath, "wb");
}

void DestroyPositionalFileWriter(void* PositionalFileWriter) {
	if (PositionalFileWriter) fclose(PositionalFileWriter);
}

const char* PositionalFileWriter_Write(void* PositionalFileWriter, void* Value, size_t ValueSize) {
	if (!PositionalFileWriter) return BYTEPICKER_ERROR_INVALID_HANDLE;

	if (fwrite(Value, ValueSize, 1, PositionalFileWriter) != 1) {
		if (ferror(PositionalFileWriter)) return strerror(errno);
		if (feof(PositionalFileWriter)) return BYTEPICKER_ERROR_EOF;
		return BYTEPICKER_ERROR_UNKNOWN;
	}
	return NULL;
}

const char* PositionalFileWriter_WriteString(void* PositionalFileWriter, const char* String) {
	if (!PositionalFileWriter) return BYTEPICKER_ERROR_INVALID_HANDLE;

	if (fwrite(String, strlen(String), 1, PositionalFileWriter) != 1) {
		if (ferror(PositionalFileWriter)) return strerror(errno);
		if (feof(PositionalFileWriter)) return BYTEPICKER_ERROR_EOF;
		return BYTEPICKER_ERROR_UNKNOWN;
	}
	return NULL;
}