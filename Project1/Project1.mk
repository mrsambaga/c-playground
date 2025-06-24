##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Project1
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=D:/Projects/c-playground
ProjectPath            :=D:/Projects/c-playground/Project1
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/Project1
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=CHEMONK
Date                   :=24/06/2025
CodeLitePath           :="C:/Program Files/CodeLite"
MakeDirCommand         :=mkdir -p
LinkerName             :=C:/cygwin64/bin/gcc.exe
SharedObjectLinkerName :=C:/cygwin64/bin/gcc.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=D:/Projects/c-playground/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  -static
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/cygwin64/bin/ar.exe rcu
CXX      := C:/cygwin64/bin/x86_64-pc-cygwin-g++.exe
CC       := C:/cygwin64/bin/gcc.exe
CXXFLAGS :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -O0 -gdwarf-2 -std=c99 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/cygwin64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/tictactoe.c$(ObjectSuffix) $(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/arrays.c$(ObjectSuffix) $(IntermediateDirectory)/string.c$(ObjectSuffix) $(IntermediateDirectory)/loop.c$(ObjectSuffix) $(IntermediateDirectory)/functions.c$(ObjectSuffix) $(IntermediateDirectory)/basic.c$(ObjectSuffix) $(IntermediateDirectory)/conditionalStatement.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@$(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/tictactoe.c$(ObjectSuffix): tictactoe.c $(IntermediateDirectory)/tictactoe.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Projects/c-playground/Project1/tictactoe.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tictactoe.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tictactoe.c$(DependSuffix): tictactoe.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tictactoe.c$(ObjectSuffix) -MF$(IntermediateDirectory)/tictactoe.c$(DependSuffix) -MM tictactoe.c

$(IntermediateDirectory)/tictactoe.c$(PreprocessSuffix): tictactoe.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tictactoe.c$(PreprocessSuffix) tictactoe.c

$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Projects/c-playground/Project1/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/arrays.c$(ObjectSuffix): arrays.c $(IntermediateDirectory)/arrays.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Projects/c-playground/Project1/arrays.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/arrays.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/arrays.c$(DependSuffix): arrays.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/arrays.c$(ObjectSuffix) -MF$(IntermediateDirectory)/arrays.c$(DependSuffix) -MM arrays.c

$(IntermediateDirectory)/arrays.c$(PreprocessSuffix): arrays.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/arrays.c$(PreprocessSuffix) arrays.c

$(IntermediateDirectory)/string.c$(ObjectSuffix): string.c $(IntermediateDirectory)/string.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Projects/c-playground/Project1/string.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/string.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/string.c$(DependSuffix): string.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/string.c$(ObjectSuffix) -MF$(IntermediateDirectory)/string.c$(DependSuffix) -MM string.c

$(IntermediateDirectory)/string.c$(PreprocessSuffix): string.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/string.c$(PreprocessSuffix) string.c

$(IntermediateDirectory)/loop.c$(ObjectSuffix): loop.c $(IntermediateDirectory)/loop.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Projects/c-playground/Project1/loop.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/loop.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/loop.c$(DependSuffix): loop.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/loop.c$(ObjectSuffix) -MF$(IntermediateDirectory)/loop.c$(DependSuffix) -MM loop.c

$(IntermediateDirectory)/loop.c$(PreprocessSuffix): loop.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/loop.c$(PreprocessSuffix) loop.c

$(IntermediateDirectory)/functions.c$(ObjectSuffix): functions.c $(IntermediateDirectory)/functions.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Projects/c-playground/Project1/functions.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/functions.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/functions.c$(DependSuffix): functions.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/functions.c$(ObjectSuffix) -MF$(IntermediateDirectory)/functions.c$(DependSuffix) -MM functions.c

$(IntermediateDirectory)/functions.c$(PreprocessSuffix): functions.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/functions.c$(PreprocessSuffix) functions.c

$(IntermediateDirectory)/basic.c$(ObjectSuffix): basic.c $(IntermediateDirectory)/basic.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Projects/c-playground/Project1/basic.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/basic.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/basic.c$(DependSuffix): basic.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/basic.c$(ObjectSuffix) -MF$(IntermediateDirectory)/basic.c$(DependSuffix) -MM basic.c

$(IntermediateDirectory)/basic.c$(PreprocessSuffix): basic.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/basic.c$(PreprocessSuffix) basic.c

$(IntermediateDirectory)/conditionalStatement.c$(ObjectSuffix): conditionalStatement.c $(IntermediateDirectory)/conditionalStatement.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Projects/c-playground/Project1/conditionalStatement.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/conditionalStatement.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/conditionalStatement.c$(DependSuffix): conditionalStatement.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/conditionalStatement.c$(ObjectSuffix) -MF$(IntermediateDirectory)/conditionalStatement.c$(DependSuffix) -MM conditionalStatement.c

$(IntermediateDirectory)/conditionalStatement.c$(PreprocessSuffix): conditionalStatement.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/conditionalStatement.c$(PreprocessSuffix) conditionalStatement.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


