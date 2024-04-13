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

class TransformComp : public Component
{
public:
	Vec3<float>& GetPos() { return m_pos; }

private:
	Vec3<float> m_pos{};
};


#endif // !TRANSFORMCOMP_H
