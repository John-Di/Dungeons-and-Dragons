//Allows to delay the application during runtime
//This is used mostly for the Random value generator (the Dice rolling)

//Windows and Linux time delays for more "true" random variables

//If Windows
#pragma once

#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)

	#include <windows.h>

	inline void delay( unsigned long ms )
    {
    Sleep( ms );
    }

#else  //Assuming Linux
	
	#include <unistd.h>
  
	inline void delay( unsigned long ms )
    {
		usleep( ms * 1000 );
    }

#endif