#pragma once

#include "ObjectPool.h"

template<typename CpntType, size_t size>
class ComponentService
{
public:
	using ComponentType = CpntType;

	ComponentService() = default;
	~ComponentService() = default;

	CpntType* CreateComponent();
	void RecycleComponent(CpntType* cpnt);

private:
	ObjectPool<CpntType, size>	m_componentPool;

};

#define DECLARE_COMPONENT_SERVICE(ServiceType, ComponentType, ComponentPoolSize) \
class ServiceType : ComponentService<ComponentType, ComponentPoolSize> \
{ \
\
}



template<typename CpntType, size_t size>
CpntType* ComponentService<CpntType, size>::CreateComponent()
{
	auto NewPair = m_componentPool.GetNew();
	CpntType* ptr = &NewPair.first;
	ptr->SetIndex(NewPair.second);

	return ptr;
}

template<typename CpntType, size_t size>
void ComponentService<CpntType, size>::RecycleComponent(CpntType* cpnt)
{
	m_componentPool.Recycle(*cpnt, cpnt->GetIndex());
}