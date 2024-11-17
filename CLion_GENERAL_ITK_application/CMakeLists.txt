cmake_minimum_required(VERSION 3.15)
project(GENERAL_ITK_application)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(
        "C:/Siemens/Teamcenter13/include"
        "C:/Siemens/Teamcenter13/include_cpp"
)

# Source files
set(SOURCES
        main.cpp
        # Remove 'helper.hpp' if it's just a header
)

# Preprocessor definitions
add_definitions(
        -DNT40
        -DPOMDLL
        -DCRTAPI1=_cdecl
        -DCRTAPI2=cdecl
        -D_WIN32
        -DWIN64
        -DWIN32_LEAN_AND_MEAN
        -DWNT
        -DBYPASS_FLEX
        -D_INTEL=1
        -DIPLIB=none
)

# Link directories
link_directories(
        "C:/Siemens/Teamcenter13/lib"
)

# Libraries to link (remove 'itk_main.obj')
set(LIBS
        libsyss.lib
        libpom.lib
        libtcsso.lib
        libae.lib
        libappr.lib
        libarchive.lib
        libbackup.lib
        libbom.lib
        libcfm.lib
        libconstants.lib
        libcxpom.lib
        libdmi.lib
        libecm.lib
        libeint.lib
        libepm.lib
        libfclasses.lib
        libform.lib
        libgms.lib
        libgrm.lib
        libtcinit.lib
        libtc.lib
        libtccore.lib
        libtctrushape.lib
        libinternal_exits.lib
        libvalidation.lib
        libitk.lib
        liblov.lib
        libme.lib
        libmgc.lib
        libobjio.lib
        libpie.lib
        libai.lib
        libproperty.lib
        libps.lib
        libpublication.lib
        libqry.lib
        libclips.lib
        libclipsutil.lib
        librbf.lib
        libce.lib
        libres.lib
        libsa.lib
        libss.lib
        libstep.lib
        libsub_mgr.lib
        libtextsrv.lib
        libtie.lib
        libnxmgr_im.lib
        libaie.lib
        libics.lib
        libeintstub.lib
        libsml.lib
        libuser_exits.lib
        librdv.lib
        libcollabctx.lib
        libmechatronics.lib
        libtccoreext.lib
        libusagewc.lib
        libusage.lib
        libcontmgmt.lib
        libtc_utils.lib
        libschmgt.lib
        libschmgt_bridge.lib
        libdocmgt.lib
        libdocmgtapp.lib
        libvm.lib
        libadsfoundationdispatch.lib
        libcm.lib
        libcmdispatch.lib
        libconstants.lib
        libbase_utils.lib
        libmld.lib
        libfunctionality.lib
        libmfg.lib
        libmfgbvr.lib
        libnls.lib
        libcondvalidation.lib
        libbooleanmath.lib
        libconfigurator.lib
        libfnd0booleansolve.lib
        libsecore.lib
        libFnd0formulamgmt.lib
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} ${LIBS})

# Compiler and linker options for MSVC
if(MSVC)
    # Compiler options
    target_compile_options(${PROJECT_NAME} PRIVATE /W3 /MD)
    # Suppress specific warnings if needed
    target_compile_options(${PROJECT_NAME} PRIVATE /wd4099 /wd4199)

    # Linker options
    set_target_properties(${PROJECT_NAME} PROPERTIES
            LINK_FLAGS "/SUBSYSTEM:CONSOLE /MACHINE:X64"
    )

    # Delay-loaded DLLs
    target_link_options(${PROJECT_NAME} PRIVATE
            "/DELAYLOAD:libtcsso.dll"
            "/DELAYLOAD:libict.dll"
            # ... add other delay-loaded DLLs
    )

    # Add the object file to the linker command line
    target_link_options(${PROJECT_NAME} PRIVATE "C:/Siemens/Teamcenter13/lib/itk_main.obj")
endif()

# Configuration-specific settings
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE DEBUG)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(${PROJECT_NAME} PRIVATE NDEBUG)
endif()