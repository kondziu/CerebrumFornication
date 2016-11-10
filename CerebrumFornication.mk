##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=CerebrumFornication
ConfigurationName      :=Debug
WorkspacePath          :=/home/ksiek/CodeLite
ProjectPath            :=/home/ksiek/Workspace/cerebrumfornication/CerebrumFornication
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Konrad Siek
Date                   :=10/11/16
CodeLitePath           :=/home/ksiek/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="CerebrumFornication.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall -I/usr/lib/llvm-3.8/include -std=c++0x -gsplit-dwarf -Wl,-fuse-ld=gold -fPIC -fvisibility-inlines-hidden -Wall -W -Wno-unused-parameter -Wwrite-strings -Wcast-qual -Wno-missing-field-initializers -pedantic -Wno-long-long -Wno-maybe-uninitialized -Wdelete-non-virtual-dtor -Wno-comment -std=c++11 -ffunction-sections -fdata-sections -O2 -g -DNDEBUG -fno-exceptions -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -L/usr/lib/llvm-3.8/lib -lLLVMCore -lLLVMSupport -lrt -ldl -ltinfo -lpthread -lz -lm $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall -I/usr/lib/llvm-3.8/include -std=c++0x -gsplit-dwarf -Wl,-fuse-ld=gold -fPIC -fvisibility-inlines-hidden -Wall -W -Wno-unused-parameter -Wwrite-strings -Wcast-qual -Wno-missing-field-initializers -pedantic -Wno-long-long -Wno-maybe-uninitialized -Wdelete-non-virtual-dtor -Wno-comment -std=c++11 -ffunction-sections -fdata-sections -O2 -g -DNDEBUG -fno-exceptions -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -L/usr/lib/llvm-3.8/lib -lLLVMCore -lLLVMSupport -lrt -ldl -ltinfo -lpthread -lz -lm $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/lexer.cpp$(ObjectSuffix) $(IntermediateDirectory)/parser.cpp$(ObjectSuffix) $(IntermediateDirectory)/cg.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ksiek/Workspace/cerebrumfornication/CerebrumFornication/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix)main.cpp

$(IntermediateDirectory)/lexer.cpp$(ObjectSuffix): lexer.cpp $(IntermediateDirectory)/lexer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ksiek/Workspace/cerebrumfornication/CerebrumFornication/lexer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lexer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lexer.cpp$(DependSuffix): lexer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lexer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/lexer.cpp$(DependSuffix) -MM lexer.cpp

$(IntermediateDirectory)/lexer.cpp$(PreprocessSuffix): lexer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lexer.cpp$(PreprocessSuffix)lexer.cpp

$(IntermediateDirectory)/parser.cpp$(ObjectSuffix): parser.cpp $(IntermediateDirectory)/parser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ksiek/Workspace/cerebrumfornication/CerebrumFornication/parser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/parser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/parser.cpp$(DependSuffix): parser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/parser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/parser.cpp$(DependSuffix) -MM parser.cpp

$(IntermediateDirectory)/parser.cpp$(PreprocessSuffix): parser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/parser.cpp$(PreprocessSuffix)parser.cpp

$(IntermediateDirectory)/cg.cpp$(ObjectSuffix): cg.cpp $(IntermediateDirectory)/cg.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ksiek/Workspace/cerebrumfornication/CerebrumFornication/cg.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cg.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cg.cpp$(DependSuffix): cg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cg.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cg.cpp$(DependSuffix) -MM cg.cpp

$(IntermediateDirectory)/cg.cpp$(PreprocessSuffix): cg.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cg.cpp$(PreprocessSuffix)cg.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


