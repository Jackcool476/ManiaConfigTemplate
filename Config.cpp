#include "pch.h"
using std::string;
using namespace std::filesystem;

extern "C"
{
	__declspec(dllexport) void Init(const char* path)
	{
		const IniFile* config = new IniFile(string(path) + "/config.ini");
		string data = path + string("/Data/Music/");
		string music = path + string("/Music/");
		string soundfx = path + string("/Data/SoundFX/Stage/");

		// Green Hill
		if (config->getInt("Green Hill", "gh1", 1) == 1)
		{
			copy_file(music + "GreenHill.brstm", data + "GreenHill1.brstm", copy_options::overwrite_existing);
		}
		else if (config->getInt("Green Hill", "gh1", 1) == 2)
		{
			copy_file(music + "GreenHillEX.brstm", data + "GreenHill1.brstm", copy_options::overwrite_existing);
		}
		else if (config->getInt("Green Hill", "gh1", 1) == 3)
		{
			copy_file(music + "AngelIsland.brstm", data + "GreenHill1.brstm", copy_options::overwrite_existing);
		}
		else if (config->getInt("Green Hill", "gh1", 1) == 4)
		{
			copy_file(music + "EmeraldHill.brstm", data + "GreenHill1.brstm", copy_options::overwrite_existing);
		}
		else if (config->getInt("Green Hill", "gh1", 1) == 5)
		{
			copy_file(music + "LostValley.brstm", data + "GreenHill1.brstm", copy_options::overwrite_existing);
		}
		else
		{
			remove((data + "GreenHill1.brstm").c_str());
		}
	}
	__declspec(dllexport) ModInfo ManiaModInfo = { ModLoaderVer, GameVer };
}