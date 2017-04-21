// This is the main DLL file.
#pragma once
#define SKEIN_MAIN_DLL
#include "TF256.cpp"
#include "TF512.cpp"
#include "TF1024.cpp"
#include "SkeinCore.h"
#include "SkeinEx.cpp"
#include "System.Security.Cryptography.SkeinXManaged.cpp" // contains definitions for all 3 state-sizes
#include "System.Security.Cryptography.HMACSkeinXManaged.cpp" // contains definitions for all 3 state-sizes
#include "SkeinDeriveBytes.cpp"
