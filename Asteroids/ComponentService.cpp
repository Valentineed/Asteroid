#include "pch.h"
#include "ComponentService.h"

//template<typename CpntType, size_t size>
//CpntType* ComponentService<CpntType, size>::CreateComponent()
//{
//	auto NewPair = m_componentPool.GetNew();
//	CpntType* ptr = &NewPair.first;
//	ptr->SetIndex(NewPair.second);
//
//	return ptr;
//}
//
//template<typename CpntType, size_t size>
//void ComponentService<CpntType, size>::RecycleComponent(CpntType* cpnt)
//{
//	m_componentPool.Recycle(*cpnt, cpnt->GetIndex());
//}