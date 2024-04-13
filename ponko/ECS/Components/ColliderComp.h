/**
* @filename:	ColliderComp.h
* @author:		weijie
* @date:		13 Apr 2024
* @breif:		Collider component
*/

#ifndef COLLIDERCOMP_H
#define COLLIDERCOMP_H
#include "ECS/ECS.h"
#include "Math/Vec3.h"
#include "ECS/Components/allComps.h" // In case need transform for collision

struct AABB
{
	Vec3<float> min_pt{};
	Vec3<float> max_pt{};

	AABB() {}
	AABB(Vec3<float> _pos, Vec3<float> _widheight)
	{
		min_pt.x = _pos.x - (_widheight.x / 2.0f);
		min_pt.y = _pos.y - (_widheight.y / 2.0f);

		max_pt.x = _pos.x + (_widheight.x / 2.0f);
		max_pt.y = _pos.y + (_widheight.y / 2.0f);
	}
};

struct ColliderComp : public Component
{
	ColliderComp() {}
	ColliderComp(AABB _aabb) : m_aabb( _aabb ) {};

	bool AABB_Point(Vec3<float> cursor)
	{
		return	cursor.x > m_aabb.min_pt.x && cursor.x < m_aabb.max_pt.x &&
				cursor.y > m_aabb.min_pt.y && cursor.y < m_aabb.max_pt.y;
	}

	AABB m_aabb{};
};

#endif // !COLLIDERCOMP_H
