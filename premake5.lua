workspace "Robot-CMDEngine"
    architecture "x64"
    startproject "Robot-Examples"

    configurations
    {
        "Debug",
        "Release"
    }

    outputdirTarget = "bin/%{cfg.buildcfg}/%{cfg.system}"
    outputdirObject = "bin-int/%{cfg.buildcfg}/%{cfg.system}"

project "Robot-CMDEngine"
    location "%{prj.name}"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir (outputdirTarget .. "/%{prj.name}")
    objdir (outputdirObject .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    filter "system:windows"
        systemversion "latest"

        includedirs
        {
            "%{prj.name}/src"
        }

        defines
        {
            "NOMINMAX"
        }

    filter "system:macosx"
        systemversion "latest"
        toolset "clang"

        sysincludedirs
        {
            "%{prj.name}/src"
        }

    filter "system:linux"
        systemversion "latest"
        toolset "clang"

        sysincludedirs
        {
            "%{prj.name}/src"
        }

    filter "configurations:Debug"
        defines "ROBOT_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "ROBOT_RELEASE"
        runtime "Release"
        symbols "on"

project "Robot-Examples"
    location "%{prj.name}"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir (outputdirTarget .. "/%{prj.name}")
    objdir (outputdirObject .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    links
    {
        "Robot-CMDEngine"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    filter "system:windows"
        systemversion "latest"

        includedirs
        {
            "%{prj.name}/src",
			"Robot-CMDEngine/src"
        }

        defines
        {
            "NOMINMAX"
        }

    filter "system:macosx"
        systemversion "latest"
        toolset "clang"

        sysincludedirs
        {
            "%{prj.name}/src",
			"Robot-CMDEngine/src"
        }

    filter "system:linux"
        systemversion "latest"
        toolset "clang"

        sysincludedirs
        {
            "%{prj.name}/src",
			"Robot-CMDEngine/src"
        }

    filter "configurations:Debug"
        defines "ROBOT_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "ROBOT_RELEASE"
        runtime "Release"
        symbols "on"
