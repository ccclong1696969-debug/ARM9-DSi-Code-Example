/*
 * A simple "Hello, World!" application for the Nintendo DSi ARM9 processor.
 */
#include <nds.h> // libnds C header. Contains all functions for DS hardware.
#include <stdio.h> // Standard I/O library for printf.

// The main function is the entry point for the ARM9 processor.
int main(void) {
    
    //---------------------------------------------------------------------------------
    // Initialization
    //---------------------------------------------------------------------------------

    // 'consoleDemoInit()' is a handy libnds function that sets up one of the
    // screens for printing text. It initializes the video mode and prepares
    // a simple tile-based background to act as a text console.
    consoleDemoInit();

    //---------------------------------------------------------------------------------
    // Main application loop
    //---------------------------------------------------------------------------------
    
    // Print our message to the screen.
    // The \x1b[2J; command is an ANSI escape code to clear the screen first.
    iprintf("\x1b[2J;"); // Clear console
    iprintf("Hello, World!\n");
    iprintf("This is running on the\n");
    iprintf("DSi's ARM946E-S CPU.\n\n");
    
    iprintf("Press START to exit.");


    while(1) {
        
        // Scans the hardware for key presses.
        scanKeys();
        
        // 'keysDown()' returns the keys that were just pressed in this frame.
        int keys = keysDown();
        
        if (keys & KEY_START) {
            break; // Exit the loop if START is pressed.
        }

        // 'swiWaitForVBlank()' is a crucial function for homebrew.
        // It pauses the CPU until the screen has finished drawing the current
        // frame (the "Vertical Blanking" interval). This has two benefits:
        // 1. It prevents screen tearing.
        // 2. It saves a lot of battery by not running the CPU at 100% constantly.
        swiWaitForVBlank();
    }

    // The application will exit back to the homebrew menu (like TWiLight Menu++).
    return 0;
}
