#pragma once

#ifdef WEZ_PLATFORM_WINDOWS

extern Wez::Application* Wez::CreateApplication();

int main(int argc, char** argv)
{
	Wez::Log::Init();

	auto app = Wez::CreateApplication();
	app->Run();
	delete app;
}

#endif