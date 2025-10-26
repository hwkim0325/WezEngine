workspace "Wez"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" 

project "Wez"
	location "Wez"
	kind "SharedLib"
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
		"Wez/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0"
		
		defines
		{
			"WEZ_PLATFORM_WINDOWS",
			"WEZ_BUILD_DLL",
			"_WINDLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/WezEngine")
		}

	filter "configurations:Debug"
		defines "WEZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "WEZ_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "WEZ_DIST"
		symbols "On"

project "WezEngine"
	location "WezEngine"
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
		"Wez/vendor/spdlog/include",
		"Wez/src"
	}

	links
	{
		"Wez"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0"
		
		defines
		{
			"WEZ_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "WEZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "WEZ_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "WEZ_DIST"
		symbols "On"

	filter {"system:windows", "configurations:Release"}
		buildoptions "/MT"
