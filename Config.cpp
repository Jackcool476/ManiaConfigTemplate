// IMPORTANT: If you build this, your mod will crash on boot what did you expect. If you want to build using this file, remove the template fucntions and items in the configschema.xml.
//            The dll doesn't like it when you enter a file location which doesn't exist so that may also be a viable reason for your mod crashing.

//            also remember to go copy all the stuff in mod-loader-common to mania-mod-loader/mod-loader-common

#include "pch.h" // adds all the headers needed to build
using std::string;               // makes the code way smaller 
using namespace std::filesystem; // so you don't have to write it everywhere

extern "C" // ??? no idea ngl
{
	__declspec(dllexport) void Init(const char* path) // creates a varaible called path which contains the filepath of your mod's dll: your mod folder
	{
		const IniFile* config = new IniFile(string(path) + "/config.ini"); // creates a variable called config which contains the information stored in the users configuration
		string sprites = path + string("/Sprites/"); // an example of a folder containing your mod's data like sprites and music.
		string modfolder = path + string("/Data/Sprites/"); // an example of a folder where you will put your mod's data according to the config.

		if (config->getInt("Green Hill", "gh1", 1) == 1) // these whole 
		{
			copy_file(music + "GreenHill.brstm", data + "GreenHill1.brstm", copy_options::overwrite_existing);
		}
		else if (config->getInt("Green Hill", "gh1", 1) == 2)
		{
			copy_file(music + "GreenHillEX.brstm", data + "GreenHill1.brstm", copy_options::overwrite_existing);
		}
		else
		{
			remove((data + "GreenHill1.brstm").c_str());
		}

		string data = path + string("/Data/Music/");
		string music = path + string("/Music/");
		// Green Hill
		if (config->getInt("Green Hill", "gh1", 1) == 1)
		{
			copy_file(music + "GreenHill.brstm", data + "GreenHill1.brstm", copy_options::overwrite_existing);
		}
		else if (config->getInt("Green Hill", "gh1", 1) == 2)
		{
			copy_file(music + "GreenHillEX.brstm", data + "GreenHill1.brstm", copy_options::overwrite_existing);
		}
		else
		{
			remove((data + "GreenHill1.brstm").c_str());
		}
	}
	__declspec(dllexport) ModInfo ManiaModInfo = { ModLoaderVer, GameVer };
}