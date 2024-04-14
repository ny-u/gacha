/**
* @filename:	EntityFactory.h
* @author:		weijie
* @date:		14 Apr 2024
* @breif:		making certain entities easier
*/

#include <Math/Vec3.h>

namespace PonkoEnv
{
	Entity& MakeCollider(Entity& _entity, Vec3<float> _pos, Vec3<float> _widheight);
	Entity& MakeButton(Entity& _entity, Vec3<float> _pos, Vec3<float> _widheight, const char* _filepathImg);
}