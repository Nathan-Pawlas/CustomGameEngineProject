workspace "Azure"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Azure"
	location "Azure"
	kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "azpch.h"
	pchsource "Azure/src/azpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"$(SolutionDir)Azure/src",
		"$(SolutionDir)Azure/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AZ_PLATFORM_WINDOWS",
			"AZ_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "AZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AZ_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"$(SolutionDir)Azure/vendor/spdlog/include",
		"$(SolutionDir)Azure/src"
	}

	links
	{
		"Azure"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AZ_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AZ_DIST"
		optimize "On"