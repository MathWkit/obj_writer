﻿#include "Polygon.h"
#include <stdexcept>

Polygon::Polygon() = default;

void Polygon::set_vertex_indices(const std::vector<int>& t_vertex_indices)
{
	if (t_vertex_indices.size() < 3)
	{
		throw std::invalid_argument("Полигон должен содержать хотя бы 3 вершины");
	}
	vertex_indices = t_vertex_indices;
}

void Polygon::set_normal_indices(const std::vector<int>& t_normal_indices)
{
	if (t_normal_indices.size() < 3)
	{
		throw std::invalid_argument("Полигон должен содержать хотя бы 3 нормали");
	}
	normal_indices = t_normal_indices;
}

void Polygon::set_texture_indices(const std::vector<int>& t_texture_indices)
{
	if (t_texture_indices.size() < 3)
	{
		throw std::invalid_argument("Полигон должен содержать хотя бы 3 текстурные координаты");
	}
	texture_indices = t_texture_indices;
}

std::vector<int> Polygon::get_vertex_indices() const
{
	return vertex_indices;
}

std::vector<int> Polygon::get_normal_indices() const
{
	return normal_indices;
}

std::vector<int> Polygon::get_texture_indices() const
{
	return texture_indices;
}

Polygon::~Polygon() = default;
