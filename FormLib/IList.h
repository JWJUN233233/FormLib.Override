#pragma once
#include "ICollection.h"
namespace System {
	namespace Collection {
		template <typename T> class IList : public ICollection<T>
		{
			virtual void Add(T value) = 0;
			virtual T Get(int index) = 0;
			virtual T& GetPtr(int index) = 0;
			virtual void Set(int index, T value) = 0;
			virtual int Size() = 0;
			virtual void Remove(T value) = 0;
			virtual void Clear() = 0;
			virtual T& operator[](int index) {
				return GetPtr(index);
			}
			virtual void CopyTo(IList<T>& list) {
				CopyTo((ICollection<T>&)list);
			}
			virtual void CopyTo(ICollection<T>& collection) {
				collection.Clear();
				for (int i = 0; i < Size(); i++) {
					collection.Add(Get(i));
				}
			}
			virtual bool operator==(IList<T>& list) {
				bool result = true;
				if (list.Size() == Size()) {
					for (int i = 0; i < Size(); i++) {
						result = result && list.Get(i) == Get(i);
					}
				}
				return result;
			}
		};
	}
}

