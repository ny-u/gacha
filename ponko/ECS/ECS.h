/**
* @file:	ECS.h
* @author:	weijie
* @date:	13 Apr 2024
* @breif:	ECS? not sure if its the OP kind but gud starting point ig
*/

#ifndef ECS_H
#define ECS_H
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

// Forward Statements
class Component;
class Entity;

using ComponentID = std::size_t;

// inline basically "copy & paste" the function to where its called kinda like a header file
inline ComponentID GetComponentTypeID()
{
	static ComponentID lastID{};
	return lastID++;
}

template <typename T>
inline ComponentID GetComponentTypeID() noexcept		// "noexcept" doesnt really have a code functionality at runtime,
{														// rather its just a hint to the compiler that we are 
	static ComponentID typeID = GetComponentTypeID();	// sure the code doesnt throw exceptions for optimization, throw std::terminate if except happens
	return typeID;

}

constexpr std::size_t maxComponents = 32; // Max amount of components a entity can hold

// ComponentBitSet helps us check if the entity has specific component
// ComponentArray holds pointers to each component a entity holds
using ComponentBitSet	= std::bitset<maxComponents>;
using ComponentArray	= std::array<Component*, maxComponents>;

class Component
{
public:
	Entity* entity{}; // so that it knows who it belongs to

	// virutal functions are just functions that are meant to be over wrtiten by its child classes
	// "pure virtual functions" end with "=0" are basically just a indicator that the function does not have function
	// as virtual functions can have defualt base code
	
	// Commented out for now cuz no real usecase for the way im doing it
	//virtual void Init() {}
	//virtual void Update() {}
	//virtual void Draw() {}

	virtual ~Component() {}

private:
};

class Entity
{
public:

	Entity() {};

	void Update();
	void Draw();
	bool isActive() const;
	void Destroy();

	template<typename T>
	bool hasComponent() const
	{
		return l_comBit[GetComponentTypeID<T>];
	}

	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs)
	{
		T* c{ new T(std::forward<TArgs>(mArgs)...) };
		//T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uPtr{ c };
		l_components.emplace_back(std::move(uPtr));

		l_comArr[GetComponentTypeID<T>()] = c;
		l_comBit[GetComponentTypeID<T>()] = true;

		//c->Init();

		return *c;
	}

	template<typename T>
	T& getComponent() const
	{
		auto ptr(l_comArr[GetComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}



private:
	bool b_active = true; // check if the entity is alive or not if false can remove the entity

	std::vector<std::unique_ptr<Component>> l_components{};
	ComponentArray l_comArr{};
	ComponentBitSet l_comBit{};
};

class EntityManager
{
public:
	EntityManager(EntityManager const&) = delete;
	EntityManager& operator=(EntityManager const&) = delete;

	static EntityManager& Get();

	void Update();
	void Draw();
	void CleanUp();
	Entity& addEntity();

private:
	EntityManager() {};
	std::vector<std::unique_ptr<Entity>> l_entities{};
};


#endif // !ECS_H
