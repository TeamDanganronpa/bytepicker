#include "bytepicker/positional/positional_reader.h"

#include <stdio.h>
#include <string.h>

#include "bytepicker/error.h"

void* CreatePositionalFileReader(const char* FilePath) {
	return fopen(FilePath, "rb");
}

void DestroyPositionalFileReader(void* PositionalFileReader) {
	if (PositionalFileReader) fclose(PositionalFileReader);
}

const char* PositionalFileReader_Read(void* PositionalFileReader, void* Buffer, size_t BufferSize) {
	if (!PositionalFileReader) return BYTEPICKER_ERROR_INVALID_HANDLE;

	if (fread(Buffer, BufferSize, 1, PositionalFileReader) != 1) {
		if (ferror(PositionalFileReader)) return strerror(errno);
		if (feof(PositionalFileReader)) return BYTEPICKER_ERROR_EOF;
		return BYTEPICKER_ERROR_UNKNOWN;
	}
	return NULL;
}

const char* PositionalFileReader_ReadString(void* PositionalFileReader, char* StringBuffer, size_t StringSizeWithoutNullTerminator) {
	if (!PositionalFileReader) return BYTEPICKER_ERROR_INVALID_HANDLE;

	if (fread(StringBuffer, StringSizeWithoutNullTerminator, 1, PositionalFileReader) != 1) {
		if (ferror(PositionalFileReader)) return strerror(errno);
		if (feof(PositionalFileReader)) return BYTEPICKER_ERROR_EOF;
		return BYTEPICKER_ERROR_UNKNOWN;
	}
	StringBuffer[StringSizeWithoutNullTerminator] = '\0';
	return NULL;
}

const char* PositionalFileReader_SetPosition(void* PositionalFileReader, size_t NewPosition) {
	if (!PositionalFileReader) return BYTEPICKER_ERROR_INVALID_HANDLE;

#ifdef _WIN32
	_fseeki64(PositionalFileReader, NewPosition, SEEK_SET);
#else
	fseek(PositionalFileReader, NewPosition, SEEK_SET);
#endif
	return NULL;
}

size_t  PositionalFileReader_GetPosition(void* PositionalFileReader) {
	return
#ifdef _WIN32
	_ftelli64(PositionalFileReader);
#else
	ftell(PositionalFileReader);
#endif
}