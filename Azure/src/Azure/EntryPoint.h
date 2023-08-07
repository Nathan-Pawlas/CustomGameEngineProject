#pragma once

#ifdef AZ_PLATFORM_WINDOWS

extern Azure::Application* Azure::CreateApplication();

#include <stdio.h>

int main(int argc, char** argv)
{
	Azure::Log::Init();
	auto app = Azure::CreateApplication();
	app->Run();
	delete app;
}

#endif