#pragma once

#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <string>
#include <fstream>
#include <sstream>
#include <exception>
#include <iostream>

namespace FieldConverter
{


	class Config
	{
	public:
		class BadConfigFile : public std::runtime_error
		{
		public:
			BadConfigFile() = delete;
			BadConfigFile(const std::string &error) : std::runtime_error(error) {}
		};

	private:

		unsigned int	m_width;
		unsigned int	m_height;
		float			m_scale;
		std::string		m_path;
		static Config	m_instance;

		Config();

	public:
		Config(const Config &other) = delete;
		Config &operator=(const Config& other) = delete;

		static Config	&getInstance();
		void			initialize();

		int				getWidth() const;
		int				getHeight() const;
		float			getScale() const;
		std::string		getPath() const;

		~Config();

	};
}

#endif
