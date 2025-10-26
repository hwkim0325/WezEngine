#pragma once

#ifdef WEZ_PLATFORM_WINDOWS

extern Wez::Application* Wez::CreateApplication();

int main(int argc, char** argv)
{
	Wez::Log::Init();
	WEZ_CORE_WARN("Initialized Log!");
	int var = 5;
	WEZ_CORE_INFO("Hello! Var={0}", var);

	auto app = Wez::CreateApplication();
	app->Run();
	delete app;
}

#endif