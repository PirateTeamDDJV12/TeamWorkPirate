#include <fstream>
#include <sstream>

#include "Config.hpp"

using FieldConverter::Config;

std::unique_ptr<Config> Config::m_instance = nullptr;

Config::Config() : m_width{ 0 }, m_height{ 0 }, m_scale{ 0.0f }, m_path{}
{
    initialize();
}

void Config::initialize()
{
    std::ifstream configFile("Ressources/heightmap.onf");
    std::string type;
    std::string value;
    std::stringstream ss;


    if (configFile.bad() || configFile.fail())
    {
        throw BadConfigFile("ERROR : Wrong config file path");
    }
    while (std::getline(configFile, type, '='))
    {
        std::getline(configFile, value);

        ss << value;

        if (type == "path")
        {
            ss >> m_path;
        }
        else if (type == "width")
        {
            ss >> m_width;
        }
        else if (type == "height")
        {
            ss >> m_height;
        }
        else if (type == "scale")
        {
            ss >> m_scale;
        }
        ss.str(std::string());
        ss.clear();
    }
    if (m_width != m_height || m_width == 0 || m_path.empty())
    {
        throw BadConfigFile("ERROR : Wrong config file content");
    }
}

Config &Config::getInstance()
{
    if (m_instance == nullptr)
    {
        m_instance.reset(new Config);
    }

    return *m_instance;
}

int Config::getWidth() const
{
    return m_width;
}

int Config::getHeight() const
{
    return m_height;
}

float Config::getScale() const
{
    return m_scale;
}

std::string Config::getPath() const
{
    return m_path;
}

Config::~Config()
{
}
