workspace "DxMinecraft"
    architecture "x64"
    configurations {"Debug", "Release"}
    startproject "DxMinecraft"

    filter "system:windows"
        buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus", "/sdl" }

outputdir = "Build/" .. "%{cfg.buildcfg}"

project "DxMinecraft"
    kind "WindowedApp"
    language "C++"
    cppdialect "C++23"
    targetdir ("Build/" .. "%{cfg.buildcfg}")
    objdir ("Intermediate/" .. "%{cfg.buildcfg}")
    location "Intermediate/ProjectFiles"
    staticruntime "off"
    warnings "Extra"
    floatingpoint "Fast"
    
    files {
        "Source/**.h",
        "Source/**.hpp",
        "Source/**.cpp",
        "Resources/DxMinecraft.rc",
        "Resources/resource.h"
    }

    includedirs {
        "Source/Public",
        "Source/Public/**",
        "Resources"
    }

    links {
        "d3d12",
        "d3dcompiler",
        "dxgi",
        "dxguid"
    }

    filter "system:windows"
       systemversion "latest"
       defines { "WINDOWS" }

        postbuildcommands
        {
            '{MKDIR} "%{cfg.targetdir}/D3D12"',
            '{COPYFILE} "%{wks.location}/Vendor/AgilitySDK/d3d12.1.619.2/bin/x64/D3D12Core.dll" "%{cfg.targetdir}/D3D12"',
        }

   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"

       postbuildcommands
       {
            '{COPYFILE} "%{wks.location}/Vendor/AgilitySDK/d3d12.1.619.2/bin/x64/d3d12SDKLayers.dll" "%{cfg.targetdir}/D3D12"'
       }

   filter "configurations:Release"
       defines { "RELEASE", "NDEBUG" }
       runtime "Release"
       optimize "On"
       symbols "On"
       linktimeoptimization "On"
