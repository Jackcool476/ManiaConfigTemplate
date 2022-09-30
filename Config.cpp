// IMPORTANT: If you build this, your mod will crash on boot what did you expect. If you want to build using this file, remove the template fucntions and items in the configschema.xml.
//            The dll doesn't like it when you enter a file location which doesn't exist so that may also be a viable reason for your mod crashing.

#define WIN32_LEAN_AND_MEAN // angy, makes builds faster iirc
#include <windows.h>
#include <filesystem>
#include "IniFile.hpp"
#include "ManiaModLoader.h"

using std::string;               // makes the code way smaller 
using namespace std::filesystem; // so you don't have to write it everywhere

extern "C" // ??? no idea ngl
{
	__declspec(dllexport) void Init(const char* path) // creates a varaible called path which contains the filepath of your mod's dll: your mod folder
	{
		const IniFile* config = new IniFile(string(path) + "/config.ini"); // creates a variable called config which contains the information stored in the users configuration
		string sprites = path + string("/Sprites/"); // an example of a folder containing your mod's data like sprites and music.
		string modfolder = path + string("/Data/Sprites/"); // an example of a folder where you will put your mod's data according to the config.

		// Example of Chemical Plant section from my mania mod
		string datas = path + string("/Data/Stages/");
		string stages = path + string("/Stages/");
		if (config->getBool("Chemical Plant", "cp1", true))
		{
			copy_file(stages + "CPZ/Scene1.bin", datas + "CPZ/Scene1.bin", copy_options::overwrite_existing);
		}
		else
		{
			remove(datas + "CPZ/Scene1.bin)");
		}
	}
	__declspec(dllexport) ModInfo ManiaModInfo = { ModLoaderVer, GameVer }; // Adds dll info so it likey idk
}