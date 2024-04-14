/**
* @file:	TransformComp.h
* @author:	weijie
* @date:	13 Apr 2024
* @brief:	Component for obj location
*/

#ifndef TRANSFORMCOMP_H
#define TRANSFORMCOMP_H

#include "ECS/ECS.h"
#include "Math/Vec3.h"

struct TransformComp : public Component
{
	TransformComp() {}
	TransformComp(Vec3<float> _pos) : m_pos(_pos) {}


	Vec3<float>		m_pos{};
	float			rotate{};
};


#endif // !TRANSFORMCOMP_H
