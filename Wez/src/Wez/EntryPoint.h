#pragma once

#ifdef WEZ_PLATFORM_WINDOWS

extern Wez::Application* Wez::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Wez::CreateApplication();
	app->Run();
	delete app;
}

#endif