# DLL based C++ minecraft chams

This repository demonstrates a very simple way of achieving chams in older Minecraft versions. By hooking `glScalef` via MinHook, we can identify when entity/player models are being drawn and apply custom OpenGL rendering states (such as disabling depth testing, disabling lighting, or setting custom colors) before passing execution to the original function.

## Key Information

* **Tested Version**: Tested and verified on Minecraft 1.8.9. Slightly later versions could also work depending on how they utilize fixed-function OpenGL scaling.
* **Shaders**: Because this project intercepts standard OpenGL calls, adding support for custom shaders would be very straightforward to implement.
* **Purpose**: This project is being released just in case some people were wondering or haven't figured out how to implement chams at this level.
