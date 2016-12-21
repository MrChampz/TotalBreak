/*******************************************************************
** This code is part of TotalBreak.
**
** TotalBreak is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#pragma once

#include <map>
#include <string>

#include <GL/glew.h>

#include "Texture.h"
#include "Shader.h"

// A static singleton ResourceManager class that hosts several
// functions to load Textures and Shaders. Each loaded texture
// handles. All functions and resources are static and no
// public constructor is defined.
class ResourceManager
{
public:
	// Resource storage
	static std::map<std::string, Shader>	Shaders;
	static std::map<std::string, Texture2D>	Textures;

	// Loads (and generate) a shader program from file loading vertex, fragment (and geometry) shader's source code.
	// If gShaderFile is not nullptr, it also loads a geometry shader
	static Shader LoadShader(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile, std::string name);

	// Retrieves a stored shader
	static Shader GetShader(std::string name);

	// Loads (and generates) a texture from file
	static Texture2D LoadTexture(const GLchar* file, GLboolean alpha, std::string name);

	// Retrieve a stored texture
	static Texture2D GetTexture(std::string name);

	// Properly de-allocates all loaded resources
	static void Clear();

private:
	// Private constructor, that is we do not want any actual resource manager objects.
	// Its members and functions should be publicly available (static)
	ResourceManager();

	// Loads and generates a shader from file
	static Shader loadShaderFromFile(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile = nullptr);

	// Loads a single texture from file
	static Texture2D loadTextureFromFile(const GLchar* file, GLboolean alpha);
};
