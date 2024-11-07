##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=first-assignment
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/Lopex/Documents/GitHub/first-assignment-ds-2024-2025-cepepe/first-assignment-ws
ProjectPath            :=C:/Users/Lopex/Documents/GitHub/first-assignment-ds-2024-2025-cepepe/first-assignment-ws/first-assignment
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/first-assignment
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Lopex
Date                   :=11/2/2024
CodeLitePath           :="C:/Program Files/CodeLite"
MakeDirCommand         :=mkdir
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=C:/Users/Lopex/Documents/GitHub/first-assignment-ds-2024-2025-cepepe/first-assignment-ws/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  -O0
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/TDM-GCC-64/bin/ar.exe -r
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -Wall $(Preprocessors)
CFLAGS   :=   $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/OpStack.cpp$(ObjectSuffix) $(IntermediateDirectory)/Operation.cpp$(ObjectSuffix) $(IntermediateDirectory)/DoublyLinkedList.cpp$(ObjectSuffix) $(IntermediateDirectory)/Core.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/QueuePixel.cpp$(ObjectSuffix) $(IntermediateDirectory)/ElemPixel.cpp$(ObjectSuffix) $(IntermediateDirectory)/StackDS.cpp$(ObjectSuffix) $(IntermediateDirectory)/SortedDoublyLList.cpp$(ObjectSuffix) $(IntermediateDirectory)/QueueDS.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/peque-image-manager_TinyImageJM.cpp$(ObjectSuffix) $(IntermediateDirectory)/peque-image-manager_RGBPixelXY.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@if not exist "$(OutputDirectory)" $(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/OpStack.cpp$(ObjectSuffix): OpStack.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Lopex/Documents/GitHub/first-assignment-ds-2024-2025-cepepe/first-assignment-ws/first-assignment/OpStack.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/OpStack.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OpStack.cpp$(PreprocessSuffix): OpStack.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OpStack.cpp$(PreprocessSuffix) OpStack.cpp

$(IntermediateDirectory)/Operation.cpp$(ObjectSuffix): Operation.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Lopex/Documents/GitHub/first-assignment-ds-2024-2025-cepepe/first-assignment-ws/first-assignment/Operation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Operation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Operation.cpp$(PreprocessSuffix): Operation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Operation.cpp$(PreprocessSuffix) Operation.cpp

$(IntermediateDirectory)/DoublyLinkedList.cpp$(ObjectSuffix): DoublyLinkedList.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Lopex/Documents/GitHub/first-assignment-ds-2024-2025-cepepe/first-assignment-ws/first-assignment/DoublyLinkedList.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DoublyLinkedList.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DoublyLinkedList.cpp$(PreprocessSuffix): DoublyLinkedList.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DoublyLinkedList.cpp$(PreprocessSuffix) DoublyLinkedList.cpp

$(IntermediateDirectory)/Core.cpp$(ObjectSuffix): Core.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Lopex/Documents/GitHub/first-assignment-ds-2024-2025-cepepe/first-assignment-ws/first-assignment/Core.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Core.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Core.cpp$(PreprocessSuffix): Core.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Core.cpp$(PreprocessSuffix) Core.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Lopex/Documents/GitHub/first-assignment-ds-2024-2025-cepepe/first-assignment-ws/first-assignment/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/QueuePixel.cpp$(ObjectSuffix): QueuePixel.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Lopex/Documents/GitHub/first-assignment-ds-2024-2025-cepepe/first-assignment-ws/first-assignment/QueuePixel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/QueuePixel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/QueuePixel.cpp$(PreprocessSuffix): QueuePixel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/QueuePixel.cpp$(PreprocessSuffix) QueuePixel.cpp

$(IntermediateDirectory)/ElemPixel.cpp$(ObjectSuffix): ElemPixel.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Lopex/Documents/GitHub/first-assignment-ds-2024-2025-cepepe/first-assignment-ws/first-assignment/ElemPixel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ElemPixel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ElemPixel.cpp$(PreprocessSuffix): ElemPixel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ElemPixel.cpp$(PreprocessSuffix) ElemPixel.cpp

$(IntermediateDirectory)/StackDS.cpp$(ObjectSuffix): StackDS.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Lopex/Documents/GitHub/first-assignment-ds-2024-2025-cepepe/first-assignment-ws/first-assignment/StackDS.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/StackDS.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/StackDS.cpp$(PreprocessSuffix): StackDS.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/StackDS.cpp$(PreprocessSuffix) StackDS.cpp

$(IntermediateDirectory)/SortedDoublyLList.cpp$(ObjectSuffix): SortedDoublyLList.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Lopex/Documents/GitHub/first-assignment-ds-2024-2025-cepepe/first-assignment-ws/first-assignment/SortedDoublyLList.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SortedDoublyLList.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SortedDoublyLList.cpp$(PreprocessSuffix): SortedDoublyLList.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SortedDoublyLList.cpp$(PreprocessSuffix) SortedDoublyLList.cpp

$(IntermediateDirectory)/QueueDS.cpp$(ObjectSuffix): QueueDS.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Lopex/Documents/GitHub/first-assignment-ds-2024-2025-cepepe/first-assignment-ws/first-assignment/QueueDS.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/QueueDS.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/QueueDS.cpp$(PreprocessSuffix): QueueDS.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/QueueDS.cpp$(PreprocessSuffix) QueueDS.cpp

$(IntermediateDirectory)/peque-image-manager_TinyImageJM.cpp$(ObjectSuffix): peque-image-manager/TinyImageJM.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Lopex/Documents/GitHub/first-assignment-ds-2024-2025-cepepe/first-assignment-ws/first-assignment/peque-image-manager/TinyImageJM.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/peque-image-manager_TinyImageJM.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/peque-image-manager_TinyImageJM.cpp$(PreprocessSuffix): peque-image-manager/TinyImageJM.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/peque-image-manager_TinyImageJM.cpp$(PreprocessSuffix) peque-image-manager/TinyImageJM.cpp

$(IntermediateDirectory)/peque-image-manager_RGBPixelXY.cpp$(ObjectSuffix): peque-image-manager/RGBPixelXY.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Lopex/Documents/GitHub/first-assignment-ds-2024-2025-cepepe/first-assignment-ws/first-assignment/peque-image-manager/RGBPixelXY.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/peque-image-manager_RGBPixelXY.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/peque-image-manager_RGBPixelXY.cpp$(PreprocessSuffix): peque-image-manager/RGBPixelXY.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/peque-image-manager_RGBPixelXY.cpp$(PreprocessSuffix) peque-image-manager/RGBPixelXY.cpp

##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


