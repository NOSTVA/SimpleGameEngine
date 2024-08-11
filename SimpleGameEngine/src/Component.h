#pragma once
#include <vector>
#include <memory>

namespace engine {
	class GameObject;
}

namespace engine {
	typedef int* TypeID;

	class ComponentBase {
	public:
		virtual TypeID getType() const = 0;
		ComponentBase(GameObject* gameObject = nullptr) : gameObject(gameObject) {};
		virtual void Start() = 0;
		virtual void Update(float deltaTime) = 0;

	public:
		GameObject* gameObject;
		void SetGameObject(GameObject* gameObject);
	};

	template <class T>
	class Component : public ComponentBase {
	public:
		static TypeID type;
		TypeID getType() const { return T::type; }
	};

	template <class T>
	TypeID Component<T>::type((TypeID)&T::type);
}