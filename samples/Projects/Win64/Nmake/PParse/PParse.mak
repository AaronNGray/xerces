# Microsoft Developer Studio Generated NMAKE File, Based on PParse.dsp
!IF "$(CFG)" == ""
CFG=PParse - Win64 Debug
!MESSAGE No configuration specified. Defaulting to PParse - Win64 Debug.
!ENDIF 

!IF "$(CFG)" != "PParse - Win64 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PParse.mak" CFG="PParse - Win64 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PParse - Win64 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

OUTDIR=.\..\..\..\..\..\bin
INTDIR=.\..\..\..\..\..\bin\obj
# Begin Custom Macros
OutDir=.\..\..\..\..\..\bin
# End Custom Macros

ALL : "$(OUTDIR)\PParse.exe"


CLEAN :
	-@erase "$(INTDIR)\PParse.obj"
	-@erase "$(INTDIR)\PParseHandlers.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\PParse.exe"
	-@erase "$(OUTDIR)\PParse.ilk"
	-@erase "$(OUTDIR)\PParse.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=$(CPP)
CPP_PROJ= /MDd /W3 /Gm /GX /Zi /Od /I "..\..\..\..\..\include" /D "PROJ_SAXCOUNT" /D "_DEBUG" /D "WIN32" /D "WIN64" /D "_CONSOLE" /D "PLATFORM_WIN32" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
#BSC32=bscmake.exe
BSC32_FLAGS=/o"$(OUTDIR)\PParse.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib xerces-c_2D.lib /version:1.0 /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\PParse.pdb" /debug /machine:IX86 /out:"$(OUTDIR)\PParse.exe" /pdbtype:sept /libpath:"..\..\..\..\..\lib" /machine:IA64 
LINK32_OBJS= \
	"$(INTDIR)\PParse.obj" \
	"$(INTDIR)\PParseHandlers.obj"

"$(OUTDIR)\PParse.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("PParse.dep")
!INCLUDE "PParse.dep"
!ELSE 
!MESSAGE Warning: cannot find "PParse.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "PParse - Win64 Debug"
SOURCE=..\..\..\..\PParse\PParse.cpp

"$(INTDIR)\PParse.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\PParse\PParseHandlers.cpp

"$(INTDIR)\PParseHandlers.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

