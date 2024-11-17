# teamcenter-itk-projects-templates

If you want to start developing server-side extensions for Teamcenter using the ITK library in the Microsoft Visual 
Studio Community environment, download the **MSVS_GENERAL_ITK_application** folder. If you prefer JetBrains CLion, 
download the **CLion_GENERAL_ITK_application** folder.

**Setting Up MSVS_GENERAL_ITK_application:**
1. Open the file **GENERAL_ITK_application_tc_133.props** for editing.
2. Modify the paths (I used **C:\Siemens\Teamcenter13**) to match your environment in the following sections of the **.props** file:
```xml
<ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">
<Link>
<GenerateDebugInformation>true</GenerateDebugInformation>
<AdditionalLibraryDirectories>C:\Siemens\Teamcenter13\lib;%(AdditionalLibraryDirectories)</AdditionalLibraryDirectories>
</Link>
</ItemDefinitionGroup>
...
<ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Release|x64'">
<Link>
<GenerateDebugInformation>true</GenerateDebugInformation>
<AdditionalLibraryDirectories>C:\Siemens\Teamcenter13\lib;%(AdditionalLibraryDirectories)</AdditionalLibraryDirectories>
</Link>
</ItemDefinitionGroup>
...
<ClCompile>
<AdditionalIncludeDirectories>C:\Siemens\Teamcenter13\include;C:\Siemens\Teamcenter13\include_cpp;%(AdditionalIncludeDirectories)</AdditionalIncludeDirectories>
<PreprocessorDefinitions>NT40;POMDLL;CRTAPI1=_cdecl;CRTAPI2=cdecl;_WIN32;WIN64;WIN32_LEAN_AND_MEAN;WNT;BYPASS_FLEX;_INTEL=1;IPLIB=none;%(PreprocessorDefinitions)</PreprocessorDefinitions>
</ClCompile>
...
<AdditionalLibraryDirectories>C:\Siemens\Teamcenter13\lib;%(AdditionalLibraryDirectories)</AdditionalLibraryDirectories>
```
3. Save your changes.
4. Open the project in Microsoft Visual Studio and build your first project.


**CLion_GENERAL_ITK_application:**
1. Open the file **CMakeLists.txt** for editing.
2. Modify the paths (I used **C:\Siemens\Teamcenter13**) to match your environment in the following sections 
of the **CMakeLists.txt** file:
```
#Include directories

include_directories(
"C:/Siemens/Teamcenter13/include"
"C:/Siemens/Teamcenter13/include_cpp"
)

#Link directories

link_directories(
"C:/Siemens/Teamcenter13/lib"
)

target_link_options(${PROJECT_NAME} PRIVATE "C:/Siemens/Teamcenter13/lib/itk_main.obj")
endif()
```
3. Save your changes.
4. Open the project in JetBrains CLion and build your first project.