#ifndef BYTEPICKER_DLL_API_H
#define BYTEPICKER_DLL_API_H

#ifdef _WIN32
	#ifdef BYTEPICKER_DLL
		#ifdef BYTEPICKER_COMPILATION
			#define BYTEPICKER_API __declspec(dllexport)
		#else
			#define BYTEPICKER_API __declspec(dllimport)
		#endif
	#else
		#define BYTEPICKER_API
	#endif
#else
	#define BYTEPICKER_API
#endif

#endif // BYTEPICKER_DLL_API_H
